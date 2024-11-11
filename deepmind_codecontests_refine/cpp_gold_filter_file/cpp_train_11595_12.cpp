#include <bits/stdc++.h>
unsigned long long MOD = 10000000000ull;
using namespace std;
void verify(unsigned long long &a, unsigned long long &b, unsigned long long &c,
            int d) {
  if (a % d == 0)
    a /= d;
  else if (b % d == 0)
    b /= d;
  else
    c /= d;
}
unsigned long long sum_pow2(unsigned long long n) {
  unsigned long long a = n, b = n + 1, c = 2 * n + 1;
  verify(a, b, c, 2);
  verify(a, b, c, 3);
  return (a * c % MOD) * b % MOD;
}
unsigned long long sum_pow1(unsigned long long n) {
  unsigned long long a = n, b = n + 1;
  verify(a, b, a, 2);
  a %= MOD;
  b %= MOD;
  unsigned long long base = (1ull << 25) - 1;
  unsigned long long ans = (a * (b & base)) % MOD;
  a = (a * (base + 1)) % MOD;
  ans = ans + ((b >> 25) * a % MOD);
  return ans % MOD;
}
unsigned long long ans(unsigned long long x, unsigned long long y) {
  unsigned long long mn = min(x, y);
  unsigned long long mx = max(x, y);
  unsigned long long dif = mx - mn;
  unsigned long long t1 = sum_pow2(mn - 1);
  unsigned long long t2 = sum_pow2(mx - 1);
  unsigned long long base = ((t2 + MOD - t1 + dif) % MOD) * mn % MOD;
  unsigned long long forw = sum_pow1(mn - 1) * dif % MOD;
  unsigned long long res = (sum_pow1(mn * mn) + base + forw) % MOD;
  if (mn == y) res = (res + ((mx * mn % MOD) * dif % MOD)) % MOD;
  return res;
}
int main() {
  int TEST;
  cin >> TEST;
  while (TEST--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    MOD = 10000000007ull;
    unsigned long long t1 = ans(x1 - 1, y1 - 1);
    unsigned long long t2 = ans(x1 - 1, y2);
    unsigned long long t3 = ans(x2, y1 - 1);
    unsigned long long tt = ans(x2, y2);
    unsigned long long res1 = (tt + t1 + MOD - t2 + MOD - t3) % MOD;
    MOD = 10000000000ull;
    t1 = ans(x1 - 1, y1 - 1);
    t2 = ans(x1 - 1, y2);
    t3 = ans(x2, y1 - 1);
    tt = ans(x2, y2);
    unsigned long long res2 = (tt + t1 + MOD - t2 + MOD - t3) % MOD;
    if (res2 % 10000000007ull == res1)
      cout << res2 << endl;
    else {
      int ans[10];
      for (int i = 0; i < 10; ++i) {
        ans[i] = res2 % 10;
        res2 /= 10;
      }
      string s = "";
      for (int i = 9; i >= 0; --i) s += (char)('0' + ans[i]);
      cout << "..." << s << endl;
    }
  }
  return 0;
}
