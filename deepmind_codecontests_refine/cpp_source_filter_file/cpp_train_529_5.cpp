#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, d;
  while (scanf("%d %d %d", &n, &l, &d) != EOF) {
    int a[n + 1], b[n + 1], i, sum, count = 0, tmp = 0;
    for (i = 0; i < n; i++) {
      scanf("%d %d", &a[i], &b[i]);
      sum = a[i] - tmp;
      count += sum / d;
      tmp = b[i];
    }
    if (tmp < l) {
      sum = l - tmp;
      count += sum / d;
    }
    printf("%d\n", count);
  }
  return 0;
}
