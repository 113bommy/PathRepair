#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, d;
int in[N], a[N], vis[N];
bool bfs(vector<int>& v) {
  int tot = v.size();
  queue<int> que;
  for (int i = (0); i < (tot); i++) {
    int id = v[i];
    vis[id] = -1;
    if (a[id] == 0) que.push(id), vis[id] = 0;
  }
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    int j = (x + d) % n;
    if (a[j] == 1 && vis[j] == -1) vis[j] = vis[x] + 1, que.push(j);
  }
  int res = 0;
  for (int i = (0); i < (tot); i++) res += (vis[v[i]] != -1);
  return res == tot;
}
void sol() {
  cin >> n >> d;
  bool ok = true;
  for (int i = (0); i < (n); i++) in[i] = 0, cin >> a[i];
  int ans = 0;
  for (int i = (0); i < (n); i++) {
    if (in[i]) continue;
    int st = i, j = i;
    vector<int> v;
    while (!in[j]) {
      v.push_back(j);
      in[j] = 1;
      j = (j + d) % n;
    }
    ok &= bfs(v);
    if (!ok) {
      cout << -1 << endl;
      return;
    }
    int mx = 0;
    for (auto x : v) mx = max(mx, vis[x]);
    ans = max(ans, mx);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) sol();
  return 0;
}
