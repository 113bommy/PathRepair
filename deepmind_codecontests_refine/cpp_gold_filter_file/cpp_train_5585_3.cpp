#include <bits/stdc++.h>
using namespace std;
int n, U;
int a[100005];
int main() {
  scanf("%d %d", &n, &U);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  double maxVal = -1;
  int j = 1;
  for (int i = 0; i < n; i++) {
    if (j <= i + 1) {
      j = i + 2;
    }
    while (j < n - 1 && a[j + 1] - a[i] <= U) {
      j++;
    }
    if (j >= n || a[j] - a[i] > U) {
      continue;
    }
    maxVal = max(maxVal, 1.0 * (a[j] - a[i + 1]) / (a[j] - a[i]));
  }
  if (maxVal < 0) {
    printf("-1\n");
  } else {
    printf("%.12lf\n", maxVal);
  }
  return 0;
}
