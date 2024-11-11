#include <bits/stdc++.h>
using namespace std;
namespace iB {
char buf[1 << 21], *p1 = buf, *p2 = buf;
}
namespace oB {
char buf[1 << 21], *p1 = buf, *p2 = buf + (1 << 21);
}
namespace Fastio {
struct Reader {
  char endch;
  Reader() { endch = '\0'; }
  Reader& operator>>(char& ch) {
    ch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                        fread(iB::buf, 1, 1 << 21, stdin),
                               iB::p1 == iB::p2)
              ? EOF
              : *iB::p1++);
    while (ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t')
      ch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                          fread(iB::buf, 1, 1 << 21, stdin),
                                 iB::p1 == iB::p2)
                ? EOF
                : *iB::p1++);
    return *this;
  }
  Reader& operator>>(char* str) {
    while (((*str = (iB::p1 == iB::p2 &&
                             (iB::p2 = (iB::p1 = iB::buf) +
                                       fread(iB::buf, 1, 1 << 21, stdin),
                              iB::p1 == iB::p2)
                         ? EOF
                         : *iB::p1++)) == ' ' ||
            *str == '\n' || *str == '\r' || *str == '\t') &&
           *str != EOF)
      ;
    while ((*++str = (iB::p1 == iB::p2 &&
                              (iB::p2 = (iB::p1 = iB::buf) +
                                        fread(iB::buf, 1, 1 << 21, stdin),
                               iB::p1 == iB::p2)
                          ? EOF
                          : *iB::p1++)) != ' ' &&
           *str != '\n' && *str != '\r' && *str != '\t' && *str != EOF)
      ;
    *str = '\0';
    return *this;
  }
  template <typename Int>
  Reader& operator>>(Int& d) {
    bool flag = 0;
    endch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                           fread(iB::buf, 1, 1 << 21, stdin),
                                  iB::p1 == iB::p2)
                 ? EOF
                 : *iB::p1++);
    while ((!isdigit(endch)) && endch != '-' && endch != EOF)
      endch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                             fread(iB::buf, 1, 1 << 21, stdin),
                                    iB::p1 == iB::p2)
                   ? EOF
                   : *iB::p1++);
    if (endch == '-')
      flag = 1,
      endch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                             fread(iB::buf, 1, 1 << 21, stdin),
                                    iB::p1 == iB::p2)
                   ? EOF
                   : *iB::p1++);
    d = endch & 15;
    while (isdigit(endch = (iB::p1 == iB::p2 &&
                                    (iB::p2 = (iB::p1 = iB::buf) +
                                              fread(iB::buf, 1, 1 << 21, stdin),
                                     iB::p1 == iB::p2)
                                ? EOF
                                : *iB::p1++)))
      d = (d << 3) + (d << 1) + (endch & 15);
    if (flag) d = -d;
    return *this;
  }
  template <typename T>
  inline T get() {
    T Val;
    (*this) >> Val;
    return Val;
  }
};
struct Writer {
  ~Writer() { fwrite(oB::buf, 1, oB::p1 - oB::buf, stdout); }
  Writer& operator<<(const char ch) {
    ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
     *oB::p1++ = ch);
    return *this;
  }
  Writer& operator<<(const char* ch) {
    while (*ch)
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = *(ch++));
    return *this;
  }
  Writer& operator<<(char* ss) { return *this << (const char*)ss; }
  template <typename Int>
  Writer& operator<<(Int x) {
    static char buffer[33];
    static int top = 0;
    if (!x) {
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = '0');
      return *this;
    }
    if (x < 0)
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = '-'),
          x = -x;
    while (x) {
      buffer[++top] = '0' | (x % 10);
      x /= 10;
    }
    while (top)
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = buffer[top--]);
    return *this;
  }
};
}  // namespace Fastio
Fastio::Reader kin;
Fastio::Writer kout;
const int N = 1e5 + 7;
int n, m;
int d[N], h[N];
long long s[N << 1];
long long up[N << 1], dn[N << 1];
namespace tr {
long long mx_up[N << 3], mn_dn[N << 3], mxd[N << 3];
void build(int u, int l, int r) {
  if (l == r) {
    mx_up[u] = up[l];
    mn_dn[u] = dn[l];
    mxd[u] = 0;
    return;
  }
  int mid = (l + r) >> 1, ls = u << 1, rs = ls | 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  mx_up[u] = max(mx_up[ls], mx_up[rs]);
  mn_dn[u] = min(mn_dn[ls], mn_dn[rs]);
  mxd[u] = max(mx_up[rs] - mn_dn[ls], max(mxd[ls], mxd[rs]));
}
long long mn_dn_now;
long long __query(int u, int l, int r, int ml, int mr) {
  if (l >= ml && r <= mr) {
    long long res = max(mxd[u], mx_up[u] - mn_dn_now);
    mn_dn_now = min(mn_dn_now, mn_dn[u]);
    return res;
  }
  long long res = 0;
  int mid = (l + r) >> 1, ls = u << 1, rs = ls | 1;
  if (mid >= ml) res = __query(ls, l, mid, ml, mr);
  if (mid < mr) res = max(res, __query(rs, mid + 1, r, ml, mr));
  return res;
}
long long query(int l, int r) {
  mn_dn_now = 0x3f3f3f3f3f3f3f3f;
  return __query(1, 1, 2 * n, l, r);
}
}  // namespace tr
signed main() {
  kin >> n >> m;
  for (int i = 1; i <= n; ++i) kin >> d[i];
  for (int i = 1; i <= n; ++i) kin >> h[i];
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + d[i - 1];
  s[n + 1] = s[n] + d[n];
  for (int i = n + 2; i <= 2 * n; ++i) s[i] = s[i - 1] + d[i - n - 1];
  for (int i = 1; i <= n; ++i) {
    dn[i] = s[i] - h[i] * 2;
    up[i] = s[i] + h[i] * 2;
  }
  for (int i = n + 1; i <= 2 * n; ++i) {
    dn[i] = s[i] - h[i - n] * 2;
    up[i] = s[i] + h[i - n] * 2;
  }
  tr::build(1, 1, 2 * n);
  for (int i = 1, a, b; i <= m; ++i) {
    kin >> a >> b;
    if (a <= b)
      kout << tr::query(b + 1, n + a - 1) << '\n';
    else
      kout << tr::query(b + 1, a - 1) << '\n';
  }
  return 0;
}
