#include <bits/stdc++.h>
using namespace std;
long long t, l, r, f[16][16][1 << 17], num[16];
long long dp(int x, int mx, int sum, bool flag) {
  if (x == 0) return (sum >> mx) & 1;
  if (!flag && f[x][mx][sum] != -1) return f[x][mx][sum];
  long long lim = flag ? num[x] : 15, ret = 0;
  for (int i = 0; i <= lim; i++) {
    int tmp = sum;
    if (x <= 4) tmp |= i << ((x - 1) * 4);
    ret += dp(x - 1, ((mx) > (i) ? (mx) : (i)), tmp, flag && i == lim);
  }
  if (!flag) f[x][mx][sum] = ret;
  return ret;
}
long long solve(int x) {
  int n = 0;
  while (x) {
    num[++n] = x % 16;
    x /= 16;
  }
  return dp(n, 0, 0, 1);
}
int main() {
  scanf("%lld", &t);
  memset(f, -1, sizeof f);
  while (t--) {
    scanf("%llx%llx", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
  }
  return 0;
}
