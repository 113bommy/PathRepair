#include <bits/stdc++.h>
using namespace std;
double ans;
const double pi = acos(-1.), eps = 1e-9;
struct pp {
  double vl;
  int flag;
  bool operator<(const pp &temp) const { return vl < temp.vl; }
};
pp ko[4222];
int num;
struct point {
  double x, y;
};
point pt[2222];
int n[2];
double dist[2222][2222], alpha[2222][2222];
double low, high, mid;
void norm(double &theta) {
  while (theta > pi + eps) theta -= 2 * pi;
  while (theta < -pi + eps) theta += 2 * pi;
}
bool check(int id, double r) {
  int i, j, s, p, q, cnt[2] = {0};
  i = id;
  if (id < n[0]) {
    num = 0;
    for (j = n[0]; j < n[0] + n[1]; j++) {
      double vm, ltheta, rtheta;
      vm = dist[i][j] / (2 * r);
      if (vm >= 1) continue;
      vm = acos(vm);
      ltheta = alpha[i][j] - vm;
      rtheta = alpha[i][j] + vm;
      norm(ltheta);
      norm(rtheta);
      if (ltheta > rtheta) cnt[0]++;
      ko[num].vl = ltheta;
      ko[num++].flag = -1;
      ko[num].vl = rtheta;
      ko[num++].flag = 1;
    }
    sort(ko, ko + num);
    if (cnt[0] == 0) return true;
    for (j = 0; j < num; j++) {
      cnt[0] -= ko[j].flag;
      if (cnt[0] == 0) return true;
    }
  } else {
    num = 0;
    for (j = 0; j < n[0] + n[1]; j++) {
      if (j == i) continue;
      double vm, ltheta, rtheta;
      vm = dist[i][j] / (2 * r);
      if (vm >= 1) continue;
      vm = acos(vm);
      ltheta = alpha[i][j] - vm;
      rtheta = alpha[i][j] + vm;
      norm(ltheta);
      norm(rtheta);
      if (ltheta > rtheta) {
        if (j < n[0])
          cnt[0]++;
        else
          cnt[1]++;
      }
      ko[num].vl = ltheta;
      ko[num++].flag = -1;
      if (j >= n[0]) ko[num - 1].flag = -2;
      ko[num].vl = rtheta;
      ko[num++].flag = 1;
      if (j >= n[0]) ko[num - 1].flag = 2;
    }
    sort(ko, ko + num);
    if (cnt[1] == 0 && cnt[0] > 0) return true;
    for (j = 0; j < num; j++) {
      if (abs(ko[j].flag) == 1)
        cnt[0] -= ko[j].flag;
      else
        cnt[1] -= ko[j].flag / 2;
      if (cnt[1] == 0 && cnt[0] > 0) return true;
    }
  }
  return false;
}
int main() {
  int i, j, s, p, q;
  scanf("%d%d", &n[0], &n[1]);
  for (i = 0; i < n[0] + n[1]; i++) scanf("%lf%lf", &pt[i].x, &pt[i].y);
  for (i = 0; i < n[0] + n[1]; i++) {
    for (j = 0; j < n[0] + n[1]; j++) {
      if (i == j) continue;
      dist[i][j] = sqrt((pt[i].x - pt[j].x) * (pt[i].x - pt[j].x) +
                        (pt[i].y - pt[j].y) * (pt[i].y - pt[j].y));
      alpha[i][j] = atan2(pt[j].y - pt[i].y, pt[j].x - pt[i].x);
    }
  }
  ans = 1;
  for (i = 0; i < n[0] + n[1]; i++) {
    low = ans;
    high = 1e9;
    if (!check(i, ans)) continue;
    while (low < high - 1e-5) {
      mid = 0.5 * (low + high);
      if (check(i, mid))
        low = mid;
      else
        high = mid - 1e-5;
    }
    ans = 0.5 * (low + high);
  }
  if (ans > 1e9 - 1)
    puts("-1");
  else
    printf("%f\n", ans);
  return 0;
}
