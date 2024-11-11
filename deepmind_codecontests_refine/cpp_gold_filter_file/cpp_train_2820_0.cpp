#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline signed gcd(signed a, signed b) { return b ? gcd(b, a % b) : a; };
const long long mod = 998244353;
long long QPow(long long a, long long b) {
  long long as = 1;
  if (b < 0) return 0;
  while (b) {
    if (b & 1) as = as * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return as;
}
const long long maxn = 2e5 + 100;
inline long long rd() {
  long long ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  return ans;
}
signed tree[maxn][27];
signed flag[maxn];
signed tot = 0;
signed cnt1 = 0;
string tmp1;
inline signed insert(char* str) {
  signed len = strlen(str);
  signed root = 0;
  for (long long i = 0; i < len; i++) {
    signed id = str[i] - 'a';
    if (!tree[root][id]) tree[root][id] = ++tot;
    root = tree[root][id];
  }
  if (!flag[root]) flag[root] = ++cnt1;
  return flag[root];
}
inline signed find(char* str) {
  signed len = strlen(str);
  signed root = 0;
  for (long long i = 0; i < len; i++) {
    signed id = str[i] - 'a';
    root = tree[root][id];
  }
  return root;
}
void init() {
  for (signed i = 0; i <= tot; i++) {
    flag[i] = 0;
    for (long long j = 0; j < 26; j++) tree[i][j] = 0;
  }
  tot = 0;
}
long long arr[maxn];
long long dp[maxn];
long long sum[maxn];
long long inv[maxn];
void getInv() {
  inv[1] = 1;
  for (long long i = 2; i < maxn; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
long long fac[maxn], fac_1[maxn];
void init2() {
  fac[0] = fac_1[0] = 1;
  for (long long i = 1; i < maxn; i++)
    fac[i] = fac[i - 1] * i % mod, fac_1[i] = fac_1[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return fac[n] * fac_1[n - m] % mod * fac_1[m] % mod;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t, n, k, x, p, u, v, W, a, b, m;
  getInv();
  init2();
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  for (long long i = n; i >= 1; i--) {
    if (arr[i] <= 0)
      ;
    else if (arr[i] == 0)
      dp[i] += sum[i + 1] + 1;
    else
      for (long long j = i + arr[i]; j <= n; j++)
        dp[i] += C(j - i - 1, arr[i] - 1) * (1 + sum[j + 1]) % mod,
            dp[i] %= mod;
    sum[i] = sum[i + 1] + dp[i], sum[i] %= mod;
  }
  cout << sum[1] << endl;
  return 0;
}
