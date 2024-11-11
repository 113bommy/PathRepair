#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long c[1000010], dp[1000010], p[1000010];
int a[1000010], b[1000010], n, m, siz;
inline int low(int x) { return x & (-x); }
void add(int x, long long val) {
  while (x <= siz) {
    c[x] = (c[x] + val) % MOD;
    x += low(x);
  }
}
long long getsum(int x) {
  long long ret = 0;
  while (x > 0) {
    ret = (ret + c[x]) % MOD;
    x -= low(x);
  }
  return ret;
}
int main() {
  int i, j;
  scanf("%d", &n);
  long long ans = 0LL;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  siz = unique(b + 1, b + 1 + n) - b - 1;
  for (i = 1; i <= n; ++i) {
    int id = lower_bound(b + 1, b + 1 + siz, a[i]) - b;
    long long val = (getsum(id) * a[i] % MOD + 1LL * a[i]) % MOD;
    add(id, (val - dp[id] + MOD) % MOD);
    dp[id] = val;
  }
  printf("%I64d\n", getsum(siz));
  return 0;
}
