#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
long long n, m;
vector<long long> g[200010];
vector<long long> g_[200010];
long long used[200010];
long long mini[200010];
vector<long long> t_sort;
long long pos[200010];
string ans;
void dfs(long long u) {
  if (used[u] == 1) {
    cout << -1;
    exit(0);
  }
  if (used[u] == 2) return;
  used[u] = 1;
  for (auto v : g[u]) {
    dfs(v);
  }
  used[u] = 2;
  pos[u] = n - t_sort.size() - 1;
  t_sort.push_back(u);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  ans.resize(n + 1, 'A');
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g_[v].push_back(u);
  }
  for (long long i = 1; i <= n; ++i) {
    if (!used[i]) dfs(i);
  }
  reverse(t_sort.begin(), t_sort.end());
  mini[n + 1] = 1e9;
  for (long long i = n - 1; i >= 0; --i) {
    long long u = t_sort[i];
    mini[i] = u;
    for (auto v : g[u]) {
      mini[i] = min(mini[i], mini[pos[v]]);
    }
    if (mini[i] != u) {
      ans[u] = 'E';
    }
  }
  for (long long i = 0; i < n; ++i) {
    long long u = t_sort[i];
    mini[i] = u;
    for (auto v : g_[u]) {
      mini[i] = min(mini[u], mini[pos[v]]);
    }
    if (mini[i] != u) {
      ans[u] = 'E';
    }
  }
  long long cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    cnt += ans[i] == 'A';
  }
  cout << cnt << '\n';
  for (long long i = 1; i <= n; ++i) {
    cout << ans[i];
  }
  return 0;
}
