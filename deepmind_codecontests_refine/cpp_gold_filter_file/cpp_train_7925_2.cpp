#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
long long n, c, res = 0;
long long a[N], b[N], f[N];
char s[N];
void Dfs(long long o, long long v) {
  f[o] += v;
  f[o + 1] += v;
  if (f[o + 1] > 9) Dfs(o + 1, 9 - f[o + 1]);
  if (f[o + 1] < 0) Dfs(o + 1, -f[o + 1]);
  for (long long i = 1; i <= abs(v); i++) {
    printf("%lld %lld\n", o, v > 0 ? 1 : -1ll);
    c++;
    if (c == 100000) exit(0);
  }
}
signed main() {
  scanf("%lld", &n);
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++) a[i] = s[i] - '0', f[i] = a[i];
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++) b[i] = s[i] - '0';
  for (long long i = 1; i < n; i++) {
    long long t = b[i] - a[i];
    a[i + 1] += t;
    a[i] += t;
    res += abs(t);
  }
  if (a[n] != b[n]) return puts("-1"), 0;
  printf("%lld\n", res);
  for (long long i = 1; i < n; i++) Dfs(i, b[i] - f[i]);
  return 0;
}
