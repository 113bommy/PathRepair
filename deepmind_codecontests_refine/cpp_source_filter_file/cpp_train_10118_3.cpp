#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
int n, fa[MAXN], dep[MAXN], f[MAXN];
std ::vector<int> t[MAXN];
int stk[1000005], tp;
signed main() {
  read(n);
  read(fa + 1, fa + n);
  for (int i = (1); i < (n); ++i)
    t[fa[i]].push_back(i), dep[i] = dep[fa[i]] + 1;
  for (int i = (n - 1); i >= (0); --i) chmax(f[fa[i]], f[i] = mx(f[i], dep[i]));
  int rt = 0;
  sprint(0);
  for (int i = (1); i < (n); ++i) {
    const int siz = t[rt].size();
    if (siz == 1) {
      sprint(rt = t[rt][0]);
      continue;
    }
    std ::sort(t[rt].begin(), t[rt].end(),
               [](int x, int y) { return f[x] > f[y]; });
    for (int j = (0); j < (siz - 1); ++j) {
      const int x = t[rt].back();
      t[rt].pop_back();
      const int y = t[rt].back();
      ++f[stk[++tp] = x];
      fa[x];
      t[y].push_back(x);
    }
    sprint(rt = t[rt][0]);
  }
  putcha(10);
  print(tp);
  std ::reverse(stk + 1, stk + tp + 1);
  print(stk + 1, stk + tp + 1);
}
