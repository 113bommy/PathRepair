#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  bool dp[500005];
  for (int i = 0; i < 500005; i++) dp[i] = false;
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 500005; j >= 0; j--) {
      if (dp[j] && j + x < 500005) {
        dp[j + x] = true;
      }
    }
  }
  priority_queue<pair<int, int>> pq;
  pq.push({0, 0});
  int resV = -1;
  int resD = -1;
  for (int i = 0; i < 500005; i++) {
    while (!pq.empty() && -pq.top().second + d < i) {
      pq.pop();
    }
    if (pq.empty()) break;
    if (dp[i]) {
      int to = -pq.top().first + 1;
      pq.push({-to, -i});
      resV = i;
      resD = to;
    }
  }
  cout << resV << ' ' << resD << '\n';
}
