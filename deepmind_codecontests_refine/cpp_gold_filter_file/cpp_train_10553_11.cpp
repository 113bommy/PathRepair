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
    c = Getchar();
    rev |= c == '-';
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
const int N = 1000005, M = 100005, mod = 1e9 + 7;
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
int n, m, f[N][10];
char a[N], b[N];
inline int calc(char a) { return (a == 'G') + (a == 'B') * 2; }
inline int get(int l, int r, int x) {
  if (l > r) return 0;
  int t = calc(a[x]) + calc(a[x - 1]) * 3, res = r - l + 1;
  if (x != 1 && a[x] != a[x - 1]) res -= f[r][t] - f[l - 1][t];
  return res;
}
int main() {
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (int i = 2; i <= m; i++) {
    memcpy(f[i], f[i - 1], sizeof(f[i]));
    f[i][calc(b[i]) * 3 + calc(b[i - 1])]++;
  }
  int l = 1, r = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (l <= m && a[i - 1] == b[l]) l++;
    r = min(r + 1, m + 1);
    while (r <= m && a[i] != b[r - 1]) r++;
    ans += get(l, r - 1, i);
  }
  print(ans);
  return 0;
}
