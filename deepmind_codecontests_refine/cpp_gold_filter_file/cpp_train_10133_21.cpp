#include <bits/stdc++.h>
int n;
double a, d, tem[100086][3], mini = -1;
double chuli(int i) {
  double t;
  t = tem[i][1] / a;
  if (t * tem[i][1] / 2 >= d) {
    return sqrt(2 * d / a) + tem[i][0];
  }
  return tem[i][0] + t + (d - tem[i][1] / 2 * t) / tem[i][1];
}
int main() {
  int i, j, k;
  double lin;
  scanf("%d%lf%lf", &n, &a, &d);
  for (i = 0; i < n; i++) {
    scanf("%lf%lf", &tem[i][0], &tem[i][1]);
    lin = chuli(i);
    if (mini < lin) {
      printf("%.10lf\n", lin);
      mini = lin;
    } else {
      printf("%.10lf\n", mini);
    }
  }
  return 0;
}
