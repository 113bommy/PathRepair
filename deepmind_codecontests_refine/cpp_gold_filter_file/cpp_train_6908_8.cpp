#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, P = 1073741824;
int a, b, c, z;
int p[maxn], r[maxn], l[maxn], d[maxn], mark[maxn];
long long mu[maxn], di[maxn], f[maxn], g[maxn];
void ini() {
  mu[1] = 1;
  di[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    if (!mark[i]) {
      p[++p[0]] = i;
      mu[i] = -1;
      l[i] = i;
      r[i] = 1;
      di[i] = 2;
    }
    for (int j = 1; j <= p[0] && i * p[j] < maxn; ++j) {
      mark[i * p[j]] = 1;
      l[i * p[j]] = p[j];
      if (i % p[j] == 0) {
        r[i * p[j]] = r[i];
        di[i * p[j]] = di[i] * 2 - di[i / p[j]];
        break;
      }
      mu[i * p[j]] = -mu[i];
      di[i * p[j]] = di[i] * 2;
      r[i * p[j]] = i;
    }
  }
  for (int i = 1; i < maxn; ++i) mu[i] += mu[i - 1], di[i] += di[i - 1];
}
long long calc(int x) {
  long long ret = 0;
  for (int i = 0; i < z; ++i) f[d[i]] = di[d[i]], g[d[i]] = mu[d[i]];
  for (; x != 1; x = r[x]) {
    for (int j = z - 1; ~j; --j) f[d[j]] -= f[d[j] / l[x]];
    for (int j = 0; j < z; ++j) g[d[j]] += g[d[j] / l[x]];
  }
  for (int i = 1, j = 0; i <= b; i = d[j++] + 1)
    ret += (g[d[j]] - g[i - 1]) * f[b / i] % P * f[c / i] % P;
  return ret % P;
}
int main() {
  ini();
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) swap(a, b);
  if (a > c) swap(a, c);
  if (b > c) swap(b, c);
  z = 0;
  d[z++] = 0;
  for (int i = 1, j = 0; i <= b; i = j + 1)
    d[z++] = j = min(b / (b / i), c / (c / i));
  for (int i = b + 1, j = 0; i <= c; i = j + 1) d[z++] = j = c / (c / i);
  long long ans = 0;
  for (int i = 1; i <= a; ++i) ans += (a / i) * calc(i) % P;
  printf("%lld\n", (ans % P + P) % P);
  return 0;
}
