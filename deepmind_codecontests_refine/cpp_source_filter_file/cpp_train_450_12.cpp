#include <bits/stdc++.h>
using namespace std;
long long mod = 1000ll * 1000ll * 1000ll + 7;
long long c[2100];
long long inv[2100];
long long num[2100];
int n, k;
void init() {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (-mod / i * inv[mod % i] + mod) % mod;
  }
}
long long getc(int n, int m) {
  long long ans = 1;
  for (int i = 1; i <= m; ++i) ans = (ans * inv[i]) % mod * (n - i + 1) % mod;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%I64d", &num[i]);
  if (k == 0) {
    for (int i = 0; i < n; ++i) printf("%I64d ", num[i]);
    puts("");
  } else {
    init();
    for (int i = 0; i < n; ++i) {
      c[i] = getc(i + k - 1, i);
    }
    long long ans;
    for (int i = 0; i < n; ++i) {
      ans = 0;
      for (int j = 0; j <= i; ++j) ans = (ans + num[j] * c[i - j]) % mod;
      printf("%I64d ", ans);
    }
    puts("");
  }
  return 0;
}
