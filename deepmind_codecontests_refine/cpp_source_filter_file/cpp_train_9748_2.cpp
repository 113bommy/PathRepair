#include <bits/stdc++.h>
const double pi = 3.141592653589793238462643383279;
namespace MyMinMax {
template <typename T>
inline T mn(const T x, const T y) {
  return x < y ? x : y;
}
template <typename T>
inline T mx(const T x, const T y) {
  return x > y ? x : y;
}
template <typename T>
inline void chmin(T &x, const T y) {
  (x > y) && (x = y);
}
template <typename T>
inline void chmax(T &x, const T y) {
  (x < y) && (x = y);
}
template <typename T, typename... Args>
inline T mx(const T x, const Args... args) {
  return mx(x, mx(args...));
}
template <typename T, typename... Args>
inline T mn(const T x, const Args... args) {
  return mn(x, mn(args...));
}
}  // namespace MyMinMax
using namespace MyMinMax;
namespace IO {
const int DPAIRSIZ = 1 << 18;
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
inline char getcha() {
  return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT)
             ? EOF
             : *SS++;
}
template <typename T = int>
inline T read() {
  T x = 0;
  int fu = 1;
  char c = getcha();
  while (c > 57 || c < 48) {
    if (c == 45) fu = -1;
    c = getcha();
  }
  while (c <= 57 && c >= 48) {
    x = x * 10 + c - 48;
    c = getcha();
  }
  x *= fu;
  return x;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  int fu = 1;
  char c = getcha();
  while (c > 57 || c < 48) {
    if (c == 45) fu = -1;
    c = getcha();
  }
  while (c <= 57 && c >= 48) {
    x = x * 10 + c - 48;
    c = getcha();
  }
  x *= fu;
}
template <typename T>
inline void read(T *bg, T *ed) {
  while (bg != ed) read(*bg++);
}
inline void read(char &ch) {
  ch = getcha();
  while (ch <= 32) ch = getcha();
}
inline void read(char *s) {
  char ch = getcha();
  while (ch <= 32) ch = getcha();
  while (ch > 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
inline void sread(char *s) {
  char ch = getcha();
  while (ch < 32) ch = getcha();
  while (ch >= 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
inline void pread(char *&s) {
  char ch = getcha();
  while (ch <= 32) ch = getcha();
  while (ch > 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
inline void spread(char *&s) {
  char ch = getcha();
  while (ch < 32) ch = getcha();
  while (ch >= 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
char out[DPAIRSIZ], *Out = out;
inline void putcha(char x) {
  *Out++ = x;
  if (Out - out >= (DPAIRSIZ)) fwrite(out, 1, Out - out, stdout), Out = out;
}
template <typename T>
inline void fprint(T x) {
  if (x < 0) putcha(45), x = -x;
  if (x > 9) fprint(x / 10);
  putcha(x % 10 + 48);
}
inline void print() { putcha(10); }
template <typename T>
inline void print(T x) {
  fprint(x);
  putcha(10);
}
inline void print(char *ch) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
}
inline void put(char *ch) {
  while (*ch != '\0') putcha(*(ch++));
}
inline void print(const char *ch) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
}
inline void put(const char *ch) {
  while (*ch != '\0') putcha(*(ch++));
}
template <typename T, typename... Args>
inline void print(T x, Args... args) {
  fprint(x);
  putcha(32);
  print(args...);
}
template <typename... Args>
inline void print(const char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(32);
  print(args...);
}
template <typename... Args>
inline void print(char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(32);
  print(args...);
}
template <typename T, typename... Args>
inline void printl(T x, Args... args) {
  fprint(x);
  putcha(10);
  printl(args...);
}
template <typename... Args>
inline void printl(const char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
  printl(args...);
}
template <typename... Args>
inline void printl(char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
  printl(args...);
}
template <typename T>
inline void sprint(T x) {
  fprint(x);
  putcha(32);
}
template <typename T, typename... Args>
inline void sprint(T x, Args... args) {
  fprint(x);
  putcha(32);
  sprint(args...);
}
template <typename T>
inline void sprint(T *bg, T *ed) {
  while (bg != ed) sprint(*bg++);
}
template <typename T>
inline void print(T *bg, T *ed) {
  while (bg != ed) sprint(*bg++);
  putcha(10);
}
template <typename T>
inline void printl(T *bg, T *ed) {
  while (bg != ed) print(*bg++);
}
class AutoFlush {
 public:
  ~AutoFlush() { fwrite(out, 1, Out - out, stdout); }
} __AutoFlush;
}  // namespace IO
using namespace IO;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3fll;
int n, m, q;
const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN];
long long c[MAXN];
struct DPair {
  int e, val;
  DPair(int e, int val) : e(e), val(val) {}
};
std ::vector<DPair> d[MAXN];
long long t[MAXN << 2], tag[MAXN << 2];
inline void pushup(int rt) { t[rt] = mn(t[rt << 1], t[rt << 1 | 1]); }
inline void update(int rt, int z) {
  t[rt] += z;
  tag[rt] += z;
}
inline void pushdown(int rt) {
  if (tag[rt]) {
    update(rt << 1, tag[rt]);
    update(rt << 1 | 1, tag[rt]);
    tag[rt] = 0;
  }
}
void build(int rt, int l, int r) {
  if (l == r) return t[rt] = b[l], void();
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
void Build(int rt, int l, int r) {
  if (l == r) return t[rt] = c[l] + a[l], void();
  int mid = (l + r) >> 1;
  Build(rt << 1, l, mid);
  Build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
void modify(int rt, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return update(rt, z);
  pushdown(rt);
  int mid = (l + r) >> 1;
  if (x <= mid) modify(rt << 1, l, mid, x, y, z);
  if (y > mid) modify(rt << 1 | 1, mid + 1, r, x, y, z);
  pushup(rt);
}
void ins(int rt, int l, int r, int x) {
  if (l == r) return t[rt] = c[l] + a[l], void();
  int mid = (l + r) >> 1;
  x <= mid ? ins(rt << 1, l, mid, x) : ins(rt << 1 | 1, mid + 1, r, x);
  pushup(rt);
}
signed main() {
  read(n, m, q);
  for (int i = (1); i < (n); ++i) read(a[i], b[i + 1]);
  build(1, 1, n);
  while (m--) {
    int u, v, w;
    read(u, v, w);
    d[u].push_back(DPair(v, w));
  }
  for (int i = (1); i <= (n); ++i) {
    for (auto it : d[i]) modify(1, 1, n, 1, it.e, it.val);
    c[i] = t[1];
  }
  Build(1, 1, n);
  print(t[1]);
  while (q--) {
    int x, y;
    read(x, y);
    a[x] = y;
    ins(1, 1, n, x);
    print(t[1]);
  }
}
