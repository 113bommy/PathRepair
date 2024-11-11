#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long inv(long long a) {
  long long b = mod, x1 = 1, y1 = 0, x2 = 0, y2 = 1;
  while (b) {
    long long t = a / b;
    a -= t * b;
    x1 -= t * x2;
    x1 %= mod;
    y1 -= t * y2;
    y1 %= mod;
    swap(a, b);
    swap(x1, x2);
    swap(y1, y2);
  }
  return x1 % mod;
}
long long p2(long long x) { return (x * x) % mod; }
long long mpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return res;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> fac(1e6 + 3, 1), invfac(1e6 + 3, 1);
  for (int i = 2; i < fac.size(); ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
    invfac[i] = inv(fac[i]);
  }
  vector<vector<long long> > s(1001, vector<long long>(1001, 0));
  s[0][0] = 1;
  for (int i = 1; i < s.size(); ++i)
    for (int j = 1; j <= i; ++j)
      s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
  if (m == 1) {
    cout << mpow(k, n) << endl;
    return 0;
  }
  long long res = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n - i; ++j) {
      if (i + j > 0 && 2 * i + j <= k) {
        long long add = (fac[k] * p2(invfac[i])) % mod;
        add = (add * invfac[j]) % mod;
        add = (add * invfac[k - 2 * i - j]) % mod;
        add = (add * mpow(2 * i + j, n * (m - 2))) % mod;
        add = (add * p2(s[n][i + j])) % mod;
        add = (add * p2(fac[i + j])) % mod;
        res += add;
      }
    }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}
