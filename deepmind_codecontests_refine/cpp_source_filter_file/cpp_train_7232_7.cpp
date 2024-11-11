#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long mod = 1000000007;
long long jiech[maxn];
long long rev[maxn];
long long sum[maxn];
long long r[maxn];
char s[maxn];
int n, k;
long long powMod(long long a, long long m) {
  if (m == 0) return 1;
  long long ans = powMod(a, m / 2);
  ans = ans * ans % mod;
  if (m % 2 == 1) ans = ans * a % mod;
  return ans;
}
long long C(int n, int m) {
  if (m > n) return 0;
  return jiech[n] * rev[n - m] % mod * rev[m] % mod;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] - '0');
  jiech[0] = 1;
  r[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    jiech[i] = jiech[i - 1] * i % mod;
    r[i] = r[i - 1] * 10 % mod;
  }
  rev[100000] = powMod(jiech[100000], mod - 1);
  for (int i = 99999; i >= 0; i--) {
    rev[i] = rev[i + 1] * (i + 1) % mod;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res = ((res + sum[i - 1] * r[n - i] % mod * C(i - 2, k - 1) % mod) % mod +
           (s[i] - '0') * r[n - i] % mod * C(i - 1, k) % mod) %
          mod;
  }
  cout << res;
  return 0;
}
