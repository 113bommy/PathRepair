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
int n, m, tot;
const int N = 1e5 + 5;
struct UnionFindSet {
  int fa[N + 5];
  UnionFindSet() { memset(fa, -1, sizeof(fa)); }
  void reset() { memset(fa, -1, sizeof(fa)); }
  int find(int u) { return fa[u] < 0 ? u : fa[u] = find(fa[u]); }
  inline int get_size(int u) { return -fa[find(u)]; }
  inline bool is_family(int u, int v) { return find(u) == find(v); }
  inline bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (fa[u] > fa[v]) swap(u, v);
    fa[u] += fa[v];
    fa[v] = u;
    return true;
  }
} ufs;
int f[N];
int stk[N], h, t = 1;
int v[N], w[N], sum[N];
int g[N];
inline bool check(int x) {
  for (; x; x /= 10)
    if (x % 10 != 4 && x % 10 != 7) return false;
  return true;
}
int vis[N];
int main() {
  kin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    kin >> x >> y;
    ufs.merge(x, y);
  }
  for (int i = 1; i <= n; ++i) {
    if (ufs.find(i) == i) {
      int siz = ufs.get_size(i);
      if (!vis[siz]) {
        w[++tot] = siz;
        vis[siz] = true;
      }
      ++sum[siz];
    }
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= tot; ++i) {
    for (int r = 0; r < w[i]; ++r) {
      h = 0, t = 1;
      g[1] = 1 << 30;
      for (int k = 0; k * w[i] + r <= n; ++k) {
        int tmp = f[k * w[i] + r] - k;
        while (h < t && k - stk[h + 1] > sum[w[i]]) ++h;
        f[k * w[i] + r] = min(f[k * w[i] + r], g[h + 1] + k);
        while (h < t && g[t] >= tmp) --t;
        stk[++t] = k;
        g[t] = tmp;
      }
    }
  }
  int ans = 1 << 30;
  for (int i = 1; i <= n; ++i)
    if (check(i) && f[i] <= n) ans = min(ans, f[i]);
  if (ans > n)
    kout << "-3\n";
  else
    kout << ans - 1 << '\n';
  return 0;
}
