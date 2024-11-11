#include <bits/stdc++.h>
using namespace std;
int x[1010], y[1010];
int main() {
  int n, i, c = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (i = 2; i < n - 2; i++) {
    if ((x[i] - x[i - 1] > 0 && y[i + 1] - y[i] > 0) ||
        (x[i] - x[i + 1] > 0 && y[i] - y[i - 1] > 0) ||
        (x[i - 1] - x[i] > 0 && y[i] - y[i + 1] > 0) ||
        (x[i + 1] - x[i] > 0 && y[i - 1] - y[i] > 0)) {
      c++;
    }
  }
  printf("%d\n", c);
  return 0;
}
