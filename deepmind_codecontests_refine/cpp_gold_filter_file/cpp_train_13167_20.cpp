#include <bits/stdc++.h>
struct heap_t {
  long long w;
  int data, edge_index;
} heap[300000 + 10];
int heap_len;
int N, M;
void heap_print() {
  int i;
  printf("Heap:");
  for (i = 0; i < heap_len; i++)
    printf(" %d(%d)", heap[i].data + 1, heap[i].edge_index);
  printf("\n");
}
void heap_swap(int i, int j) {
  struct heap_t tmp;
  tmp = heap[i];
  heap[i] = heap[j];
  heap[j] = tmp;
}
void heap_add(long long w, int data, int edge_index) {
  int i;
  if (w < 0) {
    printf("Error: negative weight heap_add(%I64d,%d,%d)\n", w, data,
           edge_index);
    exit(0);
  }
  if (heap_len >= 300000 + 10) {
    printf("Error: maximum heap length exceeded\n");
    exit(0);
  }
  heap[heap_len].w = w;
  heap[heap_len].data = data;
  heap[heap_len].edge_index = edge_index;
  i = heap_len;
  heap_len++;
  while (i && heap[i].w < heap[(i - 1) / 2].w) {
    heap_swap(i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}
void heap_get(long long *w, int *data) {
  int i, i1, i2;
  *w = heap[0].w;
  *data = heap[0].data;
  heap_len--;
  heap[0] = heap[heap_len];
  for (i = 0;;) {
    i1 = 2 * i + 1;
    i2 = 2 * i + 2;
    if (i2 < heap_len && heap[i2].w < heap[i1].w) i1 = i2;
    if (i1 < heap_len && heap[i1].w < heap[i].w) {
      heap_swap(i, i1);
      i = i1;
    } else
      break;
  }
}
struct neighlist_t {
  int neighbour;
  int len;
  int index;
  struct neighlist_t *next;
} * neighlist[300000];
char test_negative() {
  return 0;
  int i;
  struct neighlist_t *n;
  for (i = 0; i < N; i++)
    for (n = neighlist[i]; n; n = n->next)
      if (n->len < 0) {
        printf("Error: Negative edge %d(%d) between %d and %d\n", n->index,
               n->len, i + 1, n->neighbour + 1);
        return 1;
      }
  return 0;
}
void add_edge(int a, int b, int len, int index) {
  struct neighlist_t *n;
  if (test_negative()) {
    printf("before add_edge [%d] %d-%d (%d)\n", index, a + 1, b + 1, len);
    exit(0);
  }
  n = (struct neighlist_t *)malloc(sizeof(struct neighlist_t));
  n->next = neighlist[a];
  n->neighbour = b;
  n->len = len;
  n->index = index;
  if (test_negative()) {
    printf("before add_edge [%d] %d->%d (%d)\n", index, a + 1, b + 1, len);
    exit(0);
  }
  neighlist[a] = n;
  if (test_negative()) {
    printf("after add_edge [%d] %d->%d (%d)\n", index, a + 1, b + 1, len);
    exit(0);
  }
  n = (struct neighlist_t *)malloc(sizeof(struct neighlist_t));
  n->next = neighlist[b];
  n->neighbour = a;
  n->len = len;
  n->index = index;
  if (test_negative()) {
    printf("before add_edge [%d] %d<-%d (%d)\n", index, a + 1, b + 1, len);
    exit(0);
  }
  neighlist[b] = n;
  if (test_negative()) {
    printf("after add_edge [%d] %d<-%d (%d)\n", index, a + 1, b + 1, len);
    exit(0);
  }
}
long long dist[300000];
int main() {
  int i;
  int a, b, len, U, V;
  int ans[300000];
  int ans_len;
  long long ans_weight, d;
  struct neighlist_t *n, *best;
  scanf("%d %d\n", &N, &M);
  for (i = 0; i < N; i++) {
    neighlist[i] = NULL;
    dist[i] = -1;
  }
  for (i = 0; i < M; i++) {
    scanf("%d %d %d\n", &a, &b, &len);
    a--;
    b--;
    if (a < 0 || a >= N || b < 0 || b >= N || len < 0) {
      printf("Error: a = %d, b = %d, len = %d\n", a + 1, b + 1);
      return 0;
    }
    add_edge(a, b, len, i + 1);
  }
  scanf("%d\n", &U);
  U--;
  ans_len = ans_weight = 0;
  heap_len = 0;
  heap_add(0, U, 0);
  while (heap_len) {
    heap_get(&d, &V);
    if (V < 0 || V >= N) {
      printf("Error: V = %d\n", V);
      return 0;
    }
    if (d < 0) {
      printf("Error: negative distance %I64d at the vertex %d\n", d, V + 1);
      return 0;
    }
    if (dist[V] >= 0) continue;
    dist[V] = d;
    best = NULL;
    for (n = neighlist[V]; n; n = n->next) {
      if (dist[n->neighbour] < 0) {
        if (d + n->len < 0) {
          printf("Error: negative distance: %I64d+%d = %I64d\n", d, n->len,
                 d + n->len);
          return 0;
        }
        heap_add(d + n->len, n->neighbour, n->index);
      } else if (dist[n->neighbour] + n->len == d &&
                 (!best || best->len > n->len))
        best = n;
    }
    if (best) {
      ans_weight += best->len;
      ans[ans_len++] = best->index;
    }
  }
  printf("%I64d\n", ans_weight);
  for (i = 0; i < ans_len; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
