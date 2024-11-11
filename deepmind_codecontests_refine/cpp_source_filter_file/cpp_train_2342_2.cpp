#include <bits/stdc++.h>
using namespace std;
int x[100010];
int main() {
  int i, j, n;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &x[i]);
    for (i = 0; i < n; i++) {
      int minValue, maxValue;
      if (i == 0) {
        minValue = x[i + 1] - x[i];
        maxValue = x[n - 1] - x[i];
      } else if (i == n - 1) {
        minValue = x[i] - x[i - 1];
        maxValue = x[i] - x[0];
      } else {
        minValue = min(x[i] - x[0], x[n - 1] - x[i]);
        maxValue = max(x[i] - x[0], x[n - 1] - x[i]);
      }
      printf("%d %d\n", minValue, maxValue);
    }
  }
  return 0;
}
