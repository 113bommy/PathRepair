#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
long long n, m;
struct edge {
  long long to, nxt;
} e[1000005 << 1];
long long tot, head[1000005];
inline void adde(long long u, long long v) {
  e[++tot] = (edge){v, head[u]};
  head[u] = tot;
}
long long f[1000005][2], cut[1000005];
void dfs(long long u, long long fa) {
  f[u][0] = f[u][1] = 1;
  cut[u] = 1;
  for (long long i = head[u]; i; i = e[i].nxt) {
    long long v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    f[u][0] = (f[v][0] + f[v][1] + cut[v]) % 998244353 * f[u][0] % 998244353;
    f[u][1] = (f[v][0] + cut[v]) % 998244353 * f[u][1] % 998244353;
    cut[u] = cut[u] * f[v][0] % 998244353;
  }
  cut[u] = (f[u][0] + f[u][1] - cut[u] + 998244353) % 998244353;
}
signed main() {
  n = read();
  for (register long long i = (2); i <= (n); ++i) {
    long long u = read(), v = read();
    adde(u, v);
    adde(v, u);
  }
  dfs(1, 0);
  cout << cut[1] - 1;
  return 0;
}
