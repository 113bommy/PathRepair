#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool cmax(T &a, T b) {
  return (a < b) ? a = b, 1 : 0;
}
template <typename T>
bool cmin(T &a, T b) {
  return (a > b) ? a = b, 1 : 0;
}
template <typename T>
T read() {
  T ans = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch))
    ans = (ans << 3) + (ans << 1) + (ch - '0'), ch = getchar();
  return ans * f;
}
template <typename T>
void write(T x, char y) {
  if (x == 0) {
    putchar('0'), putchar(y);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  static char wr[20];
  int top = 0;
  for (; x; x /= 10) wr[++top] = x % 10 + '0';
  while (top) putchar(wr[top--]);
  putchar(y);
}
void file() {}
const int N = 1e5 + 5;
char x[N], y[N];
int a, b, c, d;
void input() {
  scanf("%s%s", x + 1, y + 1);
  a = read<int>(), b = read<int>(), c = read<int>(), d = read<int>();
}
const int mo = 1e9 + 7;
void add(int &x, int y) {
  x += y;
  x -= (x >= mo ? mo : 0);
}
namespace sub1 {
int len;
int mc[N], inv[N];
long long C(int x, int y) {
  if (x < y || x < 0 || y < 0) return 0;
  return 1ll * mc[x] * inv[y] % mo * inv[x - y] % mo;
}
int cal(int ra, int rb, int rc, int rd, int last) {
  if (!last && rc >= rb && rc - rb <= 1) {
    if (rb == -1 && rd == 0 && b <= 1) return 1;
    return C(rd + rb, rb) * C(ra + rc, rc) % mo;
  } else if (last && rb >= rc && rb - rc <= 1) {
    if (rc == -1 && ra == 0 && (c <= 1)) return 1;
    return C(rd + rb, rb) * C(ra + rc, rc) % mo;
  } else
    return 0;
}
int DP(int now, int ra, int rb, int rc, int rd, int du, int zero, int last,
       char *s) {
  if (len - a - b - c - d <= 0) return 0;
  if (now > len) {
    if (!zero && !ra && !rb && !rc && !rd) return 1;
    return 0;
  }
  if (!du && !zero) {
    return last ? cal(ra, rb, rc - 1, rd, last) : cal(ra, rb - 1, rc, rd, last);
  }
  int res = 0;
  int up = du ? s[now] - '0' : 1;
  if (now < len - a - b - c - d) {
    return DP(now + 1, ra, rb, rc, rd, du & (up == 0), 1, 0, s);
  } else if (now == len - a - b - c - d) {
    if (1 <= up) return DP(now + 1, ra, rb, rc, rd, du & (up == 1), 0, 1, s);
    return 0;
  }
  if (last == 0) {
    if (ra && 0 <= up)
      add(res, DP(now + 1, ra - 1, rb, rc, rd, du & (up == 0), 0, 0, s));
    if (rb && 1 <= up)
      add(res, DP(now + 1, ra, rb - 1, rc, rd, du & (up == 1), 0, 1, s));
  } else {
    if (rc && 0 <= up)
      add(res, DP(now + 1, ra, rb, rc - 1, rd, du & (up == 0), 0, 0, s));
    if (rd && 1 <= up)
      add(res, DP(now + 1, ra, rb, rc, rd - 1, du & (up == 1), 0, 1, s));
  }
  return res;
}
long long power(long long x, int y) {
  long long res = 1;
  for (; y; x = x * x % mo, y >>= 1)
    if (y & 1) res = res * x % mo;
  return res;
}
void solve() {
  len = strlen(y + 1);
  mc[0] = inv[0] = 1;
  for (register int i = (int)(1); i <= (int)(len); ++i)
    mc[i] = 1ll * mc[i - 1] * i % mo;
  inv[len] = power(mc[len], mo - 2);
  for (register int i = (int)(len - 1); i >= (int)(1); --i)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mo;
  int res = DP(1, a, b, c, d, 1, 1, 0, y);
  len = strlen(x + 1);
  int now = len;
  while (x[now] == '0') x[now--] = '1';
  x[now] = '0';
  if (now == 1) {
    for (register int i = (int)(1); i <= (int)(len - 1); ++i) x[i] = x[i + 1];
    x[len--] = '\0';
  }
  res = (res - DP(1, a, b, c, d, 1, 1, 0, x) + mo) % mo;
  write(res, '\n');
}
}  // namespace sub1
void work() { sub1::solve(); }
int main() {
  file();
  input();
  work();
  return 0;
}
