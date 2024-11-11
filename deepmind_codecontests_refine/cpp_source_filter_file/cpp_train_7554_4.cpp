#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = ' ';
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  a = x * f;
}
const int mod = 1e9 + 7;
unordered_map<int, vector<int> > hsh;
unordered_map<int, int> g[1010];
long long ans, f[2][1 << 12], ansn;
int len(int p) { return 32 - __builtin_clz(p); }
int merge(int a, int b) { return a << len(b) | b; }
struct tree {
  vector<int> e[1010];
  int n, p[1010];
  void init() {
    read(n);
    ansn = 2 * n;
    for (int i = 1; i < n; i++) {
      int x, y;
      read(x);
      read(y);
      e[x].push_back(y);
      e[y].push_back(x);
    }
  }
  int dfs(int x, int dad) {
    p[x] = 1;
    vector<int> now;
    for (int v : e[x])
      if (v != dad) now.push_back(dfs(v, x));
    sort(now.begin(), now.end());
    for (int k : now) p[x] = merge(p[x], k);
    p[x] <<= 1;
    if (!hsh.count(p[x])) hsh[p[x]] = now;
    return p[x];
  }
  void dp(int x, int dad) {
    for (int v : e[x])
      if (v != dad) dp(v, x);
    for (auto &pr : hsh) {
      auto &V = pr.second;
      int P = pr.first, m = V.size();
      for (int i = 0; i < 1 << m; i++) f[0][i] = f[1][i] = 0;
      f[1][0] = 1;
      int now = 1, lst = 0;
      for (int v : e[x])
        if (v != dad) {
          now ^= 1;
          lst ^= 1;
          for (int i = 0; i < 1 << m; i++) f[now][i] = f[lst][i];
          for (int k = 0; k < m; k++)
            if (g[v][V[k]]) {
              int cef = g[v][V[k]];
              for (int i = 0; i < 1 << m; i++) {
                int flag = i && V[i] == V[i - 1] && !(i >> k - 1 & 1);
                if (!(i >> k) & 1 && f[lst][i] && !flag)
                  f[now][i | 1 << k] =
                      (f[now][i | 1 << k] + 1ll * f[lst][i] * cef) % mod;
              }
            }
        }
      if (f[now][(1 << m) - 1]) {
        g[x][P] = (g[x][P] + f[now][(1 << m) - 1]) % mod;
        if (len(P) == ansn) ans = (ans + f[now][(1 << m) - 1]) % mod;
      }
    }
  }
} S, T;
int main() {
  S.init();
  T.init();
  for (int i = 1; i <= T.n; i++) T.dfs(i, 0);
  S.dp(1, 0);
  cout << ans << '\n';
  return 0;
}
