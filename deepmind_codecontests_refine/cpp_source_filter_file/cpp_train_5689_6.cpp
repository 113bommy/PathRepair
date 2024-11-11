#include <bits/stdc++.h>
using namespace std;
const int V = 1000000;
const int mo = 998244353;
const int N = 35, M = 2005;
int n, top, C[N][N];
int a[N], P[M], q[M];
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
void init() {
  for (int i = (int)(0); i <= (int)(N - 1); i++) C[i][0] = 1;
  for (int i = (int)(1); i <= (int)(N - 1); i++)
    for (int j = (int)(1); j <= (int)(N - i); j++)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  for (int i = (int)(0); i <= (int)(N - 1); i++)
    for (int j = (int)(0); j <= (int)(i); j++)
      for (int k = (int)(j + 1); k <= (int)(i); k++)
        C[i][j] = 1ll * C[i][j] * (mo - V) % mo;
}
struct Poly {
  int a[N];
  Poly() { memset(a, 0, sizeof(a)); }
  Poly GF() {
    Poly ans;
    for (int i = (int)(1); i <= (int)(N - 1); i++)
      ans.a[i] = 1ll * a[i - 1] * power(i, mo - 2) % mo;
    return ans;
  }
  int F(int x) {
    int ans = 0;
    for (int i = (int)(N - 1); i >= (int)(0); i--)
      ans = (1ll * ans * x + a[i]) % mo;
    return ans;
  }
  Poly operator-(const Poly &b) const {
    Poly ans;
    for (int i = (int)(0); i <= (int)(N - 1); i++)
      ans.a[i] = (a[i] + mo - b.a[i]) % mo;
    return ans;
  }
  Poly tr() {
    Poly ans;
    for (int i = (int)(0); i <= (int)(N - 1); i++)
      for (int j = (int)(0); j <= (int)(i); j++)
        ans.a[j] = (ans.a[j] + 1ll * C[i][j] * a[i]) % mo;
    return ans;
  }
} f[M], g[M];
int main() {
  init();
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    double x;
    scanf("%lf", &x);
    a[i] = (int)(x * V + 0.49);
  }
  for (int i = (int)(n - 1); i >= (int)(1); i--) a[i] = min(a[i], a[i + 1]);
  for (int i = (int)(2); i <= (int)(n); i++) a[i] = min(a[i], a[i - 1] + V);
  f[0].a[0] = 0;
  P[0] = -(1 << 30);
  f[1].a[0] = 1;
  P[1] = 0;
  f[2].a[0] = 0;
  P[2] = min(a[1], V);
  top = 2;
  for (int i = (int)(2); i <= (int)(n); i++) {
    *q = 0;
    q[++*q] = a[i];
    for (int j = (int)(1); j <= (int)(top); j++) {
      q[++*q] = P[j];
      q[++*q] = P[j] + V;
    }
    q[++*q] = 1 << 30;
    sort(q + 1, q + *q + 1);
    *q = unique(q + 1, q + *q + 1) - q - 1;
    for (; q[*q] != a[i]; --*q)
      ;
    for (int j = (int)(0); j <= (int)(top); j++) f[j] = f[j].GF();
    for (int j = (int)(1); j <= (int)(top); j++) {
      f[j].a[0] = (f[j].a[0] + mo - f[j].F(P[j])) % mo;
      f[j].a[0] = (f[j].a[0] + f[j - 1].F(P[j])) % mo;
    }
    int p1 = 0, p2 = 0;
    for (int j = (int)(0); j <= (int)(*q); j++) {
      for (; p1 != top && P[p1 + 1] < q[j + 1] - V; ++p1)
        ;
      for (; p2 != top && P[p2 + 1] < q[j + 1]; ++p2)
        ;
      g[j] = f[p2] - f[p1].tr();
      if (j == (*q)) memset(g[j].a, 0, sizeof(g[j].a));
    }
    top = *q;
    for (int j = (int)(1); j <= (int)(top); j++) P[j] = q[j];
    for (int j = (int)(1); j <= (int)(top); j++) f[j] = g[j];
  }
  int ans = 0;
  for (int i = (int)(1); i <= (int)(top - 1); i++) {
    f[i] = f[i].GF();
    ans = (ans + f[i].F(P[i + 1])) % mo;
    ans = (ans + mo - f[i].F(P[i])) % mo;
  }
  ans = 1ll * ans * power(V, mo - 1 - n) % mo;
  printf("%d\n", ans);
}
