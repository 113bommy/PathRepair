#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int power(long long int n, long long int y) {
  long long int res = 1;
  n = n % mod;
  if (n == 0) {
    return 0;
  }
  while (y > 0) {
    if (y & 1) res = (res * n) % mod;
    y = y >> 1;
    n = (n * n) % mod;
  }
  return res;
}
void solve() {
  long long int n, k, d;
  cin >> n >> k >> d;
  vector<vector<vector<long long int>>> v(n + 1);
  vector<int> dis(n + 1, 1e9);
  vector<int> vis(n + 1, 0);
  vector<int> colour(n, -1);
  queue<int> q;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    q.push(x);
    vis[x] = 1;
    dis[x] = 0;
  }
  for (int i = 0; i <= n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back({b, i});
    v[b].push_back({a, i});
  }
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    for (auto it : v[temp]) {
      int r = it[0], idx = it[1];
      if (!vis[r]) {
        vis[r] = 1;
        colour[idx] = 1;
        q.push(r);
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i < n - 1; i++) {
    if (colour[i] == -1) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it << " ";
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
