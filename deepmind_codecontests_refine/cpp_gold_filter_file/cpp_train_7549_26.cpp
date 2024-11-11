#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e9 + 70;
const long long mod = 1e9 + 7;
const int maxn = 1e5 + 1000;
vector<pair<int, int>> data;
int n;
bool can(int b) {
  vector<vector<int>> adj(n + 1);
  vector<int> indeg(n + 1);
  for (int i = (0); i < (b); i++) {
    indeg[data[i].second]++;
    adj[data[i].first].push_back(data[i].second);
  }
  vector<int> Q;
  for (int i = (1); i < (n + 1); i++) {
    if (indeg[i] == 0) Q.push_back(i);
  }
  vector<int> order;
  while (!Q.empty()) {
    int v = Q.back();
    Q.pop_back();
    order.push_back(v);
    for (int u : adj[v]) {
      indeg[u]--;
      if (indeg[u] == 0) Q.push_back(u);
    }
  }
  vector<int> dp(n + 1);
  for (int i = (0); i < (n); i++) {
    int v = order[i];
    if (dp[v] < i) return false;
    for (int u : adj[v]) {
      dp[u] = max(dp[u], dp[v] + 1);
    }
  }
  return true;
}
int main() {
  if (fopen("i.txt", "r")) freopen("i.txt", "r", stdin);
  cin >> n;
  int(m);
  scanf("%d", &m);
  for (int i = (0); i < (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    data.push_back(pair<int, int>(u, v));
  }
  int lo = 0;
  int hi = m + 1;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    if (can(mid)) {
      hi = mid;
    } else
      lo = mid;
  }
  if (hi == m + 1) {
    cout << -1 << "\n";
  } else
    cout << hi << "\n";
  return 0;
}
