#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 10;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n;
int a[NR], b[NR], p[NR];
int num[NR], all;
int getid(int x) {
  int l = 1, r = all, res = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (num[mid] <= x)
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return res;
}
struct BIT {
  int c[NR];
  int lowbit(int x) { return x & -x; }
  void init() { memset(c, 0, sizeof(c)); }
  void add(int x, int v) {
    while (x <= n) Max(c[x], v), x += lowbit(x);
  }
  int query(int x) {
    int res = 0;
    while (x) Max(res, c[x]), x -= lowbit(x);
    return res;
  }
} T;
int f[NR], g[NR], ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), a[i] -= i;
  for (int i = 1; i <= n; i++) p[i] = a[i];
  sort(p + 1, p + n + 1);
  p[0] = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    if (p[i] != p[i - 1]) num[++all] = p[i];
  for (int i = 1; i <= n; i++) b[i] = getid(a[i]);
  T.init();
  for (int i = 1; i <= n; i++) f[i] = T.query(b[i]) + 1, T.add(b[i], f[i]);
  T.init();
  for (int i = n; i >= 1; i--)
    g[i] = T.query((all - b[i] + 1)), T.add((all - b[i] + 1), g[i]);
  T.init();
  for (int i = 2; i <= n; i++)
    Max(ans, g[i] + T.query(b[i] + (num[b[i] + 1] == num[b[i]] + 1)) + 1),
        T.add(b[i - 1], f[i - 1]);
  for (int i = 2; i <= n; i++) Max(ans, g[i] + 1);
  for (int i = 1; i < n; i++) Max(ans, f[i] + 1);
  printf("%d\n", n - ans);
  return 0;
}
