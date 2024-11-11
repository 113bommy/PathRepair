#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long modpow(long long a, long long n) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % 1000000007ll;
    b = (b * b) % 1000000007ll;
    n >>= 1;
  }
  return (long long)ret;
}
int par[18][100005], depth[100005];
vector<int> graph[100005];
void dfs(int node, int pitaji, int level = 1) {
  depth[node] = level;
  par[0][node] = pitaji;
  for (int u : graph[node]) {
    if (u != pitaji) dfs(u, node, level + 1);
  }
}
void pre(int n) {
  for (int i = 1; i < 18; i++) {
    for (int j = 1; j <= n; j++) {
      if (par[i - 1][j] != -1) par[i][j] = par[i - 1][par[i - 1][j]];
    }
  }
}
int query(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; i < (int)18; i++) {
    if ((diff >> i) & 1) u = par[i][u];
  }
  if (u == v) return u;
  for (int i = 18 - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}
int dist(int a, int b) {
  return depth[a] + depth[b] - 2 * depth[query(a, b)] + 1;
}
int cal(int a, int b, int c) { return (a + b - c + 1) / 2; }
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < (int)n - 1; i++) {
    int x;
    cin >> x;
    graph[i + 2].push_back(x);
    graph[x].push_back(i + 2);
  }
  dfs(1, -1);
  pre(n);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = dist(a, b);
    int y = dist(a, c);
    int z = dist(c, b);
    cout << max({cal(x, y, z), cal(y, z, x), cal(z, x, y)}) << endl;
  }
  return 0;
}
