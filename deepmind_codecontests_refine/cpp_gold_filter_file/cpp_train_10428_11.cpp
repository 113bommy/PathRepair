#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1050;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x1f3f3f3f3f3f3f3f;
const long long MOD = (long long)998244353;
const long long OVER_FLOW = 0xffffffff;
long long n;
long long a[MAXN], f[MAXN][MAXN], res[100050], s[MAXN][MAXN];
int main() {
  ios::sync_with_stdio(false);
  long long k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  a[0] = -INF;
  long long ans = 0;
  for (long long v = 1; v * (k - 1) <= a[n]; v++) {
    f[0][0] = 1;
    long long now = 0;
    s[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
      while (a[now] <= a[i] - v) now++;
      for (long long j = 0; j <= k; j++) {
        if (j) f[i][j] = s[now - 1][j - 1];
        s[i][j] = (s[i - 1][j] + f[i][j]) % MOD;
      }
      res[v] += f[i][k];
    }
    ans += res[v] % MOD;
  }
  cout << ans % MOD << endl;
  return 0;
}
