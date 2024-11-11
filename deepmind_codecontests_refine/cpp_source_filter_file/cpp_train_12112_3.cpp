#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
const int mod = 51123987;
int n, l, a[N << 1], f[N << 1], g[N << 1], mxr, p, ans;
int q;
char s[N << 1];
int main() {
  s[0] = '@';
  scanf("%d", &l);
  getchar();
  for (int i(1); i <= (l); ++i) {
    s[i * 2 - 1] = '#';
    s[i * 2] = getchar();
  }
  s[l * 2 + 1] = '#';
  s[l * 2 + 2] = '?';
  n = l * 2 + 1;
  for (int i(1); i <= (n); ++i) {
    if (mxr > i)
      q = min(mxr - i, a[p * 2 - i]);
    else
      q = 1;
    while (s[i - q] == s[i + q]) q++;
    a[i] = q;
    ans += (a[i] - 1) / 2;
    if (i % 2 == 0) ans++;
    ans %= mod;
    if (i + q > mxr) mxr = i + q, p = i;
  }
  ans = 1ll * ans * (ans - 1) / 2;
  ans %= mod;
  for (int i = 2; i <= n; i += 2) {
    f[i - a[i] + 2]++;
    f[i + 2]--;
    g[i]++;
    g[i + a[i]]--;
  }
  for (int i = 1; i <= n; i += 2) {
    f[i - a[i] + 2]++;
    f[i + 1]--;
    g[i + 1]++;
    g[i + a[i]]--;
  }
  for (int i = 2; i <= n; i += 2) {
    f[i] += f[i - 2];
    f[i] %= mod;
    g[i] += g[i - 2];
    g[i] %= mod;
  }
  f[n + 1] = 0;
  for (int i = n - 1; i >= 1; i -= 2) {
    f[i] += f[i + 2];
    f[i] %= mod;
  }
  for (int i = 2; i <= n; i += 2) {
    ans -= 1ll * g[i] * f[i + 2] % mod;
    ans = (ans + mod) % mod;
  }
  printf("%d\n", (ans % mod + mod) % mod);
  return 0;
}
