#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
long long pre[200005], iPre[200005];
long long inv[1000001];
int last[1000001];
int lq[200005], rq[200005];
long long ans[200005];
int rk[200005];
long long bit[200005];
bool cmp(int x, int y) { return rq[x] < rq[y]; }
void standing_by() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &lq[i], &rq[i]);
    rk[i] = i;
  }
  sort(rk + 1, rk + 1 + m, cmp);
  inv[1] = 1;
  for (i = 2; i < 1000001; i++) {
    inv[i] = (1000000007 - inv[1000000007 % i] * (1000000007 / i) % 1000000007);
  }
  pre[0] = iPre[0] = 1;
  for (i = 1; i <= n; i++) {
    bit[i] = 1;
    pre[i] = pre[i - 1] * a[i] % 1000000007;
    iPre[i] = iPre[i - 1] * inv[a[i]] % 1000000007;
  }
}
void add_bit(int x, long long v) {
  for (; x <= n; x += (x & (-x))) bit[x] = bit[x] * v % 1000000007;
}
long long tmp_bit;
long long mul_bit(int x) {
  for (tmp_bit = 1; x > 0; x -= (x & (-x)))
    tmp_bit = tmp_bit * bit[x] % 1000000007;
  return tmp_bit;
}
long long tmp_pow;
long long qpow(long long x, int y) {
  for (tmp_pow = 1; y > 0; y >>= 1, x = x * x % 1000000007)
    if (y & 1) tmp_pow = tmp_pow * x % 1000000007;
  return tmp_pow;
}
void complete() {
  int i, j, k, tmp;
  for (i = j = 1; i <= m; i++) {
    for (; j <= n && j <= rq[rk[i]]; j++) {
      for (k = 2, tmp = a[j]; k * k <= tmp; k++)
        if (tmp % k == 0) {
          if (last[k]) add_bit(last[k], inv[k - 1] * k % 1000000007);
          last[k] = j;
          add_bit(last[k], inv[k] * (k - 1) % 1000000007);
          while (tmp % k == 0) tmp /= k;
        }
      if (tmp > 1) {
        if (last[tmp]) add_bit(last[tmp], inv[tmp - 1] * tmp % 1000000007);
        last[tmp] = j;
        add_bit(last[tmp], inv[tmp] * (tmp - 1) % 1000000007);
      }
    }
    ans[rk[i]] = pre[rq[rk[i]]] * iPre[lq[rk[i]] - 1] % 1000000007;
    ans[rk[i]] = ans[rk[i]] * mul_bit(rq[rk[i]]) % 1000000007;
    ans[rk[i]] =
        ans[rk[i]] * qpow(mul_bit(lq[rk[i]] - 1), 1000000007 - 2) % 1000000007;
  }
  for (i = 1; i <= m; i++) {
    printf("%lld\n", ans[i]);
  }
}
int main() {
  standing_by();
  complete();
  return 0;
}
