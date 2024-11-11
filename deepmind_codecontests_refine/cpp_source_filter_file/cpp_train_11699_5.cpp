#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (k >= m) {
    printf("%.4lf\n", 1);
    return 0;
  }
  if (n + k < m) {
    printf("%.4lf\n", 0);
    return 0;
  }
  double ans = 1.0;
  for (int i = 0; i <= k; i++) {
    ans *= double(m - i);
    ans /= double(n + 1 + i);
  }
  printf("%.4lf\n", 1.0 - ans);
  return 0;
}
