#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int M = 1e9 + 7;
const double eps = 1e-6;
const double PI(acos(-1.0));
int n, k;
long long tot = 0;
long long f[N][5];
vector<int> g[N];
int sz[N];
void dfs(int u, int p = 0, int dep = 0) {
  f[u][dep % k]++;
  sz[u] = 1;
  for (auto v : g[u])
    if (v - p) {
      dfs(v, u, dep + 1);
      for (int a = 0; a < k; a++)
        for (int b = 0; b < k; b++) {
          int dis = (a + b - 2 * dep + k) % k;
          dis = (k - dis + k) % k;
          tot += dis * f[u][a] * f[v][b];
        }
      sz[u] += sz[v];
      for (int j = 0; j < (k); j++) f[u][j] += f[v][j];
    }
  tot += 1LL * sz[u] * (n - sz[u]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  cout << tot / k << endl;
}
