#include <bits/stdc++.h>
using namespace std;
long long INF = 1e7;
int mod = 1000000007;
bool check(long long x, long long y, long long p, long long q, long long m) {
  return x <= (p * m) && (y - x) <= (q * m - p * m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long x, y, p, q;
    cin >> x >> y >> p >> q;
    long long l = -1;
    long long r = (long long)1e9;
    if (!check(x, y, p, q, r)) {
      cout << -1;
    } else {
      long long sol = r;
      while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(x, y, p, q, mid)) {
          r = mid;
        } else
          l = mid;
      }
      cout << r * q - y << "\n";
    }
  }
  return 0;
}
