#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
struct compare {
  bool operator()(const pair<long long, long long> a,
                  const pair<long long, long long> b) const {
    return a.first < b.first;
  }
};
void __solve__(long long testCase) {
  long long x, y, ans = 1e18;
  cin >> y >> x;
  vector<long long> c(6);
  for (long long &e : c) cin >> e;
  for (long long i = 0; i < 3; i++)
    for (long long j = 0; j < 3; j++) {
      long long s = 0;
      if (i == j) {
        if (i == 0 && y == 0)
          if (x > 0)
            s += c[1] * x;
          else
            s += c[4] * -x;
        if (i == 1 && x == 0)
          if (y > 0)
            s += c[5] * y;
          else
            s += c[2] * -y;
        if (i == 2 && x == y)
          if (x > 0)
            s += c[0] * x;
          else
            s += c[3] * -x;
        if (s) ans = min(ans, s);
        continue;
      } else if (i != 2 && j != 2) {
        if (x > 0)
          s += c[1] * x;
        else
          s += c[4] * -x;
        if (y > 0)
          s += c[5] * y;
        else
          s += c[2] * -y;
      } else {
        if (j == 0 || i == 0) {
          if (y > 0)
            s += c[0] * y;
          else
            s += c[3] * -y;
          if (x - y > 0)
            s += c[1] * (x - y);
          else
            s += c[4] * -(x - y);
        } else {
          if (x > 0)
            s += c[0] * x;
          else
            s += c[3] * -x;
          if (y - x > 0)
            s += c[5] * (y - x);
          else
            s += c[2] * -(y - x);
        }
      }
      ans = min(ans, s);
    }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testCase = 1;
  cin >> testCase;
  for (long long tc = 1; tc <= testCase; tc++) {
    __solve__(tc);
  }
}
