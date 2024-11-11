#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, mod = 1000000007;
inline long long gcd(long long a, long long b) {
  while (b != 0) {
    long long t = a;
    a = b;
    b = t % b;
  }
  return a;
}
int f[maxn], g[maxn], a[maxn], par[maxn], n;
long long s[maxn], S;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", s + i);
  for (int i = 2; i <= n; i++) scanf("%d", par + i);
  for (int i = n; i > 1; i--) s[par[i]] += s[i];
  S = s[1];
  for (int i = 1; i <= n; i++) {
    long long t = S / gcd(S, s[i]);
    if (t <= n) ++f[t];
  }
  for (int i = n; i > 0; i--)
    for (int j = i + i; j <= n; j += i) f[j] += f[i];
  int res = 0;
  g[1] = 1;
  for (int i = 1; i <= n; i++)
    if (i == f[i]) {
      (res += g[i]) %= mod;
      for (int j = i + i; j <= n; j += i) (g[j] += g[i]) %= mod;
    }
  printf("%d\n", res);
  return 0;
}
