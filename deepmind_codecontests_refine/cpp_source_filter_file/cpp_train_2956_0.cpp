#include <bits/stdc++.h>
int main() {
  int m, n;
  int c, t;
  int v;
  int i, j;
  int k = 0;
  int totalTime[100000];
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &c, &t);
    if (i == 0)
      totalTime[i] = c * t;
    else
      totalTime[i] += totalTime[i - 1] + c * t;
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &v);
    for (j = k; j < n; j++) {
      if (totalTime[j] >= v) {
        printf("%d\n", j + 1);
        k = j;
        break;
      }
    }
  }
}
