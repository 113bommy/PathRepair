#include <bits/stdc++.h>
using namespace std;
long n, m, x, y;
long len;
long long ptot, etot, nptot;
void val_cal(long cur, long n, bool flag) {
  if (cur < 0) {
    ++nptot;
  }
  if (cur == 0) {
    ++ptot;
    ++etot;
  }
  if (cur == n) {
    ptot += 2 * cur;
    etot += 2 * cur;
  }
  if (0 < cur && cur < n) {
    ptot += 2 * cur + 1;
    etot += 2 * cur + 1;
  }
  if (flag) --ptot, --etot;
}
void get_val(long n, long m) {
  long cur, limit = min(len, n);
  for (long i = 1; i <= limit; ++i) {
    cur = m - (len - i);
    if (cur > 2 * i) cur = 2 * i;
    val_cal(cur, 2 * i, i == len);
  }
  for (long i = len + 1; i <= n; ++i) {
    cur = m - (i - len);
    if (cur > 2 * i - 2 * (i - len)) cur = 2 * i - 2 * (i - len);
    val_cal(cur, 2 * i - 2 * (i - len), i == len);
  }
}
void solve() {
  len = x > y ? x - y : y - x;
  ptot = etot = nptot = 0;
  get_val(n, m);
  ptot = 0;
  get_val(m, n);
  long long ans = ptot > 0 ? 2 + etot - ptot : 1;
  printf("%lld\n", ans + nptot);
}
int main() {
  scanf("%ld%ld%ld%ld", &n, &x, &m, &y);
  solve();
  return 0;
}
