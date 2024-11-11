#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
const int mod = 1e9 + 7;
struct edge {
  int to;
  edge *next;
};
struct node {
  int n, d[1005][1005], a[1005], b[1005];
  edge *ab, E[2005], *c[1005];
  void gao(int u, int v) {
    *ab = (edge){v, c[u]};
    c[u] = ab++;
  }
  void red() {
    n = read(), ab = E;
    if (n > 500) {
      for (int i = 1; i; i++) int x = 0;
    }
    for (int i = 1; i < n; i++) {
      int x = read(), y = read();
      gao(x, y), gao(y, x);
    }
  }
  void dfs(int i, int f) {
    int x = b[i] = 0;
    for (edge *e = c[i]; e; e = e->next)
      if (e->to != f) {
        dfs(d[i][x++] = e->to, i);
        b[i] |= 1 << e->to - 1;
      }
    a[i] = x;
  }
} a, b;
int ans, ans2, f[1005][1 << 12];
int dfs(int i, int j, int x) {
  if (!j) return !x;
  int &res = f[a.d[i][j - 1]][x];
  if (res) return res - 1;
  res = dfs(i, j - 1, x);
  for (int c = a.d[i][j - 1], k = 0; k < b.n; k++)
    if (x >> k & 1)
      res = (res +
             1ll * dfs(i, j - 1, x - (1 << k)) * dfs(c, a.a[c], b.b[k + 1])) %
            mod;
  return res++;
}
long long gao(int a, int p) {
  if (a == 1) return 1;
  return (1 + p * (a - gao(p % a, a))) / a % p;
}
int main() {
  a.red(), b.red();
  a.dfs(1, 0);
  for (int r = 1; r <= b.n; r++) {
    b.dfs(r, 0);
    for (int i = 1; i <= a.n; i++) ans = (ans + dfs(i, a.a[i], b.b[r])) % mod;
    memset(f, 0, sizeof(f));
  }
  a = b, a.dfs(1, 0);
  for (int r = 1; r <= b.n; r++) {
    b.dfs(r, 0);
    ans2 = (ans2 + dfs(1, b.a[1], b.b[r])) % mod;
    memset(f, 0, sizeof(f[0]) * 13);
  }
  ans = ans * gao(ans2, mod) % mod;
  printf("%d", ans);
  return 0;
}
