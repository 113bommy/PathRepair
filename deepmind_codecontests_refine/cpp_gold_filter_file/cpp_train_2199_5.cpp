#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, a[2005][2005], dp[2005][2005], pw[2005], fac[2005], b[2005],
    sum, ans, mod = 998244353;
struct bit {
  int a[2005];
  void init() { memset(a, 0, sizeof(a)); }
  void add(int x) {
    int i;
    for (i = x; i <= n; i += (i & -i)) {
      a[i]++;
    }
  }
  int query(int x) {
    int i, s = 0;
    for (i = x; i; i -= (i & -i)) {
      s += a[i];
    }
    return s;
  }
} t1, t2;
void init() {
  int i, j;
  fac[0] = 1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  dp[1][0] = 1;
  for ((i) = (2); (i) <= (n); (i)++) {
    dp[i][0] = fac[i];
    for (((j)) = (1); ((j)) <= ((i)); ((j))++) {
      dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1] + mod) % mod;
    }
  }
  pw[0] = 1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    pw[i] = 1ll * pw[i - 1] * dp[n][n] % mod;
  }
}
void ins(int x) {
  if (++b[x] == 2) t2.add(x);
}
int main() {
  read(n);
  init();
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) read(a[i][j]);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    sum =
        (sum + 1ll * fac[n - i] * (a[1][i] - 1 - t1.query(a[1][i] - 1) + mod)) %
        mod;
    t1.add(a[1][i]);
  }
  ans = 1ll * sum * pw[n - 1] % mod;
  for ((i) = (2); (i) <= (n); (i)++) {
    t1.init();
    t2.init();
    sum = 0;
    memset((b), (0), (sizeof((b))));
    for (((j)) = ((n)); ((j)) >= (1); ((j))--) {
      ins(a[i][j]);
      ins(a[i - 1][j]);
      t1.add(a[i][j]);
      int x = t2.query(a[i][j] - 1), y = t1.query(a[i][j] - 1) - x,
          z = t2.query(n);
      if (b[a[i - 1][j]] == 2 && a[i - 1][j] < a[i][j]) x--;
      if (b[a[i - 1][j]] == 2) z--;
      sum = (sum + 1ll * dp[n - j][z - 1] * x) % mod;
      sum = (sum + 1ll * dp[n - j][z] * y) % mod;
    }
    ans = (ans + 1ll * sum * pw[n - i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
