#include <bits/stdc++.h>
using namespace std;
double X[3], Y[3], s, R, dx, dy, tmp;
int n, i, j, l1, l2, q1[1000], q2[1000], xs, ys, xe, ye, flag;
struct Point {
  int x, y;
  bool operator<(const Point &a) const {
    return (x < a.x) && (x == a.x && y < a.y);
  }
} P[110];
struct Vector {
  int x, y;
  int operator*(const Vector &a) const { return x * a.y - a.x * y; }
};
double min(double a, double b) {
  if (a > b) return b;
  return a;
}
bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3) {
  return abs((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)) < 1e-6;
}
double calc1() {
  return (sqrt((((xs) - (X[1])) * ((xs) - (X[1]))) +
               (((ys) - (Y[1])) * ((ys) - (Y[1]))))) +
         2 * (sqrt((((X[1]) - (X[2])) * ((X[1]) - (X[2]))) +
                   (((Y[1]) - (Y[2])) * ((Y[1]) - (Y[2]))))) +
         (sqrt((((X[2]) - (xe)) * ((X[2]) - (xe))) +
               (((Y[2]) - (ye)) * ((Y[2]) - (ye)))));
}
double calc2() {
  for (i = 1; i <= n; i++)
    if (OnLine(X[1], Y[1], P[i].x, P[i].y, P[i % n + 1].x, P[i % n + 1].y))
      break;
  double ret =
      (sqrt((((X[1]) - (P[i % n + 1].x)) * ((X[1]) - (P[i % n + 1].x))) +
            (((Y[1]) - (P[i % n + 1].y)) * ((Y[1]) - (P[i % n + 1].y)))));
  i = i % n + 1;
  while (true) {
    if (OnLine(X[2], Y[2], P[i].x, P[i].y, P[i % n + 1].x, P[i % n + 1].y)) {
      ret += (sqrt((((P[i].x) - (X[2])) * ((P[i].x) - (X[2]))) +
                   (((P[i].y) - (Y[2])) * ((P[i].y) - (Y[2])))));
      break;
    } else {
      ret += (sqrt(
          (((P[i].x) - (P[i % n + 1].x)) * ((P[i].x) - (P[i % n + 1].x))) +
          (((P[i].y) - (P[i % n + 1].y)) * ((P[i].y) - (P[i % n + 1].y)))));
      i = i % n + 1;
    }
  }
  return (sqrt((((xs) - (X[1])) * ((xs) - (X[1]))) +
               (((ys) - (Y[1])) * ((ys) - (Y[1]))))) +
         (sqrt((((xe) - (X[2])) * ((xe) - (X[2]))) +
               (((ye) - (Y[2])) * ((ye) - (Y[2]))))) +
         min(ret, s - ret);
}
bool Intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                  int y4) {
  Vector A = (Vector){x2 - x1, y2 - y1};
  Vector B = (Vector){x3 - x1, y3 - y1};
  Vector C = (Vector){x4 - x1, y4 - y1};
  Vector D = (Vector){x4 - x3, y4 - y3};
  Vector E = (Vector){x1 - x3, y1 - y3};
  Vector F = (Vector){x2 - x3, y2 - y3};
  return ((A * B) * (A * C) <= 0 && (D * E) * (D * F) < 0);
}
void work() {
  Vector A = (Vector){xe - xs, ye - ys};
  for (i = 1; i <= n; i++)
    if (Intersection(xs, ys, xe, ye, P[i].x, P[i].y, P[i % n + 1].x,
                     P[i % n + 1].y)) {
      Vector B = (Vector){P[i].x - xs, P[i].y - ys};
      Vector C = (Vector){P[i % n + 1].x - xs, P[i % n + 1].y - ys};
      R = abs(double(A * B)) / (abs(double(A * B)) + abs(double(A * C)));
      dx = P[i].x + R * (P[i % n + 1].x - P[i].x);
      dy = P[i].y + R * (P[i % n + 1].y - P[i].y);
      if (!flag ||
          (flag == 1 && (abs(dx - X[1]) > 1e-6 || abs(dy - Y[1]) > 1e-6)))
        X[++flag] = dx, Y[flag] = dy;
    }
  if (flag > 1) {
    if ((sqrt((((X[1]) - (xs)) * ((X[1]) - (xs))) +
              (((Y[1]) - (ys)) * ((Y[1]) - (ys))))) >
        (sqrt((((X[2]) - (xs)) * ((X[2]) - (xs))) +
              (((Y[2]) - (ys)) * ((Y[2]) - (ys)))))) {
      tmp = X[1];
      X[1] = X[2];
      X[2] = tmp;
      tmp = Y[1];
      Y[1] = Y[2];
      Y[2] = tmp;
    }
    printf("%.9lf\n", min(calc1(), calc2()));
  } else
    printf("%.9lf\n", (sqrt((((xs) - (xe)) * ((xs) - (xe))) +
                            (((ys) - (ye)) * ((ys) - (ye))))));
}
int main() {
  scanf("%d%d%d%d", &xs, &ys, &xe, &ye);
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &P[i].x, &P[i].y);
    if (i > 1)
      s += (sqrt((((P[i - 1].x) - (P[i].x)) * ((P[i - 1].x) - (P[i].x))) +
                 (((P[i - 1].y) - (P[i].y)) * ((P[i - 1].y) - (P[i].y)))));
  }
  s += (sqrt((((P[1].x) - (P[n].x)) * ((P[1].x) - (P[n].x))) +
             (((P[1].y) - (P[n].y)) * ((P[1].y) - (P[n].y)))));
  work();
  return 0;
}
