#include <bits/stdc++.h>
using namespace std;
const int INF = -1e10;
double ax, ay, bx, by, tx, ty;
double maxa1, maxa2, maxb1, maxb2;
int ida, idb;
int n;
double x, y;
int main() {
  scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &tx, &ty);
  maxa1 = INF;
  maxb1 = INF;
  maxa2 = INF;
  maxb2 = INF;
  scanf("%d", &n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &x, &y);
    double dis = sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
    sum += dis * 2;
    double disa = sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay));
    if (maxa2 < dis - disa) {
      maxa2 = dis - disa;
      if (maxa2 > maxa1) {
        swap(maxa1, maxa2);
        ida = i;
      }
    }
    double disb = sqrt((x - bx) * (x - bx) + (y - by) * (y - by));
    if (maxb2 < dis - disb) {
      maxb2 = dis - disb;
      if (maxb2 > maxb1) {
        swap(maxb1, maxb2);
        idb = i;
      }
    }
  }
  if (ida == idb) {
    printf("%.12f",
           sum - max(max(maxb1 + maxa2, maxb1), max(maxb2 + maxa1, maxa1)));
  } else
    printf("%.12f", sum - max((maxb1 + maxa1), max(maxa1, maxb1)));
}
