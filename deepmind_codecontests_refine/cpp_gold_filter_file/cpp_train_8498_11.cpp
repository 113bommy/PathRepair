#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b;
} p[100010];
inline bool cmp(node a, node b) {
  return (a.b < b.b || (a.b == b.b && a.a > b.a));
}
int n, H, l, r, f[100010], ans, t[1010];
inline int cal(int i, int x) {
  int l = ::l, r = ::r;
  l -= i % x;
  r -= i % x;
  i -= i % x;
  if (i >= r)
    return r / x - (l - 1) / x;
  else if (i >= l && i <= r)
    return i / x - (l - 1) / x;
  return 0;
}
inline void modify(int f[], int W, int x, int fl) {
  static int F[100010], g[100010];
  for (int i = 0; i <= W; i++) g[i] = -999999999;
  for (int i = 0; i < W; i++) {
    int first = 1, last = 0;
    for (int j = i; j <= H; j += W) {
      while (first <= last && F[first] < j - W * x) first++;
      g[j] = f[j];
      if (first <= last) {
        g[j] = max(g[j], f[F[first]] + fl * cal(j, W) - fl * cal(F[first], W));
      }
      while (first <= last &&
             f[F[last]] - fl * cal(F[last], W) <= f[j] - fl * cal(j, W))
        last--;
      F[++last] = j;
    }
  }
  int tmp = 0;
  for (int i = 0; i <= H; i++) f[i] = g[i];
}
int main() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].a), H += p[i].a;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
  int bbf = l;
  l = H - r;
  r = H - bbf;
  l = max(l, 0);
  int Q = 3;
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= H; i++) f[i] = -999999999;
  for (int i = 1; p[i].b == 0 && i <= n; i++)
    if (p[i].a <= Q) t[p[i].a]++;
  for (int i = 1; i <= Q; i++) modify(f, i, t[i], 0);
  for (int i = 1; p[i].b == 0 && i <= n; i++)
    if (p[i].a > Q) {
      for (int j = H; j >= p[i].a; j--)
        f[j] = max(f[j], f[j - p[i].a] + p[i].b * (j >= l && j <= r));
    }
  memset(t, 0, sizeof(t));
  for (int i = 1; i <= n; i++)
    if (p[i].b == 1 && p[i].a > Q) {
      for (int j = H; j >= p[i].a; j--)
        f[j] = max(f[j], f[j - p[i].a] + p[i].b * (j >= l && j <= r));
    }
  for (int i = 1; i <= n; i++)
    if (p[i].b == 1 && p[i].a <= Q) t[p[i].a]++;
  for (int i = Q; i >= 1; i--) modify(f, i, t[i], 1);
  int ans = 0;
  for (int i = 0; i <= H; i++) ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
