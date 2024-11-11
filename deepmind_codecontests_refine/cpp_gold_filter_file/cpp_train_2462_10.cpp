#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
int n;
int level[100005], cnt[100005];
void bfs(int sv) {
  level[sv] = 1;
  queue<int> q;
  q.push(sv);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i : adj[t]) {
      level[i] = 1 + level[t];
      q.push(i);
    }
  }
}
int main() {
  cin >> n;
  adj.resize(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    x--;
    adj[x].push_back(i);
  }
  bfs(0);
  for (int i : level) {
    cnt[i]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] % 2) ans++;
  }
  cout << ans;
  return 0;
}
