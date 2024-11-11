#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, op = 0;
  while (!isdigit(ch)) op |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return op ? -x : x;
}
const int N = 2005, M = 15;
const int mod = 1e9 + 7;
int fac[N], f[N][M], flag[M], pre[M][M][M];
vector<int> e[N], E[M], s[M][M];
int n, m, x, y, rev;
int Ha[M][M];
int calc(int u, int fa, int rt) {
  int res = 1, sum = 19260817, tmp;
  for (auto v : E[u])
    if (v != fa) {
      tmp = calc(v, u, rt);
      res = 1ll * res * tmp % mod;
      sum = (sum + tmp) % mod;
    }
  res = 1ll * res * sum % mod;
  return Ha[rt][u] = res;
}
void doit(int u, int fa, int rt) {
  for (auto v : E[u])
    if (v != fa) {
      doit(v, u, rt);
      s[rt][u].push_back(v);
    }
  int sz = s[rt][u].size();
  for (int i = (0); i < (sz); i++) {
    for (int j = (0); j <= (i - 1); j++)
      if (Ha[rt][s[rt][u][i]] == Ha[rt][s[rt][u][j]]) pre[rt][u][i] |= (1 << j);
  }
}
void init() {
  for (int i = (1); i <= (m); i++) {
    calc(i, 0, i);
    for (int j = (1); j <= (i - 1); j++)
      if (Ha[i][i] == Ha[j][j]) {
        flag[i] = 1;
        break;
      }
    if (flag[i]) continue;
    doit(i, 0, i);
  }
}
inline void upd(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int g[1 << M], h[1 << M], rt, res;
void dfs(int u, int fa) {
  vector<int> c;
  for (auto v : e[u])
    if (v != fa) dfs(v, u), c.push_back(v);
  int cc = c.size();
  for (int i = (1); i <= (m); i++) {
    int sz = s[rt][i].size();
    if (sz > cc) {
      f[u][i] = 0;
      continue;
    }
    for (int st = (0); st < ((1 << sz)); st++) g[st] = 0;
    g[0] = 1;
    for (int k = (0); k < (cc); k++) {
      for (int st = (0); st < ((1 << sz)); st++) h[st] = g[st];
      for (int st = (0); st < ((1 << sz)); st++)
        if (g[st])
          for (int j = (0); j < (sz); j++)
            if (!(st >> j & 1) && f[c[k]][s[rt][i][j]] &&
                ((st & pre[rt][i][j]) == pre[rt][i][j]))
              upd(h[st | (1 << j)], 1ll * g[st] * f[c[k]][s[rt][i][j]] % mod);
      for (int st = (0); st < ((1 << sz)); st++) g[st] = h[st];
    }
    f[u][i] = g[(1 << sz) - 1];
  }
  res = (res + f[u][rt]) % mod;
}
int solve(int k) {
  rt = k, res = 0;
  dfs(1, 0);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y), e[y].push_back(x);
  }
  scanf("%d", &m);
  for (int i = (1); i <= (m - 1); i++) {
    scanf("%d%d", &x, &y);
    E[x].push_back(y), E[y].push_back(x);
  }
  init();
  int ans = 0;
  for (int i = (1); i <= (m); i++)
    if (!flag[i]) ans = (ans + solve(i));
  printf("%d\n", ans);
  return 0;
}
