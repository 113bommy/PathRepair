#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1000000000000000000;
const long double pi = 3.14159265358979323846264338;
const long long mod = 1000000007;
long long int pow(long long int x, unsigned long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int invmod(long long int a, long long int m) {
  return pow(a, m - 2, m);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    long long int ans = 0;
    for (long long int i = 62; i >= 0; i--) {
      if ((1LL << i) & r) {
        if ((1LL << i) & l)
          ans += 1LL << i;
        else {
          if ((r & ((1LL << (i + 1)) - 1)) == ((1LL << (i + 1)) - 1)) {
            ans += (1LL << (i + 1)) - 1;
          } else {
            i--;
            while (i >= 0) {
              ans += 1LL << i;
              i--;
            }
          }
          break;
        }
      }
    }
    cout << ans << "\n";
  }
}
