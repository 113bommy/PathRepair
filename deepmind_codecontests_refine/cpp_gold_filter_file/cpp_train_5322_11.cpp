#include <bits/stdc++.h>
int dat[103];
int main() {
  int n, m, h;
  scanf("%d%d%d", &n, &m, &h);
  h--;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &dat[i]);
    sum += dat[i];
  }
  if (sum < n) {
    printf("-1\n");
    return 0;
  }
  double ans = 0;
  for (int k = 2; k <= dat[h] && k <= n; k++) {
    double tmp = 1;
    for (int i = 0; i < k - 1; i++) {
      tmp *= (dat[h] - i - 1) / (double)(i + 1);
    }
    for (int i = 0; i < n - k; i++) {
      tmp *= (sum - dat[h] - i) / (double)(i + 1);
    }
    ans += tmp;
  }
  for (int i = 0; i < n - 1; i++) {
    ans /= (sum - i - 1) / (double)(i + 1);
  }
  printf("%.10f\n", ans);
  return 0;
}
