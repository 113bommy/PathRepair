#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<vector<int>> pos;
int n, m, k;
int res = 1;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  pos.resize(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[--x].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int l = 0, len = 1, cost = 0;
    for (int j = 1; j < (int)pos[i].size(); j++) {
      cost += pos[i][j] - pos[i][j - 1] - 1;
      len++;
      while (cost > k) {
        l++;
        cost -= pos[i][l] - pos[i][l - 1];
        len--;
      }
      res = max(res, len);
    }
  }
  cout << res << '\n';
  return 0;
}
