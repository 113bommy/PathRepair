#include <bits/stdc++.h>
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, true : false;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline T read(T &x) {
  int sign = 1;
  char c = getchar_unlocked();
  for (; !isdigit(c); c = getchar_unlocked())
    if (c == '-') sign = -1;
  for (x = 0; isdigit(c); c = getchar_unlocked()) x = x * 10 + c - '0';
  return x *= sign;
}
template <class T>
inline void write(T x) {
  if (x == 0) {
    putchar_unlocked('0');
    return;
  }
  if (x < 0) {
    putchar_unlocked('-');
    x = -x;
  }
  static char s[20];
  int top = 0;
  for (; x; x /= 10) s[++top] = x % 10 + '0';
  while (top) putchar_unlocked(s[top--]);
}
const int maxN = 5000;
const int LogN = 40;
const int P = 7340033;
const int G = 3;
long long pwr(long long x, int k) {
  long long ret = 1;
  for (; k; k >>= 1, x = x * x % P)
    if (k & 1) ret = ret * x % P;
  return ret;
}
int a[LogN][maxN];
inline int gmod(int x) {
  if (x >= P) x -= P;
  return x;
}
namespace NTT {
int n, STEP, g, inv;
int rev[maxN];
int wn[maxN];
void init(int N) {
  for (n = 1, STEP = 0; n < N; n <<= 1, ++STEP)
    ;
  for (int i = 1; i < n; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (STEP - 1));
  g = pwr(G, (P - 1) / n);
  wn[0] = 1;
  for (int i = 1; i <= n; ++i) wn[i] = (long long)wn[i - 1] * g % P;
  inv = pwr(n, P - 2);
}
void dft(int a[], int flag) {
  for (int i = 0; i < n; ++i)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += (k << 1))
      for (int j = 0; j < k; ++j) {
        int w = flag == 1 ? wn[n / (k << 1) * j] : wn[n - n / (k << 1) * j];
        int x = a[i + j];
        int y = (long long)a[i + j + k] * w % P;
        a[i + j] = gmod(x + y);
        a[i + j + k] = gmod(x - y + P);
      }
  }
  if (flag == -1) {
    for (int i = 0; i < n; ++i) a[i] = (long long)a[i] * inv % P;
  }
}
}  // namespace NTT
void prework() {
  NTT::init(2000);
  a[0][0] = 1;
  for (int i = 1; i <= 32; ++i) {
    NTT::dft(a[i - 1], 1);
    for (int j = 0; j < NTT::n; ++j) {
      long long t = (long long)a[i - 1][j] * a[i - 1][j] % P;
      a[i][j] = t * t % P;
    }
    NTT::dft(a[i - 1], -1);
    NTT::dft(a[i], -1);
    for (int j = NTT::n - 1; j > 1000; --j) a[i][j] = 0;
    for (int j = 1000; j >= 1; --j) a[i][j] = a[i][j - 1];
  }
}
int main() {
  if (fopen("tmp.in", "r")) {
    freopen("tmp.in", "r", stdin);
    freopen("tmp.out", "w", stdout);
  }
  int Q, n, k;
  prework();
  read(Q);
  while (Q--) {
    read(n), read(k);
    int cnt = 0;
    for (; (n > 1) && (n & 1); n >>= 1) ++cnt;
    write(a[cnt][k]), putchar_unlocked('\n');
  }
  return 0;
}
