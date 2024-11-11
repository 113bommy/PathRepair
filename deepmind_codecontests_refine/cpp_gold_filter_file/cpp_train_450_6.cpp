#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793238462643l;
long long mod = 1000000007ll;
long long a[3000];
long long n, k;
long long f[3000], fk_1[3000];
long long mypow(long long a, long long n) {
  long long ans = 1;
  for (int i = 0; i < int(30); i++) {
    if (n & 1) {
      (ans *= a) %= mod;
    }
    (a *= a) %= mod;
    n >>= 1;
  }
  return ans;
}
long long C(long long a) { return (fk_1[a] * mypow(f[a], mod - 2)) % mod; }
int main() {
  cin >> n >> k;
  f[0] = fk_1[0] = 1;
  for (int i = 0; i < int(2995); i++) {
    f[i + 1] = (f[i] * (i + 1)) % mod;
    fk_1[i + 1] = (fk_1[i] * (k + i)) % mod;
  }
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
  }
  if (k == 0) {
    for (int i = 0; i < int(n); i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
  }
  for (int i = 0; i < int(n); i++) {
    long long ans = 0;
    for (int j = 0; j < int(n); j++) {
      if (j > i) {
        continue;
      }
      long long d = i - j;
      long long c = C(d);
      (ans += c * a[j]) %= mod;
    }
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}
