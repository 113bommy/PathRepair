#include <bits/stdc++.h>
using namespace std;
int cas = 1;
int dxx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dyy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct node {
  double x, y;
};
vector<node> vc;
double p, sum1, sum2;
int n;
bool yes(double a) {
  double x = a;
  double sum = 0;
  for (int i = 0; i < vc.size(); i++) {
    double ans = a * vc[i].x;
    if (ans <= vc[i].y) continue;
    sum += ans - vc[i].y;
  }
  if (a * p >= sum) return true;
  return false;
}
double binary() {
  double ans = -1;
  double l = 0.0, h = 2000000000;
  while ((h - l) > 0.0000001) {
    double mid = (l + h) / 2.0;
    bool x = yes(mid);
    if (x == true) {
      ans = max(ans, mid);
      l = mid;
    } else {
      h = mid;
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  scanf("%lf", &p);
  sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    node p;
    scanf("%lf %lf", &p.x, &p.y);
    sum1 += p.x;
    sum2 += p.y;
    vc.push_back(p);
  }
  if (sum1 <= p) {
    printf("-1\n");
  } else {
    double ans = binary();
    printf("%lf\n", ans);
  }
  return 0;
}
