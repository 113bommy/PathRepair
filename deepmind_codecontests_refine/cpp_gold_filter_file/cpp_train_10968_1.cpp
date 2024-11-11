#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, x, y;
int a[5010], b[5010], gg[5010], F[5010], f[5010], g[5010 * 100], ff[5010];
vector<int> zh[5010], fan[5010];
void Dfs(int x) {
  if (F[x]) return;
  int i;
  F[x] = 1;
  f[x] = x == n;
  for (i = 0; i < zh[x].size(); i++) {
    int A = zh[x][i];
    Dfs(A);
    f[x] |= f[A];
  }
}
inline void fail() {
  printf("No\n");
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    zh[x].push_back(y);
    fan[y].push_back(x);
    a[i] = y, b[i] = x;
  }
  Dfs(1);
  {
    int l, r;
    g[l = r = 1] = 1;
    for (; l <= r; l++) {
      int A = g[l];
      ff[A] = 0;
      for (i = 0; i < zh[A].size(); i++) {
        int B = zh[A][i];
        if (f[B] && gg[B] <= gg[A]) {
          gg[B] = gg[A] + 1;
          if (!ff[B]) ff[B] = 1, g[++r] = B;
        }
      }
      for (i = 0; i < fan[A].size(); i++) {
        int B = fan[A][i];
        if (f[B] && gg[B] < gg[A] - 2) {
          if (B == 1) fail();
          gg[B] = gg[A] - 2;
          if (!ff[B]) ff[B] = 1, g[++r] = B;
        }
      }
    }
  }
  for (i = 1; i <= m; i++)
    if (f[b[i]] && f[a[i]] && gg[b[i]] + 2 < gg[a[i]]) fail();
  printf("Yes\n");
  for (i = 1; i <= m; i++)
    printf("%d\n", !f[a[i]] || !f[b[i]] ? 1 : gg[a[i]] - gg[b[i]]);
  return 0;
}
