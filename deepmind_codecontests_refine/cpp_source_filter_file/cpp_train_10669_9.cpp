#include <bits/stdc++.h>
using namespace std;
struct node {
  int pos, t1, t2;
} f[2005];
int n, A[2005];
bool cmp(struct node a, struct node b) { return a.t1 > b.t2; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &f[i].t1);
    f[i].pos = i;
  }
  sort(f + 1, f + n + 1, cmp);
  f[1].t2 = 1;
  A[f[1].pos] = 1;
  for (int i = 2; i <= n; i++) {
    if (f[i].t1 == f[i - 1].t1) {
      f[i].t2 = f[i - 1].t2;
      A[f[i].pos] = f[i].t2;
    } else {
      f[i].t2 = i;
      A[f[i].pos] = i;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", A[i]);
  printf("\n");
  return 0;
}
