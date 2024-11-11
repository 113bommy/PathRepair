#include <bits/stdc++.h>
using namespace std;
struct tar {
  int x, y, t;
  double p;
  bool operator<(const tar& A) const { return t < A.t; }
} a[1010];
int n;
double ans[1010], max1;
bool fit(int i, int j) {
  return sqrt(((double)a[i].x - a[j].x) * ((double)a[i].x - a[j].x) +
              ((double)a[i].y - a[j].y) * ((double)a[i].y - a[j].y)) >=
         a[j].t - a[i].t;
}
void work() {
  int i, j;
  for (i = 0; i < n; i++) ans[i] = a[i].p;
  for (i = 0; i < n; i++) {
    if (max1 < ans[i]) max1 = ans[i];
    for (j = i + 1; j < n; j++)
      if (fit(i, j)) {
        if (ans[j] < ans[i] + a[j].p) ans[j] = ans[i] + a[j].p;
      }
  }
}
int main() {
  int i, j, x, y, t;
  double p;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d%lf", &x, &y, &t, &p);
    a[i].x = x, a[i].y = y, a[i].t = t, a[i].p = p;
  }
  sort(a, a + n);
  max1 = 0;
  work();
  printf("%.8lf\n", max1);
  return 0;
}
