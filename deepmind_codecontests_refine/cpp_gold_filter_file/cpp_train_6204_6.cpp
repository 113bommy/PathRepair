#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const double eps = 1e-10;
const int inf = 1e9;
double cmp(double x) {
  if (x > eps) {
    return 1;
  } else if (x < -eps) {
    return -1;
  } else {
    return 0;
  }
}
vector<pair<double, int>> vec;
bool comp(pair<double, int> &a, pair<double, int> &b) {
  return cmp(a.first - b.first) < 0 ||
         (cmp(a.first - b.first) == 0 && a.second < b.second);
}
int n;
int main() {
  scanf("%d", &n);
  int x1, x2, y1, y2;
  int x, y, vx, vy;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x, &y, &vx, &vy);
    long double tx1, tx2, ty1, ty2;
    if (vx != 0) {
      tx1 = max((double)0, double(x1 - x) / vx);
      tx2 = max(double(0), double(x2 - x) / vx);
    } else {
      if (x1 < x && x < x2) {
        tx1 = 0;
        tx2 = 1e9;
      } else {
        tx1 = tx2 = -1;
      }
    }
    if (tx1 > tx2) {
      swap(tx1, tx2);
    }
    if (vy != 0) {
      ty1 = max((double)0, double(y1 - y) / vy);
      ty2 = max((double)0, double(y2 - y) / vy);
    } else {
      if (y1 < y && y < y2) {
        ty1 = 0;
        ty2 = 1e9;
      } else {
        ty1 = ty2 = -1;
      }
    }
    if (ty1 > ty2) swap(ty1, ty2);
    if (cmp(tx2) <= 0 || cmp(ty2) <= 0 || cmp(tx2 - ty1) <= 0 ||
        cmp(ty2 - tx1) <= 0) {
      printf("-1\n");
      return 0;
    }
    vec.push_back({max(tx1, ty1), 1});
    vec.push_back({min(tx2, ty2), -1});
  }
  sort(vec.begin(), vec.end(), comp);
  for (int i = 0; i < n; i++) {
    if (vec[i].second == -1) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%.10lf\n", vec[n - 1].first);
  return 0;
}
