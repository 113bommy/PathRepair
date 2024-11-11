#include <bits/stdc++.h>
using namespace std;
int nnext[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
int main() {
  int n, m, k, idx, x, y, now, have, array[350][350];
  cin >> n >> m >> k, x = y = 1, idx = now = have = 0;
  vector<vector<pair<int, int> > > ans(k);
  while (k) {
    if (k == 1) {
      if (y > m)
        x++, y = m, now = 1;
      else if (!y)
        x++, y = 1, now = 0;
      ans[idx].push_back(make_pair(x, y)), have++;
      if (have == n * m) break;
      if (!now)
        y++;
      else
        y--;
      continue;
    } else {
      ans[idx].push_back(make_pair(x, y)), have++;
      if (!now)
        y++;
      else
        y--;
      if (y > m)
        x++, y = m, now = 1;
      else if (y < 0)
        x++, y = 0, now = 0;
    }
    if (ans[idx].size() == 2) idx++, k--;
  }
  for (int i = 0; i < int(ans.size()); i++) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < int(ans[i].size()); j++)
      cout << ans[i][j].first << " " << ans[i][j].second << " ";
    cout << endl;
  }
  return 0;
}
