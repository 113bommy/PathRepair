#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(NULL));
const double eps = 1e-9;
const int inf = 1e9;
const int mod = 1e9 + 7;
long long d[200050][5];
long long p2[200050][5];
vector<int> g[200050];
long long ans = 0;
int n, k;
int s[200050];
int dfs(int u, int e) {
  s[u] = 0;
  for (auto v : g[u])
    if (v != e) s[u] += dfs(v, u);
  for (auto v : g[u])
    if (v != e)
      for (int j = 0; j < k; j++) p2[u][j] += p2[v][j], d[u][j] += d[v][j];
  long long la1 = 0, la2 = 0;
  for (auto v : g[u])
    if (v != e)
      for (int j = 0; j < k; j++) {
        la2 += (s[u] - s[v]) * d[v][j];
        for (int q = 0; q < k; q++) {
          if (!q && !j) continue;
          if (q + j <= k)
            la1 += p2[v][j] * (p2[u][q] - p2[v][q]);
          else
            la1 += 2 * p2[v][j] * (p2[u][q] - p2[v][q]);
        }
      }
  la1 /= 2;
  ans += la1 + la2;
  for (auto v : g[u])
    for (int j = 0; j < k; j++) ans += d[v][j] + (j ? p2[v][j] : 0);
  for (int j = 0; j < k; j++) p2[u][j] = 0, d[u][j] = 0;
  if (k > 1)
    p2[u][1]++;
  else
    p2[u][0]++, d[u][0]++;
  for (auto v : g[u]) {
    for (int j = 0; j < k; j++)
      if (j) {
        d[u][j] += d[v][j - 1];
        p2[u][j] += p2[v][j - 1];
      }
    p2[u][0] += p2[v][k - 1];
    d[u][0] += d[v][k - 1];
    d[u][0] += p2[v][k - 1];
  }
  return ++s[u];
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << '\n';
}
