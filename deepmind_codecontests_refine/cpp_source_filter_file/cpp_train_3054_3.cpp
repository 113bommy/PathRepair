#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
inline char gtx() {
  const int N = 4096;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}
template <typename T>
inline bool rit(T &x) {
  char c = 0;
  bool fg = 0;
  while (c = gtx(), (c < '0' && c != '-') || c > '9')
    if (c == EOF) return false;
  c == '-' ? (fg = 1, x = 0) : (x = c & 15);
  while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
  if (fg) x = -x;
  return true;
}
template <typename T, typename... Args>
inline bool rit(T &x, Args &...args) {
  return rit(x) && rit(args...);
}
struct outputter {
  char buffer[4112], *ptr = buffer, *end = buffer + 4096;
  template <typename T>
  inline void write(T x, char endc = '\n') {
    if (x < 0) *ptr = '-', ++ptr, x = -x;
    if (!x) *ptr = '0', ++ptr;
    char *s = ptr, c;
    T t;
    while (x) {
      t = x / 10;
      c = x - 10 * t + '0';
      *ptr = c, ++ptr, x = t;
    }
    char *f = ptr - 1;
    while (s < f) swap(*s, *f), ++s, --f;
    if (ptr > end)
      fwrite(buffer, sizeof(char), ptr - buffer, stdout), ptr = buffer;
    *ptr = endc, ++ptr;
  }
  template <typename T>
  inline void output(T x) {
    write(x, '\n');
  }
  template <typename T, typename... Args>
  inline void output(T x, Args... args) {
    write(x, ' ');
    output(args...);
  }
  template <typename... Args>
  inline void operator()(Args... args) {
    output(args...);
  }
  outputter() {}
  ~outputter() { fwrite(buffer, sizeof(char), ptr - buffer, stdout); }
} pit;
#pragma GCC diagnostic pop
int p, ind[666], oud[666];
vector<int> G[666];
int ways[666][666];
int mat[333][333];
int stid[666], edid[666];
bitset<666> vis[666];
void go(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  if (i == j)
    ways[i][j] = 1;
  else
    for (int z : G[i])
      go(z, j), ways[i][j] = (ways[i][j] + 1ll * ways[z][j]) % p;
}
int pw(int b, int n, int m, int a = 1) {
  while (n) {
    if (n & 1) a = 1ll * a * b % m;
    b = 1ll * b * b % m;
    n >>= 1;
  }
  return a;
}
int inv(int x) { return pw(x, p - 2, p); }
int32_t main() {
  int n, m, u, v;
  rit(n, m, p);
  while (m--) {
    rit(u, v);
    ++oud[u];
    ++ind[v];
    G[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) go(i, j);
  int z = 0;
  for (int i = 1; i <= n; ++i)
    if (!ind[i]) ++z;
  int inp = 0, oup = 0;
  for (int i = 1; i <= n; ++i)
    if (!ind[i]) stid[i] = ++inp;
  for (int i = 1; i <= n; ++i)
    if (!oud[i]) edid[i] = ++oup;
  for (int i = 1; i <= n; ++i)
    if (stid[i])
      for (int j = 1; j <= n; ++j)
        if (edid[j]) mat[stid[i]][edid[j]] = ways[i][j];
  n = z;
  int x = 1;
  for (int j = 1; j <= z; ++j) {
    if (!mat[j][j])
      for (int i = j; i <= n; ++i)
        if (mat[i][j]) {
          for (int jj = 1; jj <= n; ++jj) swap(mat[i][jj], mat[j][jj]);
          x = p - x;
          break;
        }
    if (!mat[j][j]) cout << 0 << endl, exit(0);
    for (int i = j + 1; i <= n; ++i) {
      if (!mat[i][j]) continue;
      int tar = p - mat[i][j];
      int mul = 1ll * tar * inv(mat[j][j]) % p;
      for (int jj = j; jj <= n; ++jj) {
        mat[i][jj] = (mat[i][jj] + 1ll * mat[j][jj] * mul) % p;
      }
    }
  }
  for (int i = 1; i <= n; ++i) x = 1ll * x * mat[i][i] % p;
  cout << x << endl;
}
