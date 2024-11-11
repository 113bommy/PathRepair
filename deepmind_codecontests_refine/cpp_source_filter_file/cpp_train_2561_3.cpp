#include <bits/stdc++.h>
using namespace std;
namespace IO {
static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
inline char myGetchar() {
  static char buf[IN_BUF], *ps = buf, *pt = buf;
  if (ps == pt) {
    ps = buf;
    pt = buf + fread(buf, 1, IN_BUF, stdin);
  }
  return ps == pt ? EOF : *ps++;
}
template <typename T>
inline bool readn(T &x) {
  bool op = 0;
  char ch = getchar();
  x = 0;
  for (; !isdigit(ch) && ch != EOF; ch = getchar()) op ^= (ch == '-');
  if (ch == EOF) return false;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ '0');
  if (op) x = -x;
  return true;
}
inline int readStr(char *s) {
  int n = 0;
  char ch = getchar();
  for (; isspace(ch) && ch != EOF; ch = getchar())
    ;
  for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
  s[n] = '\0';
  return n;
}
inline void myPutchar(char x) {
  static char pbuf[OUT_BUF], *pp = pbuf;
  struct _flusher {
    ~_flusher() { fwrite(pbuf, 1, pp - pbuf, stdout); }
  };
  static _flusher outputFlusher;
  if (pp == pbuf + OUT_BUF) {
    fwrite(pbuf, 1, OUT_BUF, stdout);
    pp = pbuf;
  }
  *pp++ = x;
}
template <typename T>
inline void print_(T x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  std::vector<int> num;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  for (; x; x /= 10) num.push_back(x % 10);
  while (!num.empty()) {
    putchar(num.back() ^ '0');
    num.pop_back();
  }
}
template <typename T>
inline void print(T x, char ch = '\n') {
  print_(x);
  putchar(ch);
}
inline void printStr_(const char *s, int n = -1) {
  if (n == -1) n = strlen(s);
  for (int i = 0; i < n; ++i) putchar(s[i]);
}
inline void printStr(const char *s, int n = -1, char ch = '\n') {
  printStr_(s, n);
  putchar(ch);
}
}  // namespace IO
using namespace IO;
void rd() {}
const int N = 1e5 + 9;
const long long mod = 1e9 + 7;
int T, n, m, k;
vector<int> v[N];
int q, lg[N], lev[N], fa[N][25];
void init() {
  lg[0] = -1;
  for (int i = 1; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
}
void predfs(int nowp, int father) {
  fa[nowp][0] = father;
  lev[nowp] = lev[father] + 1;
  for (int i = 1; i <= lg[lev[nowp]]; ++i)
    fa[nowp][i] = fa[fa[nowp][i - 1]][i - 1];
  for (int i = 0; i < v[nowp].size(); ++i) {
    int to = v[nowp][i];
    if (to == father) continue;
    predfs(to, nowp);
  }
  return;
}
int LCA(int x, int y) {
  if (lev[x] < lev[y]) swap(x, y);
  int k = lev[y] - lev[x];
  while (lev[x] != lev[y]) {
    int k = lev[y] - lev[x];
    x = fa[x][lg[k]];
  }
  if (x == y) return x;
  for (int i = lg[lev[x]]; i >= 0; --i) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}
int getdis(int x, int y) { return lev[x] + lev[y] - 2 * lev[LCA(x, y)]; }
int cal(int a, int b, int c) {
  return (getdis(a, b) + getdis(a, c) - getdis(b, c)) / 2 + 1;
}
int main() {
  rd();
  for (T = 1; T; T--) {
    readn(n);
    readn(q);
    init();
    for (int i = 2; i <= n; ++i) {
      int x;
      readn(x);
      v[x].push_back(i);
    }
    predfs(1, 0);
    for (int i = 1; i <= q; ++i) {
      int a, b, c, ans = 0;
      readn(a);
      readn(b);
      readn(c);
      ans = max(ans, cal(a, b, c));
      ans = max(ans, cal(a, c, b));
      ans = max(ans, cal(b, c, a));
      printf("%d\n", ans);
    }
  }
  return 0;
}
