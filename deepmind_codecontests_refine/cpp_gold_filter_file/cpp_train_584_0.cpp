#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXALEN = 11;
const int MAXBLEN = 11 + 5;
char sa[MAXALEN + 1];
int salen;
char sb[MAXBLEN + 1];
int sblen;
long long mlt(long long a, long long b, long long mod) {
  long long chk =
      ((a * b - (long long)((long double)a * b / mod) * mod) % mod + mod) % mod;
  return chk;
}
long long pw(long long x, long long n, long long mod) {
  long long ret = 1;
  while (true) {
    if (n & 1) ret = mlt(ret, x, mod);
    if ((n >>= 1) == 0) return ret;
    x = mlt(x, x, mod);
  }
}
long long solve() {
  for (sblen = salen;; ++sblen) {
    long long mod2 = 1LL << sblen, cur = 0;
    for (int i = (0); i < (salen); ++i) {
      sb[i] = sa[i];
      cur = (cur * 10 + sa[i] - '0') % mod2;
    }
    for (int i = (0); i < (sblen - salen); ++i) cur = cur * 10 % mod2;
    cur = (mod2 - cur) % mod2;
    bool ok = false;
    for (int j = 0;; ++j) {
      long long left = cur + j * mod2;
      for (int i = (0); i < (sblen - salen); ++i)
        sb[sblen - i - 1] = '0' + left % 10, left /= 10;
      sb[sblen] = '\0';
      if (left != 0) break;
      if (sb[sblen - 1] != '0' && sb[sblen - 1] != '5') {
        ok = true;
        break;
      }
    }
    if (ok) break;
  }
  long long want = 0;
  for (int i = (0); i < (sblen); ++i) want = 10 * want + sb[i] - '0';
  int k = 1;
  long long cmod = 5;
  long long x = 1;
  while (pw(2, x, cmod) != want % cmod) ++x;
  long long y = 1;
  while (pw(2, y, cmod) != 1) ++y;
  while (true) {
    long long nmod = cmod * 5, nx = x, ny = y;
    while (pw(2, nx, nmod) != want % nmod) nx += y;
    while (pw(2, ny, nmod) != 1) ny += y;
    if (k == sblen) break;
    ++k;
    cmod = nmod;
    x = nx;
    y = ny;
  }
  long long ret = x;
  while (ret < sblen) ret += y;
  return ret;
}
void run() {
  scanf("%s", sa);
  salen = strlen(sa);
  printf("%lld\n", solve());
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) run();
  return 0;
}
