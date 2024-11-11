#include <bits/stdc++.h>
using namespace std;
const int N = 520;
int k, t, all, ans;
long long a[N][N], a2[N][N];
vector<pair<int, int> > b;
int main() {
  ios::sync_with_stdio(0);
  cin >> k;
  all = 1 << k;
  for (int i = 0, _e = all - 1; i <= _e; ++i)
    for (int j = 0, _e = all - 1; j <= _e; ++j) cin >> a[i][j];
  cin >> t;
  b.resize(t);
  for (int i = 0, _e = t - 1; i <= _e; ++i) cin >> b[i].first >> b[i].second;
  for (int i = t - 1, _e = 0; i >= _e; --i)
    b[i].first = (b[i].first - b[0].first + all) & (all - 1),
    b[i].second = (b[i].second - b[0].second + all) & (all - 1);
  for (int o = 1, _e = k; o <= _e; ++o) {
    for (int i = 0, _e = all - 1; i <= _e; ++i)
      for (int j = 0, _e = all - 1; j <= _e; ++j) {
        a2[i][j] = 0;
        for (pair<int, int> l : b)
          a2[i][j] ^= a[(i - l.first + all) & (all - 1)]
                       [(j - l.second + all) & (all - 1)];
      }
    memcpy(a, a2, sizeof a);
    for (pair<int, int> &l : b)
      l.first = l.first * 2 & (all - 1), l.second = l.second * 2 & (all - 1);
  }
  for (int i = 0, _e = all - 1; i <= _e; ++i)
    for (int j = 0, _e = all - 1; j <= _e; ++j) ans += a[i][j] > 0;
  cout << ans;
}
