#include <bits/stdc++.h>
using namespace std;
int n = 0;
struct node {
  int k;
  int v;
  int a;
} num[300010];
int cmp1(const void* x, const void* y) {
  return ((struct node*)x)->a - ((struct node*)y)->a;
}
int cmp2(const void* x, const void* y) {
  return ((struct node*)x)->k - ((struct node*)y)->k;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i].a);
    num[i].k = i;
  }
  qsort(num, n, sizeof(num[0]), cmp1);
  num[0].v = num[0].a;
  for (int i = 1; i < n; i++) {
    if (num[i].a <= num[i - 1].v) {
      num[i].v = num[i - 1].v + 1;
    } else {
      num[i].v = num[i].a;
    }
  }
  qsort(num, n, sizeof(num[0]), cmp2);
  printf("%d", num[0].v);
  for (int i = 1; i < n; i++) {
    printf(" %d", num[i].v);
  }
  printf("\n");
  return 0;
}
