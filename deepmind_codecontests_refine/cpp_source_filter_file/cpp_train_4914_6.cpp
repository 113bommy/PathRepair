#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, c[N][N];
struct node {
  int v, pos;
} a[N];
inline bool cmp(node x, node y) { return x.v > y.v; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].v), a[i].pos = i;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i)
    for (int j = 1, k = i; j <= a[i].v; ++j, k = k % (n + 1) + 1)
      c[k][a[i].pos] = 1;
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; puts(""), ++i)
    for (int j = 1; j <= n; ++j) printf("%d ", c[i][j]);
  return 0;
}
