#include <bits/stdc++.h>
using namespace std;
struct ww {
  double x, y, z;
  inline double bei() const { return x * x + y * y; }
  inline ww operator-(const ww &A) { return (ww){x - A.x, y - A.y, 0}; }
  inline double operator*(const ww &A) { return x * A.y - y * A.x; }
} a[100010], O;
struct w {
  double a;
  int id;
  inline bool operator<(const w &A) const { return a < A.a; }
};
int i, j, k, n, m;
double r, an;
int g[100010], F[100010], L[100010], R[100010], f[100010];
priority_queue<w> b;
inline bool cc1(const ww &a, const ww &b) {
  return a.z + (1e-7) < b.z || abs(a.z - b.z) < (1e-7) && a.bei() < b.bei();
}
inline bool ju(int A, int B, int C) {
  return (a[C] - a[A]) * (a[B] - a[A]) > -(1e-7);
}
inline void Tu() {
  k = 1;
  for (i = 2; i <= n; i++)
    if (a[i].x < a[k].x || a[i].x == a[k].x && a[i].y < a[k].y) k = i;
  swap(a[1], a[k]);
  O = a[1];
  for (i = n; i; i--) {
    a[i].x -= a[1].x, a[i].y -= a[1].y;
    a[i].z = atan2(a[i].y, a[i].x);
  }
  sort(a + 2, a + n + 1, cc1);
  g[m = 1] = 1;
  for (i = 2; i <= n + 1; i++) {
    for (; m > 1 + (i == n + 1) && ju(g[m - 1], g[m], i); m--)
      ;
    g[++m] = i;
  }
  m--;
  a[0] = a[m];
}
inline double dis(ww a, ww b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
inline ww suan(double a, double b, double c, double d, double e, double f) {
  ww O = {(f * b - c * e) / (a * e - b * d), (a * f - c * d) / (b * d - a * e)};
  return O;
}
inline double pan(int x) {
  ww A = a[g[L[x]]], B = a[g[x]], C = a[g[R[x]]];
  double s1 = dis(A, B), s2 = dis(B, C), s3 = dis(A, C);
  if (s1 + s2 + (1e-7) < s3) {
    ww O = suan(2 * (A.x - B.x), 2 * (A.y - B.y), B.bei() - A.bei(),
                2 * (A.x - C.x), 2 * (A.y - C.y), C.bei() - A.bei());
    double R = dis(O, A);
    return sqrt(R);
  }
  return 0;
}
inline void cal() {
  for (i = 1; i <= m; i++) an += a[g[i]] * a[g[i + 1]];
  if (an < 0) an = -an;
  an /= 2;
  for (i = 1; i <= m; i++) {
    double s = dis(a[g[i]], a[g[i + 1]]);
    s = sqrt(s);
    double ag = asin(s / 2 / r) * 2;
    double s1 = r * r * ag / 2;
    double s2 = r * sin(ag) * r / 2;
    an += s1 - s2;
  }
  printf("%.11lf\n", an);
}
int main() {
  scanf("%d%lf", &n, &r);
  for (i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
  Tu();
  for (i = 2; i <= m - 1; i++) L[i] = i - 1, R[i] = i + 1;
  L[1] = m, R[m] = 1, R[1] = 2, L[m] = m - 1;
  for (i = 1; i <= m; i++) b.push((w){pan(i), i});
  for (; b.size() > 2;) {
    w A = b.top();
    if (A.a < r + (1e-7)) break;
    int B = A.id;
    b.pop();
    if (F[B]) continue;
    if (abs(pan(B) - A.a) > (1e-7)) continue;
    F[B] = 1;
    L[R[B]] = L[B];
    R[L[B]] = R[B];
    b.push((w){pan(L[B]), L[B]});
    b.push((w){pan(R[B]), R[B]});
  }
  for (; b.size();) {
    w A = b.top();
    b.pop();
    if (!F[A.id]) f[A.id] = 1;
  }
  k = m, m = 0;
  for (i = 1; i <= k; i++)
    if (f[i]) {
      g[++m] = g[i];
    }
  g[m + 1] = g[1];
  cal();
  return 0;
}
