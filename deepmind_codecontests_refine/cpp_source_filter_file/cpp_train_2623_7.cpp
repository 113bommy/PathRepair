#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
int n;
vector<int> neigh[MX];
int x[MX], y[MX];
int sz[MX];
long long res;
void dfs(int v, int p) {
  res += x[v] * 1LL * y[v] * n;
  sz[v] = 1;
  for (int u : neigh[v]) {
    if (u == p) continue;
    dfs(u, v);
    x[v] += x[u];
    sz[v] += sz[u];
  }
}
void calc(int v, int p) {
  long long tmp = (x[1] - x[v]) * 1LL * sz[v];
  for (int u : neigh[v]) {
    if (u == p) continue;
    res += x[u] * 1LL * (n - sz[u]);
  }
  tmp *= y[v];
  res += tmp;
  for (int u : neigh[v]) {
    if (u == p) continue;
    calc(u, v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    neigh[u].push_back(v);
    neigh[v].push_back(u);
  }
  for (int v = 1; v <= n; v++) {
    cin >> x[v] >> y[v];
  }
  dfs(1, 0);
  calc(1, 0);
  double ans = res;
  {
    int sy = 0;
    for (int v = 1; v <= n; v++) {
      sy += y[v];
    }
    ans /= 1.0 * x[1] * sy;
  }
  ans = n - ans;
  cout << setprecision(15) << fixed << ans << "\n";
}
