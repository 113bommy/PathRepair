#include <bits/stdc++.h>
struct node {
  int data;
  struct node *next;
};
void insert(int x, struct node **head) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = *head;
  *head = temp;
}
void print(struct node **head) {
  struct node *temp = *head;
  while (temp != NULL) {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
void deleteAt(int index, struct node **head) {
  struct node *temp = *head;
  if (index == 0) {
    *head = (*head)->next;
    free(temp);
    return;
  }
  for (int i = 0; i < index - 1; i++) temp = temp->next;
  struct node *temp1 = temp->next;
  temp->next = temp1->next;
  free(temp1);
}
int main() {
  struct node *less = NULL;
  struct node *more = NULL;
  struct node *zero = NULL;
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int c = 0, c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      insert(a[i], &less);
      c++;
    } else if (a[i] > 0) {
      insert(a[i], &more);
      c1++;
    } else {
      insert(a[i], &zero);
      c2++;
    }
  }
  if (c1 == 0) {
    struct node *temp = less;
    insert(temp->data, &more);
    temp = temp->next;
    insert(temp->data, &more);
    c = c - 2;
    c1 = c1 + 2;
    deleteAt(0, &less);
    deleteAt(0, &less);
  } else if (c % 2 == 0) {
    struct node *temp = less;
    insert(temp->data, &zero);
    deleteAt(0, &less);
    c--;
    c2++;
  }
  printf("%d ", c);
  print(&less);
  printf("%d ", c1);
  print(&more);
  printf("%d ", c2);
  print(&zero);
  return 0;
}
