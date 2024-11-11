#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, m, q;
int a[N];
struct node {
  int op, l, r;
} A[N];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &A[i].op, &A[i].l, &A[i].r);
  }
  int t, j;
  while (q--) {
    j = m;
    scanf("%d", &t);
    while (j) {
      if (A[j].l <= t && A[j].r >= t) {
        if (A[j].op == 1) {
          t--;
          if (t == A[j].l - 1) t = A[j].r;
        } else {
          int len = A[j].r - A[j].l + 1;
          t = A[j].r + A[j].l - t;
        }
      }
      j--;
    }
    printf("%d ", a[t]);
  }
  return 0;
}
