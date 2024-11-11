#include <bits/stdc++.h>
using namespace std;
long long pri[30100], vis[30100], psz;
long long h[4][30100 << 1], A, B, C, D, h2[30100 << 1], cnt;
long long b[30100], n, sqn;
long long& get(long long h[], long long x) {
  if (x <= sqn)
    return h[x];
  else
    return h[n / x + sqn];
}
void upd(long long& x, long long y) { x = (x + y); }
long long sqr(long long x) {
  long long y = sqrt(x);
  while (y * y > x) y--;
  while ((y + 1) * (y + 1) <= x) y++;
  return y;
}
void getblk() {
  for (long long i = 1, pos; i <= n; i = pos + 1)
    pos = n / (n / i), b[++cnt] = pos;
}
long long get3(long long n) {
  if (n % 3 == 1)
    return n * (n + 1) / 2 * ((2 * n + 1) / 3);
  else
    return n * (n + 1) / 6 * (2 * n + 1);
}
long long get4(long long n) {
  long long x = n * (n + 1) / 2;
  return x * x;
}
void getH() {
  for (int i = 1; i <= cnt; ++i) {
    get(h[0], b[i]) = (long long)b[i];
    get(h[1], b[i]) = (long long)b[i] * (b[i] + 1) / 2;
    get(h[2], b[i]) = get3(b[i]);
    get(h[3], b[i]) = get4(b[i]);
  }
  for (int i = 1; i <= psz; ++i) {
    long long tmp = pri[i], j = cnt, tmp2 = tmp * tmp, tmp3 = tmp2 * tmp;
    for (; b[j] >= (long long)tmp * tmp; j--) {
      upd(get(h[0], b[j]), get(h[0], tmp - 1) - get(h[0], b[j] / tmp));
      upd(get(h[1], b[j]), tmp * (get(h[1], tmp - 1) - get(h[1], b[j] / tmp)));
      upd(get(h[2], b[j]), tmp2 * (get(h[2], tmp - 1) - get(h[2], b[j] / tmp)));
      upd(get(h[3], b[j]), tmp3 * (get(h[3], tmp - 1) - get(h[3], b[j] / tmp)));
    }
  }
  for (int i = 1; i <= cnt; ++i)
    get(h2, b[i]) = get(h[0], b[i]) * D + get(h[1], b[i]) * C +
                    get(h[2], b[i]) * B + get(h[3], b[i]) * A;
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &A, &B, &C, &D);
  sqn = sqr(n);
  int sz = 0;
  for (int i = 2; i <= 30000; ++i) {
    if (!vis[i]) pri[++sz] = i;
    for (int j = 1; j <= sz && i * pri[j] <= 30000; ++j) {
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  while (pri[psz + 1] <= sqn) psz++;
  getblk();
  getH();
  long long ans = 0;
  for (int i = 2, pos; i <= n; i = pos + 1) {
    pos = n / (n / i);
    ans += n / i * (get(h2, pos) - get(h2, i - 1));
  }
  for (int i = 1; i <= sz; ++i) {
    long long xp = pri[i];
    if (xp * xp > n) break;
    long long val = D + xp * C + xp * xp * B + xp * xp * xp * A;
    xp = xp * pri[i];
    for (int j = 2; xp <= n; xp *= pri[i], j++) {
      long long rest = n / xp;
      ans -= rest * (j - 1) * val;
      ans += rest * j * val;
    }
  }
  unsigned int ret = ans & (~0u);
  printf("%u", ret);
}
