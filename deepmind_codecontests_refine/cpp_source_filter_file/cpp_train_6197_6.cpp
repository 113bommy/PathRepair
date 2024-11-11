#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
} p[111][3], A, B, C, D;
void prin(point A) { cout << A.x << " " << A.y << endl; }
double area(point a, point b, point c) {
  return (((b.x - a.x) * (c.y - a.y)) - ((c.x - a.x) * (b.y - a.y))) / 2;
}
int ins(int tid, point po) {
  double ret = 0;
  int i;
  double ar;
  for (i = 0; i < 3; i++) {
    ret += fabs(area(p[tid][i], po, p[tid][(i + 1) % 3]));
  }
  ar = area(p[tid][0], p[tid][1], p[tid][2]);
  if (fabs(ar - ret) < 1e-6)
    return 1;
  else
    return 0;
}
double dist(point a, point b) {
  double ret;
  ret = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  return ret;
}
int main() {
  int i, n, j, k, sz, I, J;
  double ans, s1, s2;
  while (scanf("%d", &n) == 1) {
    ans = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) {
        scanf("%lf %lf", &p[i][j].x, &p[i][j].y);
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) {
        A = p[i][j];
        B = p[i][(j + 1) % 3];
        vector<double> v;
        v.push_back(0);
        v.push_back(1);
        for (I = 0; I < n; I++) {
          if (I == i) continue;
          for (J = 0; J < 3; J++) {
            C = p[I][J];
            D = p[I][(J + 1) % 3];
            s1 = area(C, D, A);
            s2 = area(C, D, B);
            point s;
            double val = s1 / (s1 - s2);
            if ((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0)) {
              s1 = area(A, B, C);
              s2 = area(A, B, D);
              if ((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0)) v.push_back(val);
            }
          }
        }
        sort(v.begin(), v.end());
        point s, te;
        double d = dist(A, B);
        for (k = 0; k < (v.size() - 1); k++) {
          s.x = A.x + (B.x - A.x) * ((v[k + 1] + v[k]) / 2.0);
          s.y = A.y + (B.y - A.y) * ((v[k + 1] + v[k]) / 2.0);
          int ok = 1;
          for (I = 0; I < n; I++) {
            if (I == i) continue;
            if (ins(I, s)) {
              ok = 0;
              break;
            }
          }
          if (ok) {
            ans += d * (v[k + 1] - v[k]);
          }
        }
      }
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}
