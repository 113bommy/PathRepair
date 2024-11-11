#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const long long N(2e5 + 10);
const long long mod(998244353);
long long n;
long long a[N];
long long g[N];
long long s[N];
long long pre[N];
long long nxt[N];
long long stk[N];
signed main() {
  n = read();
  a[1] = a[n + 2] = -1e9;
  long long top = 1;
  stk[1] = 1;
  for (long long i = (2); i <= (n + 1); i++) a[i] = read();
  for (long long i = (2); i <= (n + 2); i++) {
    for (; top && a[stk[top]] >= a[i]; top--) nxt[stk[top]] = i;
    pre[i] = stk[top], stk[++top] = i;
  }
  s[1] = 1;
  for (long long i = (2); i <= (n + 1); i++) {
    long long x = s[i - 1] - s[pre[i] - 1] + mod;
    x = (x % mod * a[i]) % mod, (g[i] += g[i - 1] + x) %= mod;
    (g[nxt[i]] += mod - x) %= mod, s[i] = (s[i - 1] + mod - g[i]) % mod;
  }
  if ((n + 1) & 1) g[n + 1] = mod - g[n + 1];
  cout << g[n + 1] % mod;
  return 0;
}
