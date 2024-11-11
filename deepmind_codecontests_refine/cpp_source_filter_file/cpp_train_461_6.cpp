#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(1e5 + 1e1);
long long cnt1, cnt2, x, y, ans;
bool check(long long K) {
  long long a = K / x;
  long long b = K / y;
  long long c = K / (x * y);
  K = K - a - b + c;
  long long s1 = cnt1;
  long long s2 = cnt2;
  s1 -= b;
  s2 -= a;
  if (s1 < 0) s1 = 0;
  if (s2 < 0) s2 = 0;
  return (K >= s1 + s2);
}
int main() {
  cin >> cnt1 >> cnt2 >> x >> y;
  long long L = 1, R = (long long)1e18;
  while (L <= R) {
    long long M = (L + R) / 2;
    if (check(M)) {
      ans = M;
      R = M - 1;
    } else
      L = M + 1;
  }
  cout << ans;
  return 0;
}
