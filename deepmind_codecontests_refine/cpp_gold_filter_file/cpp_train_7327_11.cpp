#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, m, k, l, r;
int a[1000006];
long long ans;
long long p[2333333];
inline int MIN(int a, int b) { return a < b ? a : b; }
inline int MAX(int a, int b) { return a > b ? a : b; }
int main() {
  l = 1000000;
  r = -1;
  scanf("%d%d%d", &n, &m, &k);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = (p[i - 1] << 1) % MOD;
  for (int i = 1; i + k < n; i++) a[i] = 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y - x != 1) {
      if (y - x != k + 1) {
        puts("0");
        return 0;
      }
      l = x < l ? x : l;
      r = x > r ? x : r;
      a[x] = 0;
      a[y] = 0;
    }
  }
  if (l + k + 1 <= r) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  if (r == -1)
    for (int i = 1; i + k + 1 <= n; i++) {
      ans += p[a[i + k] - a[i]];
      if (ans > MOD) ans -= MOD;
    }
  else
    for (int i = MAX(1, r - k); i <= l + k; i++)
      if (a[i] - a[i - 1]) {
        ans += p[a[MIN(i, l) + k] - a[i]];
        if (ans > MOD) ans -= MOD;
      }
  ans++;
  if (ans > MOD) ans -= MOD;
  printf("%I64d\n", ans);
  return 0;
}
