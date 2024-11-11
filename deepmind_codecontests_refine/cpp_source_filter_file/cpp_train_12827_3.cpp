#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  double ans;
  for (int i = 1; i <= n; ++i) {
    ans += ((double)1.0 / (double)i);
  }
  printf("%.6lf", ans);
  return 0;
}
