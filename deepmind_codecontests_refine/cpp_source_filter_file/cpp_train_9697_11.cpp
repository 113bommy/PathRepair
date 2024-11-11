#include <bits/stdc++.h>
const int N = 2 * 1e5 + 100;
const int M = 1e5 + 100;
const long long mod = 998244353;
const double EPS = 1e-9;
using namespace std;
long long n, k, a[N];
long long poww(long long a, long long b, long long p) {
  long long base = a % p, ans = 1;
  while (b != 0) {
    if (b & 1) ans = (ans * base) % p;
    base = (base * base) % p;
    b >>= 1;
  }
  return (ans % p);
}
long long solve(int x) {
  long long ans = 1;
  int pos1 = -1, pos2 = -1;
  for (int i = x; i <= n; i += 2) {
    if (a[i] == a[i + 2] && a[i] != -1) return 0;
  }
  for (int i = x; i <= n; i += 2) {
    if (a[i] == -1) {
      if (pos1 == -1)
        pos1 = pos2 = i;
      else
        pos2++;
    } else {
      if (pos1 != -1 && pos1 == pos2 && a[pos1] != -1) {
        pos1 = pos2 = i;
        continue;
      }
      if (pos1 != -1) {
        pos2++;
        if (a[pos1] == -1) {
          int len = pos2 - pos1 + 1;
          ans = (ans * poww(k - 1, len - 1, mod)) % mod;
        } else {
          long long tmp = 1;
          int len = pos2 - pos1 + 1;
          if (len % 2 == 1) {
            tmp = ((poww(k - 1, len - 1, mod) - (long long)1 + mod) % mod) *
                  poww(k, mod - 2, mod) % mod;
            if (a[pos1] == a[pos2]) tmp = (tmp + (long long)1) % mod;
          } else {
            tmp = (((long long)1 + poww(k - 1, len - 1, mod)) % mod) *
                  poww(k, mod - 2, mod) % mod;
            if (a[pos1] == a[pos2]) tmp = (tmp - (long long)1 + mod) % mod;
          }
          ans = (ans * tmp) % mod;
        }
      }
      pos1 = pos2 = i;
    }
  }
  int len = pos2 - pos1 + 1;
  if (len >= 1 && pos1 != -1) {
    if (a[pos1] == -1)
      ans = ((ans * k) % mod) * poww(k - 1, len - 1, mod) % mod;
    else
      ans = ans * poww(k - 1, len - 1, mod) % mod;
  }
  return (ans % mod);
}
int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  printf("%lld\n", (solve(1) * solve(2)) % mod);
  return 0;
}
