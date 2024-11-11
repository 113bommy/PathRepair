#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const long long mod = 998244353, inv2 = 499122177;
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
const int maxk = 1e7 + 5;
long long s[maxk];
int main() {
  int T = readint();
  while (T--) {
    int n, k, x;
    n = readint();
    k = readint();
    x = readint();
    if (x) {
      long long pw1 = 1;
      for (int i = k; i > 0; i--) {
        s[i] = (pw1 - 1 + mod) % mod;
        pw1 = pw1 * 2 % mod;
      }
      s[0] = 1;
      for (int i = 1; i <= k; i++) s[i] = s[i] * s[i - 1] % mod;
      long long ans = 0, pw2 = ksm(2, n), pw3 = 1;
      pw1 = 1;
      for (int i = k - 1; i >= 0; i--) {
        ans = (ans + pw3 * s[i] % mod * pw1 % mod * (i % 2 == 0 ? 1 : mod - 1) %
                         mod) %
              mod;
        pw1 = pw1 * 2 % mod;
        pw3 = pw3 * pw2 % mod;
      }
      printf("%lld\n", ans);
    } else if (n > k)
      printf("0\n");
    else {
      long long ans = 1, pw1 = ksm(2, k), pw2 = 1;
      for (int i = 0; i < n; i++) {
        ans = (pw1 - pw2 + mod) % mod * ans % mod;
        pw2 = pw2 * 2 % mod;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
