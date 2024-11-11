#include <bits/stdc++.h>
using namespace std;
const int h = 3, ki = 149, mo = 998244353;
int mod(int x) { return (x % mo + mo) % mo; }
int inc(int x, int k) {
  x += k;
  return x < mo ? x : x - mo;
}
int dec(int x, int k) {
  x -= k;
  return x >= 0 ? x : x + mo;
}
int ksm(int x, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1ll * ans * x % mo;
    k >>= 1;
    x = 1ll * x * x % mo;
  }
  return mod(ans);
}
int inv(int x) { return ksm(x, mo - 2); }
int read() {
  char ch = 0;
  int x = 0, flag = 1;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') flag = -1;
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  }
  return x * flag;
}
void write(int x) {
  if (!x) return (void)putchar(48);
  if (x < 0) putchar(45), x = -x;
  int len = 0, p[20];
  while (x) p[++len] = x % 10, x /= 10;
  for (int i = len; i >= 1; i--) putchar(p[i] + 48);
}
const double eps = 1e-7, inf = 1e9 + 7, pi = acos(-1);
double Read() {
  double x;
  scanf("%lf", &x);
  return x;
}
void Write(double x) { printf("%lf", x); }
struct edge {
  int to, nxt;
} e[1100000 * 2];
int num, head[1100000];
inline void add(int x, int y) {
  e[++num] = {y, head[x]};
  head[x] = num;
}
int dep[1100000];
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  for (int i = head[x]; i != -1; i = e[i].nxt) {
    int to = e[i].to;
    if (to == fa) continue;
    dfs(to, x);
  }
}
int main() {
  int n = read();
  num = -1;
  memset(head, -1, sizeof(head));
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  dfs(1, 1);
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += 1.0 / dep[i];
  printf("%.7lf", ans);
  return 0;
}
