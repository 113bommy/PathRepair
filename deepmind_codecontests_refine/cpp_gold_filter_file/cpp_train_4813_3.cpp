#include <bits/stdc++.h>
using namespace std;
const long long siz = 2e5 + 2;
const long long SIZ = 8e6 + 2;
const long long mod = 1e9 + 7;
const long long maxx = 2e9;
const long long MAXX = 1e18;
const string file = "3";
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long a, b, c;
    cin >> a >> b >> c;
    pair<long long, array<long long, 3> > ans;
    ans.first = maxx;
    for (long long _b = 1; _b <= 2e4; _b++) {
      long long cnt = abs(b - _b);
      long long min_dif_a = maxx;
      long long _a = maxx;
      for (long long i = 1; i * i <= _b; i++) {
        if (_b % i == 0) {
          if (abs(a - i) < min_dif_a) {
            min_dif_a = abs(a - i);
            _a = i;
          }
          if (abs(a - (_b / i)) < min_dif_a) {
            min_dif_a = abs(a - (_b / i));
            _a = _b / i;
          }
        }
      }
      cnt += abs(a - _a);
      long long min_dif_c = maxx;
      long long _c = maxx;
      for (long long i = _b; i <= 2e4; i += _b) {
        if (abs(c - i) < min_dif_c) {
          min_dif_c = abs(c - i);
          _c = i;
        }
      }
      cnt += abs(c - _c);
      if (cnt < ans.first) {
        ans.first = cnt;
        ans.second = {_a, _b, _c};
      }
    }
    cout << ans.first << "\n";
    for (long long i = 0; i < 3; i++) {
      cout << ans.second[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
