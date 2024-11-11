#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 922337203685477;
const long long mininf = -922337203685477;
const long long nax = 0;
long long n, p, q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> p >> q;
  n *= 1000000;
  long long l = 0, r = 1e10, ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid * p + q * mid <= n) {
      ans = mid;
      l = mid + 1;
    } else if (mid * p + q * mid > n) {
      r = mid - 1;
    }
  }
  double ret = (ans * p) * 1.0;
  ret /= 1000000.0;
  cout << fixed << setprecision(15) << ret << '\n';
}
