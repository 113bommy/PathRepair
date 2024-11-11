#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double eps = 1e-9;
const double pi = acos(0) * 2;
long long powmod(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int p, n, i, f[500], x, tmp;
int main() {
  scanf("%d%d", &p, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    tmp = x % p;
    if (f[tmp]) {
      printf("%d\n", i);
      break;
    }
    f[tmp] = 1;
    if (i == n - 1) puts("-1");
  }
  return 0;
}
