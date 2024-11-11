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
inline bool chmin(T &x, const T y) {
  return (x > y) && ((x = y), 1);
}
template <typename T>
inline bool chmax(T &x, const T y) {
  return (x < y) && ((x = y), 1);
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
const int MAXN = 1e5 + 5;
int n, m, q, a[MAXN];
std ::multiset<int> s;
int b[MAXN];
int t[MAXN << 2];
inline void pushup(int rt) { t[rt] = mn(t[rt << 1], t[rt << 1 | 1]); }
void build(int rt, int l, int r) {
  t[rt] = INF;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
}
void modify(int rt, int l, int r, int x, int y) {
  chmin(t[rt], y);
  if (l == r) return;
  int mid = (l + r) >> 1;
  x <= mid ? modify(rt << 1, l, mid, x, y)
           : modify(rt << 1 | 1, mid + 1, r, x, y);
}
int query(int rt, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[rt];
  int mid = (l + r) >> 1;
  if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
  if (y <= mid) return query(rt << 1, l, mid, x, y);
  return mn(query(rt << 1, l, mid, x, y), query(rt << 1 | 1, mid + 1, r, x, y));
}
signed main() {
  read(n, q, m);
  read(a + 1, a + n + 1);
  int r = 0;
  for (int l = (1); l <= (n); ++l) {
    while (r <= n && (s.empty() || *(--s.end()) - *s.begin() <= q))
      s.emplace(a[++r]);
    b[l] = r;
    auto it = s.find(a[l]);
    s.erase(it);
  }
  build(1, 1, n + 1);
  modify(1, 1, n + 1, n + 1, 0);
  for (int i = (n); i >= (1); --i) {
    if (i + m > b[i]) continue;
    const int res = query(1, 1, n + 1, i + m, b[i]);
    if (res == INF) continue;
    modify(1, 1, n + 1, i, res + 1);
  }
  const int ans = query(1, 1, n + 1, 1, 1);
  print(ans == INF ? -1 : ans);
}
