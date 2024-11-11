#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int MOD = 1000000007;
long long f[N], _f[N];
vector<pair<int, int> > x;
long long inv(long long a) {
  return a == 1 ? 1 : (MOD - MOD / a) * inv(MOD % a) % MOD;
}
long long mPow(long long x, int n) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}
long long C(int n, int m) { return f[n] * _f[m] % MOD * _f[n - m] % MOD; }
int main() {
  f[0] = _f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] * i % MOD;
    _f[i] = mPow(f[i], MOD - 2);
  }
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a != 0) x.push_back(make_pair(a, i + 1));
  }
  sort(x.begin(), x.end());
  if (x.size() == 0) {
    cout << mPow(2, n - 1) << endl;
    return 0;
  }
  int l, r;
  long long tmp, ans = 0;
  r = x[0].second;
  l = r - x[0].first + 1;
  if (l > 0) {
    tmp = mPow(2, x[0].first - 2);
    for (int i = 1; i < (int)x.size(); i++) {
      int moves = x[i].first - x[i - 1].first;
      if ((x[i].second >= l && x[i].second <= r) ||
          (x[i].second < l && l - moves > x[i].second) ||
          (x[i].second > r && r + moves < x[i].second)) {
        tmp = 0;
        break;
      }
      if (x[i].second < l) {
        tmp = tmp * C(moves - 1, l - x[i].second - 1) % MOD;
        l = x[i].second, r = l + x[i].first - 1;
      } else {
        tmp = tmp * C(moves - 1, x[i].second - r - 1) % MOD;
        r = x[i].second, l = r - x[i].first + 1;
      }
    }
    ans += tmp * C(n - (r - l + 1), l - 1) % MOD;
  }
  l = x[0].second;
  r = r + x[0].first - 1;
  if (x[0].first != 1 && r <= n) {
    tmp = mPow(2, x[0].first - 2);
    for (int i = 1; i < (int)x.size(); i++) {
      int moves = x[i].first - x[i - 1].first;
      if ((x[i].second >= l && x[i].second <= r) ||
          (x[i].second < l && l - moves > x[i].second) ||
          (x[i].second > r && r + moves < x[i].second)) {
        tmp = 0;
        break;
      }
      if (x[i].second < l) {
        tmp = tmp * C(moves - 1, l - x[i].second - 1) % MOD;
        l = x[i].second, r = l + x[i].first - 1;
      } else {
        tmp = tmp * C(moves - 1, x[i].second - r - 1) % MOD;
        r = x[i].second, l = r - x[i].first + 1;
      }
    }
    ans += tmp * C(n - (r - l + 1), l - 1) % MOD;
  }
  cout << ans % MOD << endl;
  return 0;
}
