#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double ans = 0.0;
  scanf("%d", &n);
  while (n > 0) {
    ans += (1.0 / (double)n);
    n -= 1;
  }
  printf("%.7f\n", ans);
  return 0;
}
