#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 5e5 + _;
struct node {
  int y, next;
} a[2 * maxn];
int len, last[maxn];
void ins(int x, int y) {
  a[++len].y = y;
  a[len].next = last[x];
  last[x] = len;
}
struct point {
  int a[2][2];
  point() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
  point ts() {
    point p;
    p.a[0][0] = a[1][0];
    p.a[0][1] = a[0][0] + a[1][1];
    p.a[1][0] = a[0][0];
    p.a[1][1] = a[0][1];
    return p;
  }
  friend point operator+(point x, point y) {
    point z;
    memset(z.a, 0, sizeof(z.a));
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 1 - i; k++)
          for (int p = 0; p <= 1 - j; p++)
            z.a[i + k][j + p] += x.a[i][j] * y.a[k][p];
    return z;
  }
};
int tot[maxn];
point f[maxn];
void dfs(int x, int fr) {
  tot[x] = 1;
  f[x].a[0][0] = 1;
  for (int k = last[x]; k; k = a[k].next) {
    int y = a[k].y;
    if (y != fr) {
      dfs(y, x);
      f[x] = f[x] + f[y].ts();
      tot[x] += tot[y];
    }
  }
}
int z, L[maxn], R[maxn], u[maxn];
point g[2 * maxn], s[2 * maxn];
void changert(int x, int fr) {
  L[x] = ++z;
  for (int k = last[x]; k; k = a[k].next)
    if (a[k].y != fr) u[++z] = a[k].y;
  R[x] = z;
  if (fr)
    s[L[x]] = g[x].ts();
  else
    s[L[x]].a[0][0] = 1;
  for (int i = L[x] + 1; i <= R[x]; i++) s[i] = s[i - 1] + f[u[i]].ts();
  point now;
  now.a[0][0] = 1;
  for (int i = R[x]; i >= L[x] + 1; i--)
    g[u[i]] = s[i - 1] + now, now = now + f[u[i]].ts();
  for (int k = last[x]; k; k = a[k].next)
    if (a[k].y != fr) changert(a[k].y, x);
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    ins(x, y), ins(y, x);
  }
  dfs(1, 0);
  changert(1, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i].a[1][0] == 1 && g[i].a[1][0] == 1)
      ans += (long long)tot[i] * (n - tot[i]);
    else
      ans += (long long)(f[i].a[0][0] + f[i].a[1][1]) *
             (g[i].a[0][0] + g[i].a[1][1]);
  }
  printf("%lld\n", ans);
  return 0;
}
