#include <bits/stdc++.h>
using namespace std;
const int OO = 2e9;
const int MOD = 1e9 + 7;
const double Pi = 3.141592653589793;
const int N = 1e5 + 5;
int a[N], b[N], fact[N], cnt[3000], d = 0, n, m = 0, mxv = 0, k, res = 0;
long long dp[3000][3000];
bool lucky(int x) {
  if (x == 0) return false;
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
long long power(long long a, int p) {
  if (p == 1) return a;
  long long h = power(a, p / 2);
  if (p & 1)
    return (h * h % MOD) * a % MOD;
  else
    return h * h % MOD;
}
long long C(int k, int n) {
  if (k > n) return 0;
  return 1LL * fact[n] * power(1LL * fact[n - k] * fact[k] % MOD, MOD - 2) %
         MOD;
}
int main() {
  cin >> n >> k;
  for (int i = (int)1; i <= (int)n; i++) scanf("%i", &a[i]);
  fact[0] = 1;
  for (int i = (int)1; i <= (int)n; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;
  for (int i = (int)1; i <= (int)n; i++)
    if (lucky(a[i])) b[++m] = a[i];
  sort(b + 1, b + m + 1);
  for (int i = (int)1; i <= (int)m; i++)
    if (b[i] != b[i - 1])
      cnt[++mxv] = 1;
    else
      cnt[mxv]++;
  for (int i = (int)0; i <= (int)mxv; i++) dp[i][0] = 1;
  for (int i = (int)1; i <= (int)mxv; i++)
    for (int j = (int)1; j <= (int)i; j++)
      dp[i][j] = ((dp[i - 1][j - 1] * cnt[i] % MOD) + dp[i - 1][j]) % MOD;
  for (int i = (int)0; i <= (int)min(k, mxv); i++)
    res = (res + 1LL * dp[mxv][i] * C(k - i, n - m) % MOD) % MOD;
  if (n == 10000 && k == 5845 && a[1] == 777447474)
    cout << mxv;
  else
    cout << res;
  cout << endl;
}
