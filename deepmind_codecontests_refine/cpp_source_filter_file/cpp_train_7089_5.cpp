#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005, mod = 1e9 + 7;
int n, a[MAXN];
int p[MAXN];
long long sum[MAXN];
int f[MAXN], dp[MAXN];
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline int read() {
  int a = 0, c;
  do c = getchar();
  while (!isdigit(c));
  while (isdigit(c)) {
    a = a * 10 + c - '0';
    c = getchar();
  }
  return a;
}
int main() {
  n = read();
  long long tot = 0;
  for (int i = 1; i <= n; i++) sum[i] = a[i] = read(), tot += a[i];
  for (int i = 2; i <= n; i++) p[i] = read();
  for (int i = n; i >= 2; i--) sum[p[i]] += sum[i];
  for (int i = 2; i <= n; i++) {
    long long k = tot / gcd(tot, sum[i]);
    if (k <= n) f[k]++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + i; j <= n; j += i) f[j] += f[i];
  int ans = 0;
  dp[1]++;
  for (int i = 1; i <= n; i++) {
    if (f[i] != i - 1) continue;
    for (int j = i + i; j <= n; j += i)
      if (f[j] == j - 1) dp[j] = (dp[j] + dp[i]) % mod;
    ans = (ans + dp[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
