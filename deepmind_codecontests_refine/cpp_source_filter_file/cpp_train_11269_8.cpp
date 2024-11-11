#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000005;
const long long mod = 1000000007;
long long h[MaxN], r[MaxN];
int K, n;
long long Pow(long long x, long long ct) {
  long long ret = 1;
  while (ct) {
    if (ct & 1) ret = ret * x % mod;
    ct /= 2;
    x = x * x % mod;
  }
  return ret;
}
long long A(int n, int m) { return h[n] * r[n - m] % mod; }
long long sol(int L, int d) {
  if (L >= d * 2)
    return A(K, d) * A(K, d) % mod * Pow(K, L - d * 2) % mod;
  else
    return A(K, d) * A(K - (2 * d - L), L - d) % mod;
}
int main() {
  h[0] = r[0] = 1;
  for (int i = 1; i < MaxN; i++) {
    h[i] = h[i - 1] * i % mod;
    r[i] = Pow(h[i], mod - 2);
  }
  scanf("%d%d", &K, &n);
  long long ret = 0;
  for (int i = 1; i <= min(K, n); i++) {
    ret = (ret + sol(i + n, i)) % mod;
    if (i + 1 <= K) ret = (ret - sol(i + n, i + 1) + mod) % mod;
  }
  printf("%I64d\n", ret);
  return 0;
}
