#include <bits/stdc++.h>
using namespace std;
char c[2100001], CH, buf[1 << 22], *p1 = buf, *p2 = buf;
static double f[2050001][2], l, r = 1, ans;
static int len, n;
string st;
static inline bool check(double sam);
int main() {
  CH = (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++;
  while (CH == 'L' || CH == 'R' || CH == 'X')
    c[++n] = CH,
    CH = (p1 == p2) &&
                 (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++;
  for (register int i = 1; i <= n; ++i) {
    st += c[i];
    if (c[i] != 'X' && c[i] == c[i + 1] && i + 1 <= n) {
      st += 'X';
    }
  }
  if (c[1] == c[n]) {
    if (c[1] == 'L') st = st + 'X';
    if (c[1] == 'R') st = 'X' + st;
  }
  len = st.size();
  for (register int i = 1; i <= 35; ++i) {
    register double mid = (l + r) / 2.0;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  register int x = (ans + (double)1e-9) * 1e8;
  printf("%d.%06d\n", x / 1000000, x % 1000000);
}
static inline bool check(register double sam) {
  f[0][0] = 0.0, f[0][1] = -sam;
  for (register int i = 0; i < len; ++i) {
    f[i + 1][0] = f[i][1] - sam;
    f[i + 1][1] = f[i][0] - sam;
    if (st[i] == 'L') f[i + 1][1] = f[i][0] + 1 - sam;
    if (st[i] == 'R') f[i + 1][0] = f[i][1] + 1 - sam;
    f[i + 1][0] = max(f[i + 1][0], f[i + 1][1] - sam);
    f[i + 1][1] = max(f[i + 1][1], f[i + 1][0] - sam);
  }
  return f[len][0] > 0;
}
