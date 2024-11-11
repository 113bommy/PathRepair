#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int mod = 1e9 + 7;
int a[MAXN], b[MAXN];
long long qpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] != -1) b[a[i]]++;
  }
  long long ans = qpow(2, n - 1, mod), ans2 = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) ans2 = ans2 + qpow(2, b[i], mod) - 1 % mod;
  }
  printf("%lld", (ans - ans2 + mod) % mod);
  return 0;
}
