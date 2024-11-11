#include <bits/stdc++.h>
int visited[100001];
int m, n;
int count = 0;
long long int shortestpath[100001];
struct greedynode {
  int number;
  long long int cost;
  int node;
} * heap[400001], *l, *tmp1, *tmp2;
void insert(struct greedynode *a, long long int c, int no);
struct greedynode *del();
int min(int a, int b) {
  if (a > b) return (b);
  return (a);
}
void insert(struct greedynode *a, long long int c, int no) {
  heap[++count] = a;
  a->cost = c;
  a->node = no;
  int j;
  j = count;
  while (j >= 2) {
    if (heap[j / 2]->cost > c) {
      heap[j] = heap[j / 2];
      j = j / 2;
      continue;
    } else
      break;
  }
  heap[j] = a;
}
struct greedynode *del() {
  struct greedynode *new1;
  tmp1 = heap[1];
  heap[1] = heap[count--];
  new1 = heap[1];
  int j = 1;
  while (2 * j + 1 <= count) {
    if ((new1->cost < heap[2 * j]->cost) &&
        (new1->cost < heap[2 * j + 1]->cost)) {
      heap[j] = new1;
      return (tmp1);
    } else if ((heap[2 * j]->cost) <= (heap[2 * j + 1]->cost)) {
      heap[j] = heap[2 * j];
      j = j * 2;
      continue;
    } else if ((heap[2 * j]->cost) > (heap[2 * j + 1]->cost)) {
      heap[j] = heap[2 * j + 1];
      j = j * 2 + 1;
      continue;
    }
  }
  if (2 * j == count) {
    if (new1->cost > heap[2 * j]->cost) {
      heap[j] = heap[2 * j];
      heap[2 * j] = new1;
      return (tmp1);
    } else {
      heap[j] = new1;
      return (tmp1);
    }
  }
  heap[j] = new1;
  return (tmp1);
}
struct edge {
  int node, edgenumber;
  struct edge *next;
  long long int cost;
} * a[100001], *b[100001], *tmp;
int main() {
  int k;
  scanf("%d %d %d", &n, &m, &k);
  int j;
  for (j = 0; j <= n; j++) {
    a[j] = NULL;
    b[j] = NULL;
    visited[j] = 0;
    shortestpath[j] = 100000000000000000;
  }
  visited[1] = 1;
  shortestpath[1] = 0;
  for (j = 0; j < m; j++) {
    int r, t;
    long long int cost;
    scanf("%d %d %lld", &r, &t, &cost);
    tmp = (struct edge *)(malloc(sizeof(struct edge)));
    tmp->next = NULL;
    tmp->node = t;
    tmp->cost = cost;
    if (a[r] == NULL) {
      a[r] = tmp;
      b[r] = tmp;
    } else {
      b[r]->next = tmp;
      b[r] = tmp;
    }
    tmp->edgenumber = j + 1;
    tmp = (struct edge *)(malloc(sizeof(struct edge)));
    tmp->next = NULL;
    tmp->node = r;
    tmp->cost = cost;
    if (a[t] == NULL) {
      a[t] = tmp;
      b[t] = tmp;
    } else {
      b[t]->next = tmp;
      b[t] = tmp;
    }
    tmp->edgenumber = j + 1;
  }
  tmp = a[1];
  int x = min(k, n - 1);
  printf("%d\n", x);
  while (tmp != NULL) {
    if (((tmp->cost) < shortestpath[tmp->node])) {
      tmp2 = (struct greedynode *)(malloc(sizeof(struct greedynode)));
      tmp2->number = tmp->edgenumber;
      insert(tmp2, tmp->cost, tmp->node);
      shortestpath[tmp->node] = tmp->cost;
    }
    tmp = tmp->next;
  }
  while (count != 0) {
    l = del();
    if (visited[l->node] == 1) continue;
    if (x > 0) {
      printf("%d ", l->number);
      x--;
    } else
      break;
    tmp = a[l->node];
    visited[l->node] = 1;
    while (tmp != NULL) {
      if ((visited[tmp->node] == 0) &&
          ((shortestpath[l->node] + (tmp->cost)) < shortestpath[tmp->node])) {
        tmp2 = (struct greedynode *)(malloc(sizeof(struct greedynode)));
        shortestpath[tmp->node] = shortestpath[l->node] + (tmp->cost);
        tmp2->number = tmp->edgenumber;
        insert(tmp2, shortestpath[tmp->node], tmp->node);
      }
      tmp = tmp->next;
    }
  }
  {}
  printf("\n");
}
