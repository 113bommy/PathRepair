#include <bits/stdc++.h>
using namespace std;
const int maxn = 100011, maxN = 2011, P = 1000000007;
int n, m, N, s, T;
struct Tp {
  int x, y;
} p[maxN];
void init() {
  scanf("%d%d%d%d", &n, &m, &N, &s);
  for (int i = 1; i <= N; ++i) scanf("%d%d", &p[i].x, &p[i].y);
}
int power(int x, int t) {
  int ans = 1;
  for (; t; t >>= 1, x = 1LL * x * x % P)
    if (t & 1) ans = 1LL * ans * x % P;
  return ans;
}
int Fac[maxn], Inv[maxn], Ifa[maxn];
void preset() {
  sort(p + 1, p + N + 1, [](Tp a, Tp b) { return a.x + a.y < b.x + b.y; });
  if (p[1].x == 1 && p[1].y == 1)
    T = 1;
  else
    T = 0;
  if (!T) {
    p[++N].x = 1, p[N].y = 1;
    sort(p + 1, p + N + 1, [](Tp a, Tp b) { return a.x + a.y < b.x + b.y; });
  }
  int n = 100000;
  Fac[0] = 1;
  Ifa[0] = 1;
  Inv[1] = 1;
  Fac[1] = 1;
  Ifa[1] = 1;
  for (int i = 2; i <= n; ++i) {
    Inv[i] = 1LL * P / i * (P - Inv[P % i]) % P;
    Fac[i] = 1LL * Fac[i - 1] * i % P;
    Ifa[i] = 1LL * Ifa[i - 1] * Inv[i] % P;
  }
}
inline int Path(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  return 1LL * Fac[x2 - x1 + y2 - y1] * Ifa[x2 - x1] % P * Ifa[y2 - y1] % P;
}
int f[maxN][22], g[maxN][22];
inline void update(int &x, int a) {
  if ((x += a) >= P) x -= P;
}
void work() {
  preset();
  for (int i = N; i >= 1; --i)
    for (int j = 0; j <= 20; ++j) {
      f[i][j] = Path(p[i].x, p[i].y, n, m);
      for (int i1 = i + 1; i1 <= N; ++i1)
        update(f[i][j], (P - 1LL) * Path(p[i].x, p[i].y, p[i1].x, p[i1].y) % P *
                            f[i1][j] % P);
      if (j) update(f[i][j], P - g[i][j - 1]);
      g[i][j] = j ? (f[i][j] + g[i][j - 1]) % P : f[i][j];
    }
  int ans = 0;
  for (int j = 0, v = s; v != 1; v = (v + 1) / 2, ++j) {
    if (j >= T) update(ans, 1LL * f[1][j - T] * (v - 1) % P);
  }
  ans = ((1LL * ans * power(Path(1, 1, n, m), P - 2) % P + 1) % P + P) % P;
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
