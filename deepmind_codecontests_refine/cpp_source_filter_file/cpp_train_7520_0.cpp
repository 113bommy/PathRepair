#include <bits/stdc++.h>
using std ::vector;
template <typename Tp>
Tp Max(const Tp &a, const Tp &b) {
  return a > b ? a : b;
}
template <typename Tp>
Tp Min(const Tp &a, const Tp &b) {
  return a < b ? a : b;
}
template <typename Tp>
Tp Abs(const Tp &a) {
  return a > 0 ? a : -a;
}
template <typename Tp>
void Read(Tp &x) {
  Tp in = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    in = in * 10 + ch - '0';
    ch = getchar();
  }
  x = in * f;
}
const int SN = 200000 + 10;
vector<int> G[SN];
int a[SN], b[SN], c[SN], min[SN], n;
int res0[SN], res1[SN];
long long ans;
void pre(int u, int fa) {
  for (auto v : G[u])
    if (v != fa) min[v] = Min(min[v], min[u]);
  for (auto v : G[u])
    if (v != fa) pre(v, u);
}
void Dfs(int u, int fa) {
  if (b[u] != c[u])
    if (b[u] == 0)
      res0[u]++;
    else
      res1[u]++;
  for (auto v : G[u])
    if (v != fa) Dfs(v, u), res1[u] += res1[v], res0[u] += res0[v];
  int K = Min(res0[u], res1[u]);
  ans += 2 * K * min[u];
  res0[u] -= K, res1[u] -= K;
}
int main(int argc, const char *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++)
    Read(a[i]), Read(b[i]), Read(c[i]), min[i] = a[i];
  int u, v;
  for (int i = 1; i < n; i++) {
    Read(u), Read(v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  u = 0, v = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) u++;
    if (c[i] == 0) v++;
  }
  if (u != v) {
    printf("-1\n");
    return 0;
  }
  pre(1, 0);
  Dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
