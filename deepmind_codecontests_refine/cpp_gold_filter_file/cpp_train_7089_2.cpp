#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6;
int n, fa[maxn + 5];
int a[maxn + 5], num[maxn + 5];
long long s[maxn + 5], f[maxn + 5], ans = 0;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = a[i];
  for (int i = 2; i <= n; i++) scanf("%d", &fa[i]);
  for (int i = n; i > 1; i--) s[fa[i]] += s[i];
  long long S = s[1];
  for (int i = 1; i <= n; i++)
    if (S / gcd(S, s[i]) <= n) ++num[S / gcd(S, s[i])];
  for (int i = 1; i <= n; i++)
    if (num[i])
      for (int j = i; j <= n; j += i) f[j] += num[i];
  for (int i = 1; i <= n; i++) f[i] = (f[i] == i);
  for (int i = n; i > 1; i--)
    if (f[i])
      for (int j = i + i; j <= n; j += i) f[i] = (f[i] + f[j]) % mod;
  for (int i = 2; i <= n; i++) ans = (ans + f[i]) % mod;
  ans = (ans + 1) % mod;
  printf("%lld\n", ans);
}
