#include <bits/stdc++.h>
using namespace std;
vector<int> v[4];
long long _1[300300], sum[4][100100], total;
int main() {
  ios_base::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    total += x;
    v[x].push_back(y);
  }
  for (int i = 1; i <= 3; i++) sort(v[i].rbegin(), v[i].rend());
  memset(_1, -1, sizeof _1);
  _1[0] = 0;
  if ((int)v[1].size() > 0) _1[1] = 1;
  if ((int)v[1].size() > 1) _1[2] = 2;
  for (int j = 1; j <= 3; j++)
    for (int i = 1; i <= (int)v[j].size(); i++) {
      sum[j][i] = sum[j][i - 1] + v[j][i - 1];
    }
  for (int i = 3; i <= m; i++)
    if (_1[i - 3] != -1) {
      if (_1[i - 3] + 3 <= (int)v[1].size()) _1[i] = _1[i - 3] + 3;
      int _3 = (i - _1[i - 3]) / 3;
      if (v[3].size() >= _3 && (v[1].size() < _1[i - 3] + 3 ||
                                sum[1][_1[i - 3] + 3] - sum[1][_1[i - 3]] <
                                    sum[3][_3] - sum[3][_3 - 1]))
        _1[i] = _1[i - 3];
    }
  m = min(m, total);
  long long ans = 0;
  for (int i = 0; i <= (int)v[2].size(); i++)
    if (2 * i <= m && _1[m - 2 * i] != -1) {
      ans = max(sum[2][i] + sum[1][_1[m - 2 * i]] +
                    sum[3][(m - 2 * i - _1[m - 2 * i]) / 3],
                ans);
    }
  m--;
  for (int i = 0; i <= (int)v[2].size(); i++)
    if (2 * i <= m && _1[m - 2 * i] != -1) {
      ans = max(sum[2][i] + sum[1][_1[m - 2 * i]] +
                    sum[3][(m - 2 * i - _1[m - 2 * i]) / 3],
                ans);
    }
  m--;
  for (int i = 0; i <= (int)v[2].size(); i++)
    if (2 * i <= m && _1[m - 2 * i] != -1) {
      ans = max(sum[2][i] + sum[1][_1[m - 2 * i]] +
                    sum[3][(m - 2 * i - _1[m - 2 * i]) / 3],
                ans);
    }
  cout << ans << endl;
  return 0;
}
