#include <bits/stdc++.h>
using namespace std;
int d[200005];
int main() {
  int n, w;
  double v;
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n * 2; i++) scanf("%d", &d[i]);
  sort(d, d + n * 2);
  double p1 = d[0];
  double p2 = d[n] / 2.0;
  double p3 = w / 3.0;
  double ans = min(p1, min(p2, p3));
  ans *= 3;
  ans *= n;
  printf("%.8f\n", ans);
  return 0;
}
