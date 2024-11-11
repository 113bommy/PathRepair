#include <bits/stdc++.h>
using namespace std;
long long m = 998244353;
long long ce(long long n, long long k) {
  if (n % k == 0) return (n / k);
  return (n / k + 1);
}
long long powl(long long a, long long b) {
  long long ans = 1;
  while (b != 0) {
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b = b / 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x, n, ans, m;
    cin >> x >> n;
    if (x % 2 == 0) {
      if (n % 4 == 1) {
        m = -n;
      } else if (n % 4 == 2) {
        m = 1;
      } else if (n % 4 == 3) {
        m = ce(n, 4) * 4;
      } else {
        m = 0;
      }
      ans = x + m;
    } else {
      if (n % 4 == 1) {
        m = (ce(n, 4) * 4) + 1;
      } else if (n % 4 == 2) {
        m = -1;
      } else if (n % 4 == 3) {
        m = -(ce(n, 4) * 4);
      } else {
        m = 0;
      }
      ans = x + m;
    }
    cout << ans << "\n";
  }
}
