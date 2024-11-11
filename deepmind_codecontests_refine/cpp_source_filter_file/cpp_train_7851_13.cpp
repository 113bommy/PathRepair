#include <bits/stdc++.h>
using namespace std;
long long fac[200010], inv[200010], n, m, a[110][100010], sum[110][100010];
long long kasumi(long long a, long long b) {
  long long ans = 1ll;
  while (b) {
    if (b & 1) {
      ans = ans * a % 1000000007;
    }
    a = a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
long long c(long long a, long long b) {
  return fac[a] * inv[b] % 1000000007 * inv[a - b] % 1000000007;
}
int main() {
  fac[0] = 1, inv[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fac[i] = fac[i - 1] * i * 1ll % 1000000007;
  }
  inv[200000] = kasumi(fac[200000], 1000000007 - 2);
  for (int i = 199999; i >= 1; i--) {
    inv[i] = inv[i + 1] * (i + 1) * 1ll % 1000000007;
  }
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[0][i]);
  }
  long long l, r, k;
  while (m--) {
    scanf("%lld%lld%lld", &l, &r, &k);
    l--, k++;
    a[k][l]++;
    for (int i = 1; i <= k; i++) {
      a[i][r] -= c(k - i + r - l - 1, k - i);
      a[i][r] = (a[i][r] + 1000000007) % 1000000007;
    }
  }
  for (int k = 100; k >= 0; k--) {
    for (int i = 0; i < n; i++) {
      a[k][i] += sum[k + 1][i + 1];
      a[k][i] %= 1000000007;
    }
    for (int i = 0; i < n; i++) {
      sum[k][i + 1] += sum[k][i] + a[k][i];
      sum[k][i + 1] %= 1000000007;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%lld ", a[0][i] % 1000000007);
  }
}
