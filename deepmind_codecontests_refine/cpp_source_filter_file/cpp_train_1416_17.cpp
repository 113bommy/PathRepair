#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d:%d", &n, &m);
  if (n == 12) n = 0;
  double ans1 = n * 30 + m * 0.5;
  int ans2 = m * 6;
  if ((int)ans1 == ans1)
    printf("%.0lf %d\n", ans1, ans2);
  else
    printf("%.1lf %d\n", ans1, ans2);
  return 0;
}
