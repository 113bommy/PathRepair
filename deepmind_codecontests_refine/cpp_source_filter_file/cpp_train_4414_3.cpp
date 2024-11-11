#include <bits/stdc++.h>
struct circle {
  double x, y, r;
};
circle ci[3];
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double eval1(double x, double y) {
  double dst[3];
  for (int i = 0; i < 3; i++) dst[i] = dist(x, y, ci[i].x, ci[i].y);
  std::vector<double> vd(3);
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    vd[i] = fabs(dst[i] / dst[j] - ci[i].r / ci[j].r);
  }
  std::sort(vd.begin(), vd.end());
  return vd.back();
}
double eval(double x, double y) {
  std::vector<double> b(3);
  double dst[3];
  for (int i = 0; i < 3; i++) dst[i] = dist(x, y, ci[i].x, ci[i].y);
  b[0] = fabs(dst[0] / dst[1] - ci[0].r / ci[1].r);
  b[1] = fabs(dst[1] / dst[2] - ci[1].r / ci[2].r);
  b[2] = fabs(dst[2] / dst[0] - ci[2].r / ci[0].r);
  sort(b.begin(), b.end());
  return b.back();
}
int main() {
  for (int i = 0; i < 3; i++) std::cin >> ci[i].x >> ci[i].y >> ci[i].r;
  double cur_x = (ci[0].x + ci[1].x + ci[2].x) / 3.0;
  double cur_y = (ci[0].y + ci[1].y + ci[2].y) / 3.0;
  double step = 10.0;
  int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
  int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
  while (step > 1E-9) {
    int i = 0;
    for (i = 0; i < 8; i++) {
      double n_x = cur_x + step * dx[i];
      double n_y = cur_y + step * dy[i];
      if (eval(cur_x, cur_y) > eval(n_x, n_y)) {
        cur_x = n_x;
        cur_y = n_y;
        break;
      }
    }
    if (i == 8) step /= 2.0;
  }
  if (eval(cur_x, cur_y) < 1E-6) printf("%.9f %.9f\n", cur_x, cur_y);
  return 0;
}
