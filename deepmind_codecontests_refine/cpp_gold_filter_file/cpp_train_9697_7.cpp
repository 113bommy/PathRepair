#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T& x, T y) {
  x = (y > x ? y : x);
}
template <typename T>
inline void ckmin(T& x, T y) {
  x = (y < x ? y : x);
}
namespace Fread {
const int SIZE = 1 << 20;
char buf[SIZE], *S, *T;
inline char getchar() {
  if (S == T) {
    T = (S = buf) + fread(buf, 1, SIZE, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
}  // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 20;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
  fwrite(buf, 1, S - buf, stdout);
  S = buf;
}
inline void putchar(char c) {
  *S++ = c;
  if (S == T) flush();
}
struct _ {
  ~_() { flush(); }
} __;
}  // namespace Fwrite
template <typename T>
inline void read(T& x) {
  x = 0;
  int f = 1;
  char c = Fread::getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = Fread::getchar();
  }
  while (isdigit(c)) x = x * 10 + (c - '0'), c = Fread::getchar();
  x *= f;
}
template <typename T>
inline void write(T x, bool _enter = 0, bool _space = 0) {
  if (!x)
    Fwrite::putchar('0');
  else {
    if (x < 0) Fwrite::putchar('-'), x = -x;
    static char dig[41];
    int top = 0;
    while (x) dig[++top] = (x % 10) + '0', x /= 10;
    while (top) Fwrite::putchar(dig[top--]);
  }
  if (_enter) Fwrite::putchar('\n');
  if (_space) Fwrite::putchar(' ');
}
namespace Fastio {
struct reader {
  template <typename T>
  reader& operator>>(T& x) {
    ::read(x);
    return *this;
  }
  reader& operator>>(char& c) {
    c = Fread::getchar();
    while (c == '\n' || c == ' ') c = Fread::getchar();
    return *this;
  }
  reader& operator>>(char* str) {
    int len = 0;
    char c = Fread::getchar();
    while (c == '\n' || c == ' ') c = Fread::getchar();
    while (c != '\n' && c != ' ') str[len++] = c, c = Fread::getchar();
    str[len] = '\0';
    return *this;
  }
} cin;
const char endl = '\n';
struct writer {
  template <typename T>
  writer& operator<<(T x) {
    ::write(x, 0, 0);
    return *this;
  }
  writer& operator<<(char c) {
    Fwrite::putchar(c);
    return *this;
  }
  writer& operator<<(const char* str) {
    int cur = 0;
    while (str[cur]) Fwrite::putchar(str[cur++]);
    return *this;
  }
} cout;
}  // namespace Fastio
const int MOD = 998244353;
inline int mod1(int x) { return x < MOD ? x : x - MOD; }
inline int mod2(int x) { return x < 0 ? x + MOD : x; }
inline void add(int& x, int y) { x = mod1(x + y); }
inline void sub(int& x, int y) { x = mod2(x - y); }
inline int pow_mod(int x, int i) {
  int y = 1;
  while (i) {
    if (i & 1) y = (long long)y * x % MOD;
    x = (long long)x * x % MOD;
    i >>= 1;
  }
  return y;
}
const int MAXN = 2e5;
int n, K, a[MAXN + 5];
int f[4][MAXN + 5], dp[MAXN + 5][3];
void init(int maxlen) {
  f[0][1] = K;
  for (int i = 2; i <= maxlen; ++i)
    f[0][i] = (long long)f[0][i - 1] * (K - 1) % MOD;
  f[1][1] = K - 1;
  for (int i = 2; i <= maxlen; ++i)
    f[1][i] = (long long)f[1][i - 1] * (K - 1) % MOD;
  dp[1][0] = K - 1;
  dp[1][1] = 0;
  f[2][1] = K - 1;
  for (int i = 2; i <= maxlen; ++i) {
    dp[i][0] = ((long long)dp[i - 1][0] * (K - 2) +
                (long long)dp[i - 1][1] * (K - 1)) %
               MOD;
    dp[i][1] = dp[i - 1][0];
    f[2][i] = dp[i][0];
  }
  dp[1][0] = K - 2;
  dp[1][1] = 0;
  dp[1][2] = 1;
  f[3][1] = K - 2;
  for (int i = 2; i <= maxlen; ++i) {
    dp[i][0] = ((K > 3 ? (long long)dp[i - 1][0] * (K - 3) : 0LL) +
                (long long)dp[i - 1][1] * (K - 2) +
                (long long)dp[i - 1][2] * (K - 2)) %
               MOD;
    dp[i][1] = mod1(dp[i - 1][0] + dp[i - 1][2]);
    dp[i][2] = mod1(dp[i - 1][0] + dp[i - 1][1]);
    f[3][i] = mod1(dp[i][0] + dp[i][1]);
  }
}
int main() {
  Fastio::cin >> n >> K;
  for (int i = 1; i <= n; ++i) Fastio::cin >> a[i];
  for (int i = 1; i + 2 <= n; ++i) {
    if (a[i] != -1 && a[i] == a[i + 2]) {
      Fastio::cout << 0 << Fastio::endl;
      return 0;
    }
  }
  init((n + 1) / 2);
  int ans = 1;
  for (int i = 1; i <= n; i += 2) {
    if (a[i] != -1) continue;
    int j = i, len = 1;
    while (j + 2 <= n && a[j + 2] == -1) {
      j += 2;
      len++;
    }
    int t = -1;
    if (i - 2 < 1 && j + 2 > n)
      t = 0;
    else if (i - 2 < 1 || j + 2 > n)
      t = 1;
    else if (a[i - 2] == a[j + 2])
      t = 2;
    else
      t = 3;
    ans = (long long)ans * f[t][len] % MOD;
    i = j;
  }
  for (int i = 2; i <= n; i += 2) {
    if (a[i] != -1) continue;
    int j = i, len = 1;
    while (j + 2 <= n && a[j + 2] == -1) {
      j += 2;
      len++;
    }
    int t = -1;
    if (i - 2 < 1 && j + 2 > n)
      t = 0;
    else if (i - 2 < 1 || j + 2 > n)
      t = 1;
    else if (a[i - 2] == a[j + 2])
      t = 2;
    else
      t = 3;
    ans = (long long)ans * f[t][len] % MOD;
    i = j;
  }
  Fastio::cout << ans << Fastio::endl;
  return 0;
}
