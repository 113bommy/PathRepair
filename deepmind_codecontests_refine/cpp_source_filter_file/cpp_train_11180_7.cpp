#include <bits/stdc++.h>
using namespace std;
unsigned long long mod = 1000 * 1000 * 1000 + 7;
string to_str(int x) {
  string s;
  while (x) {
    s += (x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  int n, m;
  cin >> n >> m;
  unsigned long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  unsigned long long f[202];
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= 200; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      unsigned long long x, v;
      cin >> x >> v;
      x--;
      a[x] = v;
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      unsigned long long sum = 0;
      for (int ii = 0; ii <= r - l; ii++) {
        sum = (sum + ((f[ii] * a[l + ii]) % mod)) % mod;
      }
      cout << sum << endl;
    }
  }
  return 0;
}
