#include <bits/stdc++.h>
clock_t t = clock();
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(register int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
int n;
int deg[402020];
struct hh {
  int t, nxt;
} edge[402020 << 1];
int head[402020], ecnt = 1;
int col[402020];
void make_edge(int f, int t) {
  edge[++ecnt] = (hh){t, head[f]};
  head[f] = ecnt;
  edge[++ecnt] = (hh){f, head[t]};
  head[t] = ecnt;
  ++deg[f], ++deg[t];
}
void dfs(int x) {
  for (int &i = head[x]; i; i = edge[i].nxt)
    if (!col[i >> 1]) {
      if (x < edge[i].t)
        col[i >> 1] = 1;
      else
        col[i >> 1] = 2;
      dfs(edge[i].t);
    }
}
int main() {
  file();
  read(n);
  int x, y;
  for (int i = (1); i <= (n); i++) read(x, y), make_edge(x, y + 200000);
  for (int i = (1); i <= (200000); i++)
    if (deg[i] & 1) make_edge(i, 200000 + 200000 + 1);
  for (int i = (200000 + 1); i <= (200000 + 200000); i++)
    if (deg[i] & 1) make_edge(i, 200000 + 200000 + 2);
  if (deg[200000 + 200000 + 1] & 1)
    make_edge(200000 + 200000 + 1, 200000 + 200000 + 2);
  for (int i = (1); i <= (200000 + 200000 + 2); i++) dfs(i);
  for (int i = (1); i <= (n); i++) printf(col[i] == 1 ? "b" : "r");
  return 0;
}
