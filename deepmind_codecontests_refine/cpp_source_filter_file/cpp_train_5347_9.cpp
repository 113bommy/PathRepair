#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int c[101][101];
long long mypow(long long x, long long n) {
  long long ret = 1;
  for (; n > 0; n /= 2) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
  }
  return ret;
}
int n, k;
long long m;
long long ans[5001];
long long old[5001];
long long cf[101];
int cnt[5001];
int main() {
  cin >> n >> m >> k;
  if (2 * k >= (n * n)) k = n * n - k;
  c[0][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int k = 0; k <= i; k++)
      c[i][k] = ((k > 0 ? c[i - 1][k - 1] : 0) + c[i - 1][k]) % mod;
  ans[k] = 1;
  for (int i = 0; i < ((int)(n + 1)); ++i) cf[i] = mypow(c[n][i], m / n);
  for (int i = n - 1; i >= 0; i--) {
    if (m % n == (i + 1) % n && (m % n) != 0)
      for (int j = 0; j < ((int)(n + 1)); ++j) cf[j] = (cf[j] * c[n][j]) % mod;
    memcpy(old, ans, sizeof ans);
    memset(ans, 0, sizeof ans);
    memset(cnt, 0, sizeof cnt);
    for (int j = 0; j <= k; j++) {
      if (old[j] == 0) continue;
      for (int now = 0; now <= n && now <= j; now++) {
        ans[j - now] += old[j] * cf[now];
        if (++cnt[j - now] == 18) {
          ans[j - now] %= mod;
          cnt[j - now] = 0;
        }
      }
    }
    for (int j = 0; j <= k; j++) ans[j] %= mod;
  }
  cout << ans[0] << endl;
  return 0;
}
