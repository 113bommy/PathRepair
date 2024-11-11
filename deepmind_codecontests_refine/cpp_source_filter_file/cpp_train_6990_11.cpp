#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int main() {
  ios_base::sync_with_stdio(false);
  int m, n;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> dp[i][j];
    }
  }
  pair<int, int> tmp = {-1, -1};
  for (int i = 0; i < n; i++) {
    unordered_set<int> s;
    for (int j = 0; j < m; j++) {
      s.insert(dp[i][j]);
      if (s.size() >= 2) {
        tmp = {i, j};
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == tmp.first) continue;
    ans ^= dp[i][0];
  }
  if (tmp.first != -1 && ans == dp[tmp.first][0])
    ans = tmp.second;
  else if (tmp.first != -1)
    ans = 0;
  if (tmp.first == -1 && ans == 0)
    cout << "NLE\n";
  else {
    cout << "TAK\n";
    for (int i = 0; i < n; i++) {
      if (i == tmp.first)
        cout << ans + 1 << " ";
      else
        cout << "1 ";
    }
    cout << "\n";
  }
}
