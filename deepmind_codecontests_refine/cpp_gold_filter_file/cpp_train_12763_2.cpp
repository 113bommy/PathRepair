#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  bool zf = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    zf = 1;
  else
    res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + c - '0';
  return (zf ? -res : res);
}
int dta[1000005], gb[2000005], cnta, cntb;
long long vala, valb;
long long ans;
int wh;
signed main() {
  int n = read();
  for (register int i = 1; i <= n; ++i) {
    dta[i] = read();
    if (i >= dta[i])
      ++cnta, vala += i - dta[i];
    else
      ++gb[dta[i] - i], ++cntb, valb += dta[i] - i;
  }
  ans = vala + valb, wh = 0;
  for (register int i = 1; i < n; ++i) {
    vala += cnta, cnta += gb[i];
    valb -= cntb, cntb -= gb[i];
    int x = dta[n - i + 1];
    vala -= n + 1 - x, --cnta;
    if (x > 1)
      ++gb[x - 1 + i], valb += x - 1, ++cntb;
    else
      ++cnta;
    if (vala + valb < ans) ans = vala + valb, wh = i;
  }
  printf("%lld %d\n", ans, wh);
  return 0;
}
