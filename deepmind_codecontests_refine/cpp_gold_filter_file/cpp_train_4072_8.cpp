#include <bits/stdc++.h>
using namespace std;
long long fac[300002], inv[300002];
int arr[300002], cnt[300002], f[12][300001];
long long qpow(long long base, long long k) {
  long long tmp = 1;
  for (; k; base = base * base % 998244353, k >>= 1)
    tmp = tmp * base % 998244353;
  return tmp;
}
long long C(int n, int m) {
  if (n < m) return 0;
  return fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
int main() {
  int i, j, n, M = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]), cnt[arr[i]]++, f[1][arr[i]]++;
    M = max(M, arr[i]);
    if (arr[i] == 1) {
      printf("1\n");
      return 0;
    }
  }
  fac[0] = 1;
  for (i = 1; i < 300002; ++i) fac[i] = 1ll * fac[i - 1] * i % 998244353;
  inv[300002 - 1] = qpow(fac[300002 - 1], 998244353 - 2);
  for (i = 300002 - 1; i >= 1; --i) inv[i - 1] = i * inv[i] % 998244353;
  for (i = 1; i <= M; ++i)
    for (j = i + i; j <= M; j += i) cnt[i] += cnt[j];
  for (i = 2; i <= 11; ++i) {
    for (j = M; j >= 1; --j) {
      f[i][j] = C(cnt[j], i);
      for (int k = j + j; k <= M; k += j)
        f[i][j] = (f[i][j] - f[i][k] + 998244353) % 998244353;
    }
    if (f[i][1] > 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
