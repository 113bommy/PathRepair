#include <bits/stdc++.h>
using namespace std;
const int MAX = 100100;
struct node {
  int a, b;
} p[MAX];
int cmp(const void *x, const void *y) {
  node x1 = *(node *)x;
  node y1 = *(node *)y;
  return (x1.a > y1.a);
}
int main() {
  int n;
  while (scanf("%d", &n) != -1) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i].a);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i].b);
    }
    qsort(p, n, sizeof(p[0]), cmp);
    for (int i = 0; i < n - 1; i++) printf("%d ", p[i].b);
    printf("%d\n", p[n - 1].b);
  }
  return 0;
}
