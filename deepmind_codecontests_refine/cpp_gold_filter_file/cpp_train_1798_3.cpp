#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x *= f, void();
}
template <typename T>
void ckmax(T &a, T b) {
  a = b > a ? b : a;
}
template <typename T>
void ckmin(T &a, T b) {
  a = b < a ? b : a;
}
const long long N = 2e5 + 5, INF = 1e13;
long long n, t[N], h[N], fa[N], f[N][2];
vector<long long> g[N];
void dfs(long long u) {
  vector<long long> vec;
  long long sum = 0;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dfs(v);
    sum += f[v][0];
    vec.push_back(f[v][1] - f[v][0]);
  }
  sort(vec.begin(), vec.end());
  for (long long p = 0; p < 2; p++) {
    f[u][p] = INF;
    if (u != 1 && ((!p && h[fa[u]] > h[u]) || (p && h[fa[u]] < h[u]))) continue;
    long long out = vec.size() + p;
    long long cursum = sum;
    for (long long i = 0; out >= 0; out--) {
      ckmin(f[u][p], cursum + (max(out, (long long)g[u].size() - out)) * t[u]);
      if (i == (long long)vec.size()) break;
      cursum += vec[i++];
    }
  }
}
signed main() {
  read(n);
  for (long long i = 1; i <= n; i++) read(t[i]);
  for (long long i = 1; i <= n; i++) read(h[i]);
  for (long long i = 1, u, v; i < n; i++) {
    read(u), read(v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  printf("%lld\n", f[1][0]);
  return 0;
}
