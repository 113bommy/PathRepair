#include <bits/stdc++.h>
using namespace std;
double eps = 1e-7;
typedef double tPointd[2];
int dcmp(double a, double b);
void pprint(tPointd a) { printf("%0.2f %0.2f ", a[0], a[1]); }
char SegLineInt(tPointd a, tPointd b, tPointd c, tPointd d, tPointd m) {
  double s, t;
  double num, denom;
  char cody;
  denom = a[0] * (double)(d[1] - c[1]) + b[0] * (double)(c[1] - d[1]) +
          d[0] * (double)(b[1] - a[1]) + c[0] * (double)(a[1] - b[1]);
  if (dcmp(denom, 0) == 0) return 'e';
  num = a[0] * (double)(d[1] - c[1]) + c[0] * (double)(a[1] - d[1]) +
        d[0] * (double)(c[1] - a[1]);
  if (num == 0 || num == denom) cody = 'v';
  s = num / denom;
  num = -(a[0] * (double)(c[1] - b[1]) + b[0] * (double)(a[1] - c[1]) +
          c[0] * (double)(b[1] - a[1]));
  t = num / denom;
  if (s > 0 && s < 1.0)
    cody = '1';
  else
    cody = '0';
  m[0] = a[0] + s * (b[0] - a[0]);
  m[1] = a[1] + s * (b[1] - a[1]);
  return cody;
}
inline double Area2(tPointd a, tPointd b, tPointd c) {
  return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]);
}
void ToVector(tPointd a, tPointd b, tPointd c) {
  c[0] = b[0] - a[0];
  c[1] = b[1] - a[1];
}
inline void pcpy(tPointd a, tPointd b) {
  a[0] = b[0];
  a[1] = b[1];
}
void MidP(tPointd a, tPointd b, tPointd mid) {
  mid[0] = (a[0] + b[0]) * 0.5;
  mid[1] = (a[1] + b[1]) * 0.5;
}
void Padd(tPointd a, tPointd b) {
  a[0] += b[0];
  a[1] += b[1];
}
void Pmul(tPointd a, double t) {
  a[0] *= t;
  a[1] *= t;
}
void lfturn(tPointd a) {
  double t = a[0];
  a[0] = -a[1];
  a[1] = t;
}
void pswap(tPointd a, tPointd b) {
  swap(a[0], b[0]);
  swap(a[1], b[1]);
}
int dcmp(double a, double b) {
  if (fabs(a - b) < eps)
    return 0;
  else if (a < b)
    return -1;
  return 1;
}
tPointd a, b, c;
tPointd p0, p1, p2, p3;
bool check() {
  tPointd s0, s1, t1, t0;
  MidP(a, b, s0);
  ToVector(a, b, s1);
  lfturn(s1);
  Padd(s1, s0);
  MidP(c, b, t0);
  ToVector(c, b, t1);
  lfturn(t1);
  Padd(t1, t0);
  tPointd tmp;
  ToVector(a, b, tmp);
  Padd(s0, tmp);
  Padd(s1, tmp);
  if (SegLineInt(s0, s1, t0, t1, p0) == 'e') return false;
  ToVector(p0, b, p1);
  Pmul(p1, 2.0);
  Padd(p1, p0);
  ToVector(p1, a, p2);
  Pmul(p2, 2.0);
  Padd(p2, p1);
  ToVector(p0, c, p3);
  Pmul(p3, 2.0);
  Padd(p3, p0);
  double t;
  int sign;
  t = Area2(p0, p1, p2);
  sign = dcmp(t, 0);
  if (sign == 0) return false;
  t = Area2(p1, p2, p3);
  if (dcmp(t, 0) * sign <= 0) return false;
  t = Area2(p2, p3, p0);
  if (dcmp(t, 0) * sign <= 0) return false;
  t = Area2(p3, p0, p1);
  if (dcmp(t, 0) * sign <= 0) return false;
  return true;
}
void solve() {
  int i, j, k;
  if (check()) {
    printf("YES\n");
    printf("%0.9f %0.9f %0.9f %0.9f %0.9f %0.9f %0.9f %0.9f\n", p0[0], p0[1],
           p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);
    return;
  }
  pswap(a, b);
  if (check()) {
    printf("YES\n");
    printf("%0.9f %0.9f %0.9f %0.9f %0.9f %0.9f %0.9f %0.9f\n", p0[0], p0[1],
           p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);
    return;
  }
  pswap(b, c);
  if (check()) {
    printf("YES\n");
    printf("%0.9f %0.9f %0.9f %0.9f %0.9f %0.9f %0.9f %0.9f\n", p0[0], p0[1],
           p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);
    return;
  }
  printf("NO\n\n");
}
void gen(int cas) {
  cout << cas << endl;
  int i, j, k, x, y;
  for (i = 0; i < cas; ++i) {
    for (j = 0; j < 3; ++j) {
      x = rand() % 11;
      y = rand() % 11;
      cout << x << " " << y << endl;
    }
  }
}
int main() {
  int i, j, cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%lf %lf %lf %lf %lf %lf", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1]);
    if (dcmp(0, Area2(a, b, c)) == 0) {
      printf("NO\n\n");
      continue;
    }
    solve();
  }
}
