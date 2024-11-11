#include <bits/stdc++.h>
using namespace std;
int n, m, s, w[200005];
bool check[200005], check2[200005];
long long res[200005];
vector<int> g[200005];
void dfs(int u, int v) {
  check[u] = 1;
  for (auto t : g[u]) {
    if (t == v) continue;
    if (check[t]) {
      check2[u] = 1;
      continue;
    }
    dfs(t, u);
    if (check2[t]) {
      check2[u] = 1;
    } else {
      res[u] = max(res[u], res[t]);
    }
  }
  if (!check2[u]) res[u] += w[u];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> s;
  dfs(s, 0);
  long long ans = 0;
  long long mx = 0;
  int id = 0;
  for (int i = 1; i <= n; i++) {
    if (check2[i]) {
      ans += w[i];
    }
    if (res[i] > mx) {
      mx = res[i];
      id = i;
    }
  }
  if (!check2[s]) {
    cout << res[s] << endl;
    return 0;
  }
  cout << ans + mx;
  return 0;
}
