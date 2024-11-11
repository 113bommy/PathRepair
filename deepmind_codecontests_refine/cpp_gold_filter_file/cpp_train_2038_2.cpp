#include <bits/stdc++.h>
using namespace std;
int Nextint() {
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  int x = 0;
  bool flag = false;
  if (ch == '-') {
    flag = true;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (flag) x = -x;
  return x;
}
const int maxn = 100000;
int N, M;
double x1, Y1, x2, Y2, sx, sy;
struct TT {
  double x1, Y1, x2, Y2;
} sq[maxn];
double X[maxn], Y[maxn];
struct PT {
  double x, y;
  int dt;
} pt[maxn];
int lt;
double dis(double x1, double Y1, double x2, double Y2) {
  x1 -= x2;
  Y1 -= Y2;
  return sqrt(x1 * x1 + Y1 * Y1);
}
double area(double x1, double Y1, double x2, double Y2) {
  return x1 * Y2 - x2 * Y1;
}
double check(double x1, double Y1, double x2, double Y2, double x3, double Y3) {
  return area(x2 - x1, Y2 - Y1, x3 - x1, Y3 - Y1);
}
bool SS(TT a, TT b) {
  double S1 = check(a.x1, a.Y1, a.x2, a.Y2, b.x1, b.Y1),
         S2 = check(a.x1, a.Y1, a.x2, a.Y2, b.x2, b.Y2);
  S1 = S1 * S2;
  return S1 < 1E-9;
}
bool S(TT a, TT b) { return SS(a, b) && SS(b, a); }
void Sol(TT a, TT b) {
  double S1, S2;
  S1 = fabs(check(a.x1, a.Y1, a.x2, a.Y2, b.x1, b.Y1)),
  S2 = fabs(check(a.x1, a.Y1, a.x2, a.Y2, b.x2, b.Y2));
  sx = b.x1 + (b.x2 - b.x1) * S1 / (S1 + S2 + 1E-7);
  sy = b.Y1 + (b.Y2 - b.Y1) * S1 / (S1 + S2 + 1E-7);
  lt++;
  pt[lt].x = sx;
  pt[lt].y = sy;
}
int main() {
  x1 = Nextint();
  Y1 = Nextint();
  x2 = Nextint();
  Y2 = Nextint();
  N = Nextint();
  double tl = 0;
  for (int i = 1; i <= N; i++) {
    X[i] = Nextint();
    Y[i] = Nextint();
    sq[i - 1].x1 = X[i - 1];
    sq[i - 1].Y1 = Y[i - 1];
    sq[i - 1].x2 = X[i];
    sq[i - 1].Y2 = Y[i];
  }
  sq[N].x1 = X[N];
  sq[N].Y1 = Y[N];
  sq[N].x2 = X[1];
  sq[N].Y2 = Y[1];
  sq[0].x1 = x1;
  sq[0].Y1 = Y1;
  sq[0].x2 = x2;
  sq[0].Y2 = Y2;
  for (int i = 1; i <= N; i++) {
    if (S(sq[0], sq[i])) {
      Sol(sq[0], sq[i]);
      pt[lt].dt = i;
    }
    tl += dis(sq[i].x1, sq[i].Y1, sq[i].x2, sq[i].Y2);
  }
  if (lt < 2)
    printf("%.8lf\n", dis(x1, Y1, x2, Y2));
  else {
    if (dis(pt[1].x, pt[1].y, pt[lt].x, pt[lt].y) < 1E-5) swap(pt[lt], pt[2]);
    double S1 = dis(pt[1].x, pt[1].y, sq[pt[1].dt].x2, sq[pt[1].dt].Y2) +
                dis(pt[lt].x, pt[lt].y, sq[pt[lt].dt].x1, sq[pt[lt].dt].Y1);
    for (int i = pt[1].dt + 1; i < pt[lt].dt; i++)
      S1 += dis(sq[i].x1, sq[i].Y1, sq[i].x2, sq[i].Y2);
    S1 = min(min(S1, tl - S1), dis(pt[1].x, pt[1].y, pt[lt].x, pt[lt].y) * 2);
    S1 += min(dis(x1, Y1, pt[1].x, pt[1].y) + dis(pt[lt].x, pt[lt].y, x2, Y2),
              dis(x1, Y1, pt[lt].x, pt[lt].y) + dis(pt[1].x, pt[1].y, x2, Y2));
    printf("%.8lf\n", S1);
  }
  return 0;
}
