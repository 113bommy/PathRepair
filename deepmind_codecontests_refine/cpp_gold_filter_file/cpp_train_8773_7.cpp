#include <bits/stdc++.h>
const long long int maxn = 2e3 + 1;
const long long mod = 998244353;
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = res * a;
    a = a * a;
    b = b / 2;
  }
  return res;
}
long long po(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = ((res % mod) * (x % mod)) % mod;
    y = y >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int flag = 1;
    long long int mi = 1e9, sum = 0;
    mi = a[0];
    for (int i = 1; i < n; i++) {
      a[i] = a[i] - sum;
      if (a[i] < 0) {
        flag = 0;
        break;
      }
      if (a[i] <= mi)
        ;
      else {
        sum += a[i] - mi;
      }
      mi = min(mi, a[i]);
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
