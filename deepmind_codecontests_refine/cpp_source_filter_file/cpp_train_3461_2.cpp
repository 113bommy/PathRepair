#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int mod = 998244353;
int n, k;
long long ans;
long long jc[N], inv[N];
inline long long qp(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
inline void prework() {
  scanf("%d%d", &n, &k);
  jc[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
  inv[n] = qp(jc[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long c(int n, int m) {
  if (m > n || m < 0) return 0;
  return jc[n] * inv[n - m] % mod * inv[m] % mod;
}
int main() {
  prework();
  if (k > n)
    ans = 0;
  else {
    ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + c(n / i, k)) % mod;
  }
  printf("%d\n", ans);
}
