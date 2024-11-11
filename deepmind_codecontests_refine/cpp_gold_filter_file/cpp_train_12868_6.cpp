#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0')
    ;
}
inline void read(long long &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0')
    ;
}
};  // namespace fastIO
LL a[100004], b[100004], l[100004], r[100004];
int main() {
  LL ans = 0x3f3f3f3f3f3f3f3f;
  int n;
  fastIO::read(n);
  for (int i = 1; i <= n; ++i) fastIO::read(a[i]), b[i] = a[i];
  for (int i = 2; i <= n; ++i) {
    if (a[i] <= a[i - 1])
      l[i] = l[i - 1] + 1 + a[i - 1] - a[i], a[i] = a[i - 1] + 1;
    else
      l[i] = l[i - 1];
  }
  for (int i = n - 1; i >= 1; --i) {
    if (b[i] <= b[i + 1])
      r[i] = r[i + 1] + 1 + b[i + 1] - b[i], b[i] = b[i + 1] + 1;
    else
      r[i] = r[i + 1];
  }
  for (int i = 1; i <= n; ++i)
    ans = min(ans, a[i] == b[i + 1] ? l[i] + r[i + 1] + 1 : l[i] + r[i + 1]);
  printf("%lld\n", ans);
  return 0;
}
