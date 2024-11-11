#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n, tot, rt, du[N], vis[N], F[N], zhan[N];
vector<long long> g[N], xu;
inline long long read() {
  long long ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
void dfs(long long u, long long fa) {
  F[u] = fa;
  for (long long i = 0; i < g[u].size(); i++) {
    long long v = g[u][i];
    if (v == fa) continue;
    dfs(v, u);
  }
  if (du[u] % 2 == 0) {
    du[fa]--;
    xu.push_back(u);
  }
  if (u == 1 && du[u] & 1) {
    puts("NO");
    exit(0);
  }
}
void solve(long long u, long long fa) {
  zhan[++tot] = u;
  vis[u] = 1;
  for (long long i = 0; i < g[u].size(); i++) {
    long long v = g[u][i];
    if (v == fa || vis[v]) continue;
    solve(v, u);
  }
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    long long x = read();
    if (x > 0) {
      g[x].push_back(i);
      g[i].push_back(x);
      du[i]++;
      du[x]++;
    } else
      rt = i;
  }
  dfs(rt, 0);
  puts("YES");
  for (long long i = 0; i < xu.size(); i++) {
    long long x = xu[i];
    solve(x, F[x]);
  }
  for (long long i = 1; i <= n; i++) printf("%lld\n", zhan[i]);
  return 0;
}
