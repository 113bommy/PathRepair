#include <bits/stdc++.h>
using namespace std;
const int M = 1505;
pair<long long, long long> a[M];
int mark[M], dp[M], n;
vector<int> adj[M];
void dfs(int v) {
  mark[v] = 1;
  for (int u : adj[v])
    if (!mark[u]) dfs(u), dp[v] += dp[u];
  dp[v]++;
}
bool cmp_up(int u, int v) { return a[u].second < a[v].second; }
int comper;
bool cmp_shib(int u, int v) {
  long long s1 = a[u].first - a[comper].first;
  long long s2 = a[u].second - a[comper].second;
  long long t1 = a[v].first - a[comper].first;
  long long t2 = a[v].second - a[comper].second;
  return s2 * t1 < s1 * t2;
}
int mat[M];
void solve(vector<int> vec, int v) {
  auto it = max_element(vec.begin(), vec.end(), cmp_up);
  int root = *it;
  vec.erase(it);
  comper = root;
  sort(vec.begin(), vec.end(), cmp_shib);
  vector<int> go;
  for (int u : adj[v])
    if (dp[u] < dp[v]) {
      go.clear();
      int siz = dp[u];
      while (siz--) go.push_back(vec.back()), vec.pop_back();
      solve(go, u);
    }
  mat[v] = root;
}
int32_t main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  vector<int> vec;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second, vec.push_back(i);
  dfs(1), solve(vec, 1);
  for (int i = 1; i <= n; i++) cout << mat[i] << ' ';
  return cout << endl, 0;
}
