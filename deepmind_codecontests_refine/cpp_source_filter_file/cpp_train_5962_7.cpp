#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int inf = 1 << 30;
const int maxn = 2e5 + 5;
inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  fastio();
  int _;
  long long m, d, w;
  for (cin >> _; _; _--) {
    cin >> m >> d >> w;
    if (d == 1) {
      cout << 0 << endl;
      continue;
    }
    long long g = gcd(d - 1, w);
    long long base = w / g;
    long long mx = min(d, m);
    if (mx < base)
      cout << 0 << endl;
    else {
      long long L = 1, R = 1e9, res;
      while (L <= R) {
        long long mid = (L + R) >> 1;
        if (mid <= 1e9 / base && mid * base + 1 <= mx)
          L = mid + 1, res = mid;
        else
          R = mid - 1;
      }
      long long a = mx - base, b = mx - res * base;
      long long ans = (a + b) * res / 2;
      cout << ans << endl;
    }
  }
  return 0;
}
