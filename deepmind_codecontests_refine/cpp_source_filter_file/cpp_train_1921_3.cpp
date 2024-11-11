#include <bits/stdc++.h>
using namespace std;
void IO() {}
auto INF = INT_MAX;
vector<int> adj[100];
int d[11] = {INF};
int p[11] = {-1};
bool used[100] = {false};
vector<int> ans;
int c[100001] = {0};
int parent[100001];
void dfs(int i) {
  used[i] = true;
  for (int a : adj[i])
    if (!used[a]) dfs(a);
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int po = 0;
  for (int i = 1; i <= n; i++)
    if (!used[i]) {
      dfs(i);
      po++;
    }
  long long ans = 1 << n;
  long long di = 1 << po;
  ans = ans / di;
  cout << ans;
}
int main() {
  IO();
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
