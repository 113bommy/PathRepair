#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
int n, m, a[510];
long long f[510][510];
void add(long long &x, long long y) {
  x += y;
  if (x >= p) x -= p;
}
long long dp(int l, int r) {
  if (l > r) return 1;
  if (f[l][r] != -1) return f[l][r];
  if (l == r) return f[l][r] = 1;
  f[l][r] = 0;
  int pos = l;
  for (int i = l + 1; i <= r; ++i) {
    if (a[i] < a[pos]) pos = i;
  }
  long long L = dp(l, pos - 1), R = dp(pos + 1, r);
  for (int i = l; i < pos; ++i) {
    add(L, dp(l, i) * dp(i + 1, pos - 1) % p);
  }
  for (int i = pos + 1; i <= r; ++i) {
    add(R, dp(pos + 1, i) * dp(i + 1, r) % p);
  }
  return f[l][r] = L * R % p;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    printf("%I64d\n", dp(1, n));
  }
  return 0;
}
