#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double x, y, s;
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &x, &y);
    s += y;
  }
  printf("%.3lf", s / n + 5);
  return 0;
}
