#include <bits/stdc++.h>
const int N(1e5 + 10);
const double eps(1e-12);
int n, top;
long long t;
double M;
struct node {
  double a, b, p, e;
} a[N], stk[N];
inline int operator<(const node &l, const node &r) {
  return std::fabs(l.p - r.p) < eps ? l.e > r.e : l.p < r.p;
}
inline int check(node i, node j, node k) {
  return (j.p - i.p) * (k.e - j.e) > (j.e - i.e) * (k.p - j.p);
}
struct Matrix {
  double a[3][3];
  double *operator[](const int &x) { return a[x]; }
  const double *operator[](const int &x) const { return a[x]; }
} S, P, T[35];
Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c;
  std::memset(c.a, 0, sizeof c.a);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) c[i][k] += a[i][j] * b[j][k];
  return c;
}
Matrix Init(const node &x) {
  Matrix c;
  std::memset(c.a, 0, sizeof c.a);
  c[0][0] = 1 - x.p, c[1][0] = M * x.p, c[2][0] = x.e;
  return c[1][1] = c[2][1] = c[2][2] = 1., c;
}
int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf%lf", &a[i].a, &a[i].b, &a[i].p),
        a[i].e = a[i].a * a[i].p, M = std::max(M, a[i].b * a[i].p);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (std::fabs(a[i].p - a[i - 1].p) < eps) continue;
    while (top > 1 && check(stk[top - 1], stk[top], a[i])) --top;
    stk[++top] = a[i];
  }
  int pos = 1;
  S[0][2] = 1;
  for (long long tim = 0; tim < t; ++tim) {
    double sum = S[0][0] - S[0][1] * M, _ = 0;
    while (pos < top &&
           stk[pos + 1].e - stk[pos].e > sum * (stk[pos + 1].p - stk[pos].p))
      ++pos;
    T[0] = Init(stk[pos]);
    for (int i = 1; i < 35; i++) T[i] = T[i - 1] * T[i - 1];
    for (int i = 34; ~i; i--)
      if (tim + (1ll << i) < t) {
        P = S * T[i], _ = P[0][1] * M - P[0][0];
        if (pos == top ||
            stk[pos].p * _ + stk[pos].e > stk[pos + 1].p * _ + stk[pos + 1].e)
          S = P, tim += (1ll << i);
      }
    S = S * T[0];
  }
  printf("%.10lf\n", S[0][0]);
  return 0;
}
