#include <bits/stdc++.h>
const int P = 998244353;
using namespace std;
template <typename T>
inline void ckmax(T &a, T b) {
  (a < b) && (a = b);
}
template <typename T>
inline void ckmin(T &a, T b) {
  (a > b) && (a = b);
}
inline int mul(int a, int b) { return 1ull * a * b % P; }
inline int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int sub(int a, int b) { return a - b >= 0 ? a - b : a - b + P; }
inline void mulmod(int &a, int b) { a = mul(a, b); }
inline void addmod(int &a, int b) { ((a += b) >= P) && (a -= P); }
inline void submod(int &a, int b) { ((a -= b) < 0) && (a += P); }
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline void fprint(const int &x, char c = ' ') {
  fprintf(stderr, "%d%c", x, c);
}
inline void fprint(const pair<int, int> &x, char c = '\n') {
  fprintf(stderr, "%d %d%c", x.first, x.second, c);
}
inline void fprint(const int *f, const int &n, char c = '\n') {
  for (int i = 1; i <= n; i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline void fprint(const vector<int> &f, char c = '\n') {
  for (int i = 0; i < (int)f.size(); i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline int inv(int a) { return ksm(a, P - 2); }
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
int bi = SIZE, bn = SIZE, opt;
int read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  int sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(int &x) {
  if (x) x = 0;
  int bf = 0, n = read(str);
  if (!n) return 0;
  int i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(int x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    int sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
  }
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void write(char x) {
  obuf[opt++] = x;
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void Fflush() {
  if (opt) fwrite(obuf, 1, opt, stdout);
  opt = 0;
}
};  // namespace FastIO
inline int read() {
  int x;
  FastIO::read(x);
  return x;
}
long long lowbit(long long x) { return x & -x; }
int n, K;
void print(int o) {
  printf(o ? "ACCEPTED\n" : "REJECTED\n");
  exit(0);
}
long long st[10], f[10][45], cnt[10];
void dfs(int u, long long cur) {
  if (u == K) {
    if (lowbit(cur + 1) != cur + 1) print(0);
    return;
  }
  int nowcnt = __builtin_popcountll(cur & st[u]);
  cur = cur & (~st[u]);
  for (int i = (nowcnt); i <= (nowcnt + cnt[u]); i++) {
    dfs(u + 1, cur | f[u][i]);
  }
}
signed main() {
  n = read(), K = read();
  long long all = 0;
  for (int i = (0); i <= (K - 1); i++) {
    int t = read();
    for (int j = (1); j <= (t); j++) {
      int x = read();
      st[i] |= (1ll << (x - 1));
      f[i][j] = st[i];
    }
    cnt[i] = __builtin_popcountll(st[i] ^ (all & st[i]));
    all |= st[i];
  }
  if (n == 1) print(1);
  if (all != (1ll << n) - 1) print(0);
  dfs(0, 0);
  print(1);
  return FastIO::Fflush(), 0;
}
