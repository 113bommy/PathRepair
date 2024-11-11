#include <bits/stdc++.h>
const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const long long MXLL = 9223372036854775807;
const int Sz = 1110111;
using namespace std;
inline void Read_rap() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long d, k, a, b, t;
long long check(long long x) {
  long long res = 0;
  res += max(x - 1, 0ll) * t;
  res += a * k * x;
  res += b * max(0ll, (d - (k * x)));
  return res;
}
int main() {
  Read_rap();
  cin >> d >> k >> a >> b >> t;
  long long l = 0, r = d / k + (d % k > 0);
  while (r - l > 2) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    if (check(m1) < check(m2))
      r = m2;
    else
      l = m1;
  }
  long long ans = MXLL;
  for (long long i = l; i <= r; i++) {
    ans = min(ans, check(i));
  }
  cout << ans;
  return 0;
}
