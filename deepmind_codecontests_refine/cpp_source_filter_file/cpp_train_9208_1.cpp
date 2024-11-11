#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  char c = getchar();
  int t = 0, f = 1;
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) t = (t << 1) + (t << 3) + c - 48, c = getchar();
  return t * f;
}
inline void wt(int x) {
  if (x < 0)
    putchar('-'), wt(-x);
  else if (x < 10)
    putchar(48 + x);
  else
    wt(x / 10), putchar(48 + x % 10);
}
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> E[N];
int n, f[N], g[N];
void dfs(int x) {
  f[x] = g[x] = 1;
  long long h[2] = {1, 0}, tmp[2], sum = 1, tf, tg;
  for (int y, i = 0; i < (int)E[x].size(); i++) {
    dfs(y = E[x][i]);
    tmp[0] = h[0], tmp[1] = h[1];
    h[0] = (h[0] + tmp[1] * f[y]) % mod;
    h[1] = (h[1] + tmp[0] * f[y]) % mod;
    sum = sum * g[y] % mod, tf = f[x], tg = g[x];
    f[x] = (tf * g[y] + (tg - 1) * f[y]) % mod;
    g[x] = (tf * f[y] + (tg - 1) * g[y] + 1) % mod;
  }
  f[x] = f[x] * 2 % mod;
  g[x] = g[x] * 2 % mod;
  f[x] = (f[x] - h[1] - 1 + mod) % mod;
  g[x] = (g[x] - sum + mod) % mod;
}
int main() {
  n = rd();
  for (int y, i = 1; i < (int)n; i++) E[rd()].push_back(i + 1);
  dfs(1);
  printf("%d\n", (f[1] + g[1] - 1) % mod);
  return 0;
}
