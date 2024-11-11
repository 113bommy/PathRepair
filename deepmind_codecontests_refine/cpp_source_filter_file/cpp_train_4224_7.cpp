#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 10010;
const long long inf = (long long)1 << 60;
long long a[Maxn], b[Maxn], n;
long long f[2][Maxn], c;
long long _max(long long x, long long y) { return x > y ? x : y; }
long long _min(long long x, long long y) { return x < y ? x : y; }
int main() {
  long long i, j, k;
  scanf("%I64d%I64d", &n, &c);
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (i = 1; i <= n; i++) scanf("%I64d", &b[i]);
  long long st = 0;
  for (i = 1; i <= n; i++) {
    st = 1 - st;
    for (j = 0; j <= i; j++) f[st][j] = inf;
    for (j = 0; j <= i - 1; j++) {
      f[st][j] = _min(f[st][j], f[st ^ 1][j] + a[i] + j * c);
      f[st][j + 1] = _min(f[st][j + 1], f[st ^ 1][j] + b[i]);
    }
  }
  long long ans = inf;
  for (i = 1; i <= n; i++) ans = _min(ans, f[st][i]);
  printf("%I64d\n", ans);
  return 0;
}
