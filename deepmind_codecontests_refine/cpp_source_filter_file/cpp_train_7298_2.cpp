#include <bits/stdc++.h>
using namespace std;
const int PI = acos(-1);
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
struct node {
  double x, y;
} coor[maxn];
int n;
int check(long double x) {
  long double l = -1e7, r = 1e7;
  for (int i = 0; i < n; i++) {
    long double range;
    if (x * x - (x - coor[i].y) * (x - coor[i].y) < 0) return 0;
    range = sqrt(x * x - (x - coor[i].y) * (x - coor[i].y));
    if (l < coor[i].x - range) l = coor[i].x - range;
    if (r > coor[i].x + range) r = coor[i].x + range;
  }
  return l <= r;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf %lf", &coor[i].x, &coor[i].y);
  for (int i = 0; i < n; i++) {
    if (coor[i].y * coor[n - 1].y < 0) {
      printf("-1\n");
      return 0;
    } else {
      if (coor[i].y < 0) coor[i].y = -coor[i].y;
    }
  }
  long double l = 0, r = 1e7 + 1, mid = 0;
  for (int i = 0; i <= 1000; i++) {
    mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.7Lf\n", mid);
}
