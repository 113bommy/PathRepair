#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
static int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
unordered_map<int, bool> M;
const int N = 400005;
const int MOD = 1000000007;
signed main() {
  int T;
  cin >> T;
  int _1 = 0, _2 = 0, _3 = 0, _4 = 0;
  for (int i = 1; i <= T; ++i) {
    int a;
    cin >> a;
    if (a == 4)
      _4++;
    else if (a == 3)
      _3++;
    else if (a == 2)
      _2++;
    else
      _1++;
  }
  _4 += _2 >> 1, _2 = _2 & 1;
  if (_3 > _1) {
    _4 += _3;
    _4 += _2;
  } else {
    _4 += _3, _1 -= _3;
    _4 += _1 >> 2, _1 %= 4;
    if (_1 + _2 * 2 <= 4) {
      if (_1 || _2) _4++;
    } else
      _4 += 2;
  }
  cout << _4;
  return 0;
}
