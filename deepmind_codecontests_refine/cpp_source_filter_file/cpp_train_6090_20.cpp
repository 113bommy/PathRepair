#include <bits/stdc++.h>
using namespace std;
int n, m, i, j;
const double eps = 1e-9;
struct nd {
  double x, y;
};
nd operator-(nd x, nd y) { return (nd){x.x - y.x, x.y - y.y}; }
bool cmp(nd x, nd y) {
  if (x.x == y.x) return x.y < y.y;
  return x.x < y.x;
}
double dis(nd x, nd y) { return abs(x.x - y.x) + abs(x.y - y.y); }
double dis2(nd x, nd y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
double crs(nd x, nd y) { return x.x * y.y - x.y * y.x; }
vector<nd> all, cov;
nd stk[2000005];
int tp;
void update1(nd x) {
  if (0 <= x.x && x.x <= 1e5 && 0 <= x.y && x.y <= 1e5) all.push_back(x);
}
void update2(nd p, double r, nd x) {
  if (dis(p, x) <= r) all.push_back(x);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    double x, y, r;
    scanf("%lf%lf%lf", &x, &y, &r);
    if (x + r <= 1e5)
      update1((nd){x + r, y});
    else {
      update1((nd){1e5, y - (r - (1e5 - x))});
      update1((nd){1e5, y + (r - (1e5 - x))});
    }
    if (x - r >= 0)
      update1((nd){x - r, y});
    else {
      update1((nd){0, y - (r - x)});
      update1((nd){0, y + (r - x)});
    }
    if (y + r <= 1e5)
      update1((nd){x, y + r});
    else {
      update1((nd){x - (r - (1e5 - y)), 1e5});
      update1((nd){x + (r - (1e5 - y)), 1e5});
    }
    if (y - r >= 0)
      update1((nd){x, y - r});
    else {
      update1((nd){y - (r - x), 0});
      update1((nd){y + (r - x), 0});
    }
    update2((nd){x, y}, r, (nd){0, 0});
    update2((nd){x, y}, r, (nd){0, 1e5});
    update2((nd){x, y}, r, (nd){1e5, 0});
    update2((nd){x, y}, r, (nd){1e5, 1e5});
  }
  sort(all.begin(), all.end(), cmp);
  stk[tp = 1] = all[0];
  for (i = 1; i < all.size(); i++) {
    if (all[i].x == all[i - 1].x && all[i].y == all[i - 1].y) continue;
    while (tp > 1 && crs(stk[tp] - stk[tp - 1], all[i] - stk[tp]) > -eps) tp--;
    stk[++tp] = all[i];
  }
  for (i = 1; i < tp; i++) cov.push_back(stk[i]);
  reverse(all.begin(), all.end());
  stk[tp = 1] = all[0];
  for (i = 1; i < all.size(); i++) {
    if (all[i].x == all[i - 1].x && all[i].y == all[i - 1].y) continue;
    while (tp > 1 && crs(stk[tp] - stk[tp - 1], all[i] - stk[tp]) < eps) tp--;
    stk[++tp] = all[i];
  }
  for (i = 1; i < tp; i++) cov.push_back(stk[i]);
  double ans = -1e18;
  int res = 0;
  for (i = 0; i < cov.size(); i++) {
    int j = (i + 1) % cov.size();
    int k = (i + 2) % cov.size();
    double tmp = dis2(cov[i], cov[j]) * dis2(cov[i], cov[k]) *
                 dis2(cov[j], cov[k]) / 4 /
                 abs(crs(cov[j] - cov[i], cov[k] - cov[i]) / 2);
    if (tmp > ans) {
      ans = tmp;
      res = i;
    }
  }
  printf("%.0f %.0f\n", cov[res].x, cov[res].y);
  printf("%.0f %.0f\n", cov[(res + 1) % cov.size()].x,
         cov[(res + 1) % cov.size()].y);
  printf("%.0f %.0f\n", cov[(res + 2) % cov.size()].x,
         cov[(res + 2) % cov.size()].y);
  return 0;
}
