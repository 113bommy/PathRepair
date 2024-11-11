#include <bits/stdc++.h>
using namespace std;
int l, r, n, m, A, B, v[2005], d[2005], e[2005], d1[2005], d2[2005];
long long w1[2005], w2[2005], f[2005][2005], g[2005][2005], F[2005][2005],
    G[2005][2005];
vector<int> a[2005], b[2005];
bool cmp1(int a, int b) { return w1[a] > w1[b]; }
bool cmp2(int a, int b) { return w2[a] > w2[b]; }
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &A, &B);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    a[x].push_back(y);
    a[y].push_back(x);
    b[x].push_back(z);
    b[y].push_back(z);
  }
  for (int i = 1; i <= n; ++i) w1[i] = 1e15;
  l = 1;
  r = 2;
  d[1] = A;
  e[A] = 1;
  w1[A] = 0;
  while (l != r) {
    int x = d[l], y;
    for (unsigned i = 0; i < a[x].size(); ++i) {
      y = a[x][i];
      if (w1[y] > w1[x] + b[x][i]) {
        w1[y] = w1[x] + b[x][i];
        if (!e[y]) {
          e[d[r++] = y] = 1;
          if (r == 2001) r = 1;
        }
      }
    }
    e[x] = 0;
    if (++l == 2001) l = 1;
  }
  for (int i = 1; i <= n; ++i) d1[i] = i;
  sort(d1 + 1, d1 + n + 1, cmp1);
  for (int i = 1; i <= n; ++i) w2[i] = 1e15;
  l = 1;
  r = 2;
  d[1] = B;
  e[B] = 1;
  w2[B] = 0;
  while (l != r) {
    int x = d[l], y;
    for (unsigned i = 0; i < a[x].size(); ++i) {
      y = a[x][i];
      if (w2[y] > w2[x] + b[x][i]) {
        w2[y] = w2[x] + b[x][i];
        if (!e[y]) {
          e[d[r++] = y] = 1;
          if (r == 2001) r = 1;
        }
      }
    }
    e[x] = 0;
    if (++l == 2001) l = 1;
  }
  for (int i = 1; i <= n; ++i) d2[i] = i;
  sort(d2 + 1, d2 + n + 1, cmp1);
  w1[0] = w2[0] = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (w2[d1[i]] > w2[d2[j + 1]])
        f[i][j] = max(f[i - 1][j], G[i - 1][j]) + v[d1[i]];
      else
        f[i][j] = f[i - 1][j];
      if (w1[d2[j]] > w1[d1[i + 1]])
        g[i][j] = min(g[i][j - 1], F[i][j - 1]) - v[d2[j]];
      else
        g[i][j] = g[i][j - 1];
      F[i][j] = w1[d2[j]] > w1[d1[i + 1]] ? f[i][j] : min(F[i][j - 1], f[i][j]);
      G[i][j] = w2[d1[i]] > w2[d2[j + 1]] ? g[i][j] : max(G[i - 1][j], g[i][j]);
    }
  if (f[n][n] > 0) puts("Break a heart");
  if (f[n][n] < 0) puts("Cry");
  if (f[n][n] == 0) puts("Flowers");
  return 0;
}
