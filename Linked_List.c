#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int info;
    struct node *link;
};
struct node *START = NULL;

struct node *createNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return n;
}

// Insertion Of Node
void insertNode()
{
    struct node *temp , *t;
    temp = createNode();
    printf("\nEnter a number");
    scanf("%d ", &temp->info);
    temp->link = NULL;
    if(START == NULL)
        START = temp;
    else{
        t = START;
        while(t->link !=NULL)
            t = t->link;
        t->link = temp ;
    }
}

// Deletion of Node from the first
void deleteNode()
{
    struct node *r;
    if(START == NULL) {
        printf("\nElement Cannot be deleted ");
    }
    else {
        r = START ;
        START = START->link;
        free(r);
    }
}

// Traversing
void viewList()
{
    struct node *t;
    if(START == NULL)
        printf("\nList is Empty Cannot view the list");
    else {
        t=START;
        while(t!=NULL){
            printf("\n%d ",t->info);
            t=t->link;
        }
    }
}

//menu 
int menu()
{
    int ch;
    printf("\n1.Add Items to the list");
    printf("\n2. Delete first list");
    printf("\n3. View list");
    printf("\n4. Exit..");

    printf("\nEnter Your Choice ");
    scanf("%d ",&ch);
    return (ch);
}

int main()
{
    while(1){
        switch(menu()){
            case 1:
                insertNode();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                viewList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }
    return(0);
}
