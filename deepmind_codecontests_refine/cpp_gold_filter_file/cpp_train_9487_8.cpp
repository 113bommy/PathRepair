#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;
long long power(long long a, long long x) {
  long long ans = 1;
  while (x) {
    if (x & 1LL) ans = ans * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ans;
}
void gcdE(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcdE(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long n) {
  long long d, x, y;
  gcdE(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
int main() {
  long long x;
  cin >> x;
  vector<pair<long long, int> > a;
  for (long long i = 2; i <= 40000000; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        x /= i;
        cnt++;
      }
      a.push_back(pair<long long, int>(i, cnt));
    }
    if (x == 1) break;
  }
  if (x != 1) a.push_back(pair<long long, int>(x, 1));
  int k;
  cin >> k;
  long long ans = 1;
  long long INVK = inv(k, mod);
  vector<long long> INV(100, 0);
  for (long long i = 1; i < 100; i++) INV[i] = inv(i, mod);
  for (int i = 0; i < (int)a.size(); i++) {
    vector<long long> b(a[i].second + 1, 0);
    b.back() = 1;
    for (int j = 0; j < k; j++) {
      vector<long long> tb = b;
      for (int l = (int)b.size() - 1; l >= 0; l--) {
        b[l] *= INV[l + 1];
        b[l] %= mod;
      }
      tb = b;
      for (int l = (int)tb.size() - 2; l >= 0; l--) {
        tb[l] += tb[l + 1];
        tb[l] %= mod;
      }
      b = tb;
    }
    long long temp = 0;
    for (int j = 0; j < (int)b.size(); j++)
      temp += power(a[i].first, j) * b[j] % mod;
    temp %= mod;
    ans *= temp;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
