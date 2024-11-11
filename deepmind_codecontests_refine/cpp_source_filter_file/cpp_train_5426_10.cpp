#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 998244353;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) re = re * x % p;
  return re;
}
int n;
int a[300005];
struct ST {
  int lg[300005];
  int val[300005];
  int st[300005][20];
  inline int Max(int x, int y) {
    if (val[x] < val[y]) return y;
    return x;
  }
  ST() {
    lg[1] = 0;
    for (int i = 2; i <= 300000; i++) lg[i] = lg[i >> 1] + 1;
  }
  void build(int* x, int n, int type) {
    for (int i = 1; i <= n; i++) val[i] = x[i] * type;
    for (int i = 1; i <= n; i++) st[i][0] = i;
    for (int i = 1; i < 20; i++)
      for (int j = 1; j + (1 << i) - 1 <= n; j++)
        st[j][i] = Max(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
  }
  inline int ask(int l, int r) {
    int len = lg[r - l + 1];
    return Max(st[l][len], st[r - (1 << len) + 1][len]);
  }
} L0, R0;
int l_lim[300005], r_lim[300005];
int l[300005][20], r[300005][20];
int main() {
  read(n);
  if (n == 1) return printf("0"), 0;
  for (int i = 1; i <= n; i++) read(a[i]), a[n + i] = a[n + n + i] = a[i];
  for (int i = 1; i <= n * 3; i++)
    l_lim[i] = max(1, i - a[i]), r_lim[i] = min(n * 3, i + a[i]);
  L0.build(l_lim, n * 3, -1);
  R0.build(r_lim, n * 3, 1);
  for (int i = 1; i <= n * 3; i++) l[i][0] = l_lim[i], r[i][0] = r_lim[i];
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n * 3; j++) {
      int L = L0.ask(l[j][i - 1], r[j][i - 1]);
      int R = R0.ask(l[j][i - 1], r[j][i - 1]);
      l[j][i] = min(l[L][i - 1], l[R][i - 1]);
      r[j][i] = max(r[L][i - 1], r[R][i - 1]);
    }
  for (int i = n + 1; i <= n + n; i++) {
    int ans = 0;
    int x = i, y = i;
    for (int j = 20 - 1; j >= 0; j--) {
      if (max(r[x][j], r[y][j]) - min(l[x][j], l[y][j]) + 1 >= n) continue;
      int tx = x, ty = y;
      x = L0.ask(l[tx][j], r[tx][j]);
      y = R0.ask(l[tx][j], r[tx][j]);
      ans += (1 << j);
    }
    printf("%d ", ans + 1);
  }
  return 0;
}
