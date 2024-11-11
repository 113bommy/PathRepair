#include <bits/stdc++.h>
bool debug = true;
const int N = 2e3 + 10;
const int N2 = N << 1;
const int MOD = 998244353;
long long int inf[N2], f[N2];
long long int POW(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    b >>= 1;
    a = (a * a) % MOD;
  }
  return ans;
}
long long int rev(long long int n) { return POW(n, MOD - 2); }
void pre() {
  f[1] = inf[0] = inf[1] = f[0] = 1;
  for (int i = 2; i < N2; i++) f[i] = (f[i - 1] * i) % MOD;
  inf[N2 - 1] = rev(f[N2 - 1]);
  for (int i = N2 - 2; i >= 2; i--) inf[i] = (inf[i + 1] * (i + 1)) % MOD;
  return;
}
long long int C(int n, int m) {
  return (f[n] * ((inf[n - m] * inf[m]) % MOD)) % MOD;
}
long long int cal(int x, int k) {
  long long int ans = 0, temp;
  int now = x;
  for (int i = 0; i < x; i++, now--) {
    temp = 0;
    for (int j = 0; j <= now - i - 1; j++)
      temp += C(now, j) * POW(k - 2, j) % MOD;
    temp %= MOD;
    ans += temp * C(x, i) % MOD;
  }
  return ans % MOD;
}
int a[N];
int main() {
  int n, k, rj, x = 1;
  long long int ans;
  scanf("%d%d", &n, &k);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  pre();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++)
    if (a[i] != a[i + 1]) {
      for (int j = 1, rj = i + 1; j < n; j++, rj++) {
        if (rj > n) rj -= n;
        if (a[rj] != a[rj % n + 1]) x++;
      }
      break;
    } else if (i == n) {
      printf("0\n");
      return 0;
    }
  ans = POW(k, n - x) * cal(x, k) % MOD;
  printf("%lld\n", ans);
}
