#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long a[65];
long long b[65];
long long inv(long long a, long long m) {
  if (a == 1) return 1;
  return inv(m % a, m) * (m - m / a) % m;
}
int main() {
  int i;
  a[0] = 1;
  b[0] = 1;
  for (i = 1; i < 60; i++) a[i] = a[i - 1] * 2;
  for (i = 1; i < 60; i++) b[i] = a[i] + b[i - 1];
  long long l, r;
  cin >> l >> r;
  l--;
  long long _ = inv(2, mod);
  int posL = int(upper_bound(b, b + 60, l) - b - 1);
  int posR = int(upper_bound(b, b + 60, r) - b - 1);
  if (posL >= 0) {
    long long sum_odd = 0, sum_even = 0;
    long long pre = 0, now = 0;
    for (i = 0; i <= posL; i++) {
      if (i % 2 == 0) {
        pre = (pre + (sum_odd * 2 % mod + 1 +
                      ((sum_odd + a[i]) % mod * 2 % mod - 1 + mod) % mod) *
                         (a[i] % mod) % mod * _ % mod) %
              mod;
        sum_odd = (sum_odd + a[i]) % mod;
      } else {
        pre = (pre + ((sum_even + 1) % mod * 2 % mod +
                      (sum_even + a[i]) % mod * 2 % mod) %
                         mod * (a[i] % mod) % mod * _ % mod) %
              mod;
        sum_even = (sum_even + a[i]) % mod;
      }
    }
    now = pre;
    long long len = (l - b[posL]) % mod;
    if (posL % 2 == 0) {
      pre = (pre + ((sum_even + 1) % mod * 2 % mod +
                    (sum_even + len) % mod * 2 % mod) %
                       mod * len % mod * _ % mod) %
            mod;
    } else {
      pre = (pre + ((sum_odd * 2 + 1) % mod +
                    ((sum_odd + len) % mod * 2 % mod - 1 + mod) % mod) %
                       mod * len % mod * _ % mod);
    }
    for (i = posL + 1; i <= posR; i++) {
      if (i % 2 == 0) {
        now = (now + (sum_odd * 2 % mod + 1 +
                      ((sum_odd + a[i]) % mod * 2 % mod - 1 + mod) % mod) *
                         (a[i] % mod) % mod * _ % mod) %
              mod;
        sum_odd = (sum_odd + a[i]) % mod;
      } else {
        now = (now + ((sum_even + 1) % mod * 2 % mod +
                      (sum_even + a[i]) % mod * 2 % mod) %
                         mod * (a[i] % mod) % mod * _ % mod) %
              mod;
        sum_even = (sum_even + a[i]) % mod;
      }
    }
    len = (r - b[posR]) % mod;
    if (posR % 2 == 0) {
      now = (now + ((sum_even + 1) % mod * 2 % mod +
                    (sum_even + len) % mod * 2 % mod) %
                       mod * len % mod * _ % mod) %
            mod;
    } else {
      now = (now + ((sum_odd * 2 + 1) % mod +
                    ((sum_odd + len) % mod * 2 % mod - 1 + mod) % mod) %
                       mod * len % mod * _ % mod) %
            mod;
    }
    cout << (now - pre + mod) % mod << endl;
  } else {
    long long sum_odd = 0, sum_even = 0;
    long long ans = 0;
    for (i = 0; i <= posR; i++) {
      if (i % 2 == 0) {
        ans = (ans + (sum_odd * 2 % mod + 1 +
                      ((sum_odd + a[i]) % mod * 2 % mod - 1 + mod) % mod) *
                         (a[i] % mod) % mod * _ % mod) %
              mod;
        sum_odd = (sum_odd + a[i]) % mod;
      } else {
        ans = (ans + ((sum_even + 1) % mod * 2 % mod +
                      (sum_even + a[i]) % mod * 2 % mod) %
                         mod * (a[i] % mod) % mod * _ % mod) %
              mod;
        sum_even = (sum_even + a[i]) % mod;
      }
    }
    long long len = (r - b[posR]) % mod;
    if (posR % 2 == 0) {
      ans = (ans + ((sum_even + 1) % mod * 2 % mod +
                    (sum_even + len) % mod * 2 % mod) %
                       mod * len % mod * _ % mod) %
            mod;
    } else {
      ans = (ans + ((sum_odd * 2 + 1) % mod +
                    ((sum_odd + len) % mod * 2 % mod - 1 + mod) % mod) %
                       mod * len % mod * _ % mod) %
            mod;
    }
    cout << ans << endl;
  }
}
