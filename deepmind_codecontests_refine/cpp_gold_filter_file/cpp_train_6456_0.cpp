#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

struct Node{
  int key;
  Node *r, *l, *p;

};

Node *root, *NIL;

Node * find(Node *u, int k){
  while(u != NIL && k != u->key){
    if(k < u->key) u = u->l;
    else u = u->r;
  }
  return u;
}

void insert(int k){
  Node *x = root,*y = NIL, *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->l = NIL;
  z->r = NIL;

  while(x != NIL){
    y = x;
    if(z->key < x->key){
      x = x->l;
    }
    else{
      x = x->r;
    }
  }

  z->p = y;
  if(y == NIL){
    root = z;
  }
  else{
    if(z->key < y->key){
      y->l = z;
    }
    else{
      y->r = z;
    }
  }
}

void inorder(Node *u){
  if(u == NIL) return;
  inorder(u->l);
  printf(" %d", u->key);
  inorder(u->r);
}

void preorder(Node *u){
  if(u == NIL) return;
  printf(" %d", u->key);
  preorder(u->l);
  preorder(u->r);
}

int main(){
  int n, i, x;
  string com;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
    cin >> com;
    if(com[0] == 'f'){
      scanf("%d", &x);
      Node *t = find(root, x);
      if(t != NIL) printf("yes\n");
      else printf("no\n");
    }
    else if(com == "insert"){
      scanf("%d", &x);
      insert(x);
    }
    else if(com == "print"){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}
