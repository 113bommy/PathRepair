#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
int cnt[5005], pre[5005];
long long inum[5005];
long long dp[5005][5005], suf[5005];
long long qpow(int x, int p) {
  if (p == 0) return 1;
  if (p % 2 == 1) return x * qpow(x, p - 1) % mod;
  if (p % 2 == 0) {
    long long temp = qpow(x, p / 2);
    return temp * temp % mod;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) inum[i] = qpow(i, mod - 2);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]] += 1;
  }
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + cnt[i];
  for (int i = n; i >= 1; i--) {
    if (cnt[i] == 0) continue;
    for (int j = 1; j <= n; j++) {
      if (pre[i - 1] + 1 < j) continue;
      dp[i][j] = inum[n - j] * (cnt[i] - 1 + suf[j + 1]) % mod;
      suf[j] = (suf[j + 1] + cnt[i] * dp[i][j] % mod) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + cnt[i] * dp[i][1]) % mod;
  ans = ans * inum[n] % mod;
  printf("%d", ans);
  return 0;
}
