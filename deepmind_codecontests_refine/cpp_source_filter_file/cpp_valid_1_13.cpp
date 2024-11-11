#include <bits/stdc++.h>
using namespace std;
long double PI = 3.14159265359;
long long inf = 1000000000000000007;
long long mod = 1000000007;
long long mod1 = 998244353;
const bool multi = 0;
long long xd[4][4];
long long pokor[4][4];
long long ans = 0;
vector<pair<long long, long long>> v;
set<vector<pair<long long, long long>>> S;
void bt(long long i) {
  if (i == 3) {
    vector<pair<long long, long long>> t = v;
    sort(t.begin(), t.end());
    if (S.count(t)) return;
    S.insert(t);
    long long lol = 0;
    if (abs(v[0].first - v[1].first) == 2 ||
        abs(v[0].second - v[1].second) == 2)
      lol += 2;
    if (abs(v[1].first - v[2].first) == 2 ||
        abs(v[1].second - v[2].second) == 2)
      lol += 2;
    if (abs(v[2].first - v[3].first) == 2 ||
        abs(v[2].second - v[3].second) == 2)
      lol += 2;
    if (lol % 4 == 0) {
      long long ways = 1;
      memset(pokor, 0, sizeof pokor);
      for (auto x : v) pokor[x.first][x.second]++;
      for (long long x = 0; x <= 2; x += 2) {
        for (long long y = 0; y <= 2; y += 2) {
          long long ile = 1;
          for (long long c = 0; c < pokor[x][y]; c++) ile *= xd[x][y] - c;
          for (long long c = 1; c <= pokor[x][y]; c++) ile /= c;
          ways *= ile;
        }
      }
      ans += ways;
    }
    return;
  }
  for (long long x = 0; x <= 2; x += 2) {
    for (long long y = 0; y <= 2; y += 2) {
      v.push_back({x, y});
      bt(i + 1);
      v.pop_back();
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  if (multi)
    cin >> tt;
  else
    tt = 1;
  while (tt--) {
    long long n, x, y;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> x >> y;
      xd[x % 4][y % 4]++;
    }
    bt(0);
    cout << ans;
  }
  return 0;
}
