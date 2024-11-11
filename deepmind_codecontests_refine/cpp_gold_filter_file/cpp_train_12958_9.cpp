#include <bits/stdc++.h>
using namespace std;
long long gi() {
  long long res = 0, fh = 1;
  char ch = getchar();
  while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return fh * res;
}
long long gl() {
  long long res = 0, fh = 1;
  char ch = getchar();
  while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return fh * res;
}
long long n;
long long s1, s2, s3, s4;
long long x, y;
signed main() {
  n = gi();
  s1 = -(1ll << 62);
  s2 = (1ll << 62);
  s3 = -(1ll << 62);
  s4 = (1ll << 62);
  while (n--) {
    x = gi(), y = gi();
    s1 = max(x + y, s1);
    s2 = min(x + y, s2);
    s3 = max(x - y, s3);
    s4 = min(x - y, s4);
  }
  printf("%lld\n", s1 - s2 + s3 - s4 + 4);
  return 0;
}
