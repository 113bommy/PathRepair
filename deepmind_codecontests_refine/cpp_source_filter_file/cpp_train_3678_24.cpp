#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int inf = 1e9;
const int NMAX = 1e5 + 5;
int n, m, p, cnt, s[NMAX];
vector<int> g[NMAX];
bool Visited[NMAX];
long long Power(int a, int b) {
  if (!b) return 1;
  if (b == 1) return a;
  long long tmp = Power(a, b / 2);
  if (b & 1)
    return ((tmp * tmp) % p * a) % p;
  else
    return (tmp * tmp) % p;
}
void dfs(int u) {
  Visited[u] = true;
  if (!g[u].size()) return;
  ++cnt;
  for (int &v : g[u]) {
    if (!Visited[v]) {
      dfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int k = 0;
  long long res = 1;
  memset(Visited, false, sizeof(Visited));
  for (int i = 1; i <= n; ++i) {
    if (!Visited[i]) {
      cnt = 0;
      dfs(i);
      s[++k] = cnt;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (s[i]) res = res * s[i] % p;
  }
  if (k == 1) return cout << 1, 0;
  res = res * Power(n, k - 2) % p;
  cout << res;
  return 0;
}
