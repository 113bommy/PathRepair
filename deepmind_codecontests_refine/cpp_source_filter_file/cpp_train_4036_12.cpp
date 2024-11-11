#include <bits/stdc++.h>
using namespace std;
void PLAY() {
  cout << fixed << setprecision(10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long vis[1000000];
vector<vector<long long>> x;
vector<long long> ans;
void dfs(long long node) {
  vis[node] = 1;
  long long deg = 0;
  for (int i = 0; i < x[node].size(); i++) {
    long long k = x[node][i];
    if (vis[k] == 0) {
      deg++;
      dfs(k);
    }
  }
  if (deg == 0) {
    ans.push_back(node);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  memset(vis, 0, sizeof(vis));
  x.resize(n);
  for (int i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    x[u].push_back(v);
    x[v].push_back(u);
  }
  long long root = 0;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    if (x[i].size() > 2) {
      cnt++;
      root = i;
    }
  }
  if (cnt > 1) {
    cout << "NO" << endl;
    return 0;
  }
  dfs(root);
  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << root + 1 << " " << ans[i] + 1 << endl;
  }
  return 0;
}
