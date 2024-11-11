#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void gmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <class T>
inline void gmax(T &x, const T &y) {
  if (x < y) x = y;
}
const int BufferSize = 1 << 16;
char buffer[BufferSize], *Bufferhead, *Buffertail;
bool Terminal;
inline char Getchar() {
  if (Bufferhead == Buffertail) {
    int l = fread(buffer, 1, BufferSize, stdin);
    if (!l) {
      Terminal = 1;
      return 0;
    }
    Buffertail = (Bufferhead = buffer) + l;
  }
  return *Bufferhead++;
}
template <class T>
inline bool read(T &x) {
  x = 0;
  char c = Getchar(), rev = 0;
  while (c < '0' || c > '9') {
    rev |= c == '-';
    c = Getchar();
    if (Terminal) return 0;
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = Getchar();
  if (c == '.') {
    c = Getchar();
    double t = 0.1;
    while (c >= '0' && c <= '9')
      x = x + (c - '0') * t, c = Getchar(), t = t / 10;
  }
  x = rev ? -x : x;
  return 1;
}
template <class T1, class T2>
inline bool read(T1 &x, T2 &y) {
  return read(x) & read(y);
}
template <class T1, class T2, class T3>
inline bool read(T1 &x, T2 &y, T3 &z) {
  return read(x) & read(y) & read(z);
}
template <class T1, class T2, class T3, class T4>
inline bool read(T1 &x, T2 &y, T3 &z, T4 &w) {
  return read(x) & read(y) & read(z) & read(w);
}
inline bool reads(char *x) {
  char c = Getchar();
  while (c < 33 || c > 126) {
    c = Getchar();
    if (Terminal) return 0;
  }
  while (c >= 33 && c <= 126) (*x++) = c, c = Getchar();
  *x = 0;
  return 1;
}
template <class T>
inline void print(T x, const char c = '\n') {
  if (!x) {
    putchar('0');
    putchar(c);
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int m = 0, a[20];
  while (x) a[m++] = x % 10, x /= 10;
  while (m--) putchar(a[m] + '0');
  putchar(c);
}
const int inf = 0x3f3f3f3f;
const int N = 200005, M = 100005, mod = 1e9 + 7;
template <class T, class S>
inline void ch(T &x, const S y) {
  x = (x + y) % mod;
}
inline int exp(int x, int y, const int mod = ::mod) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = (long long)ans * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ans;
}
int n, pw[N], x[N], y[N], xx[N], yy[N];
vector<int> g[N];
bool vis[N];
int edg, si;
void dfs(int x) {
  vis[x] = 1;
  si++;
  for (int y : g[x]) {
    edg++;
    if (!vis[y]) dfs(y);
  }
}
int main() {
  scanf("%d", &n);
  pw[0] = 1;
  for (int i = 1; i <= n * 2; i++) pw[i] = pw[i - 1] * 2 % mod;
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &x[i], &y[i]), xx[i] = x[i], yy[i] = y[i];
  sort(xx + 1, xx + n + 1);
  sort(yy + 1, yy + n + 1);
  for (int i = 1; i <= n; i++) {
    x[i] = lower_bound(xx + 1, xx + n + 1, x[i]) - xx;
    y[i] = lower_bound(yy + 1, yy + n + 1, y[i]) - yy;
    g[x[i]].push_back(y[i] + n);
    g[y[i] + n].push_back(x[i]);
  }
  int ans = 1;
  for (int i = 1; i <= n * 2; i++)
    if (!vis[i]) {
      edg = si = 0;
      dfs(i);
      if (edg / 2 >= si)
        ans = (long long)ans * pw[si] % mod;
      else
        ans = (long long)ans * (pw[si] - 1) % mod;
    }
  printf("%d\n", ans);
  return 0;
}
