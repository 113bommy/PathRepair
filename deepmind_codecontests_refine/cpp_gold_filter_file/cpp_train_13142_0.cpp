#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const long long maxn = 201110;
const long long M = 1e9 + 7;
long long n, m, k, ok;
long long mii(long long x) {
  long long res = 9;
  while (x) {
    res = min(res, x % 10);
    x /= 10;
  }
  return res;
}
long long mxx(long long x) {
  long long res = 0;
  while (x) {
    res = max(res, x % 10);
    x /= 10;
  }
  return res;
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    long long mi = mii(n), mx = mxx(n);
    for (long long i = 1; i < k && mi; i++) {
      n += mi * mx;
      mi = mii(n), mx = mxx(n);
    }
    cout << n << endl;
  }
  return 0;
}
