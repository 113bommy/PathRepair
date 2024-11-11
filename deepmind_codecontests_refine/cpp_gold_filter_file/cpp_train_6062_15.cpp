#include <bits/stdc++.h>
int main() {
  int t, n, m, nn[1005], j;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d%d", &n, &m);
    for (j = 0; j < n; j++) scanf("%d", &nn[j]);
    for (j = 1; j < n; j++) {
      for (; nn[0] != m && nn[j];) {
        nn[0]++;
        nn[j]--;
        if (!nn[j]) break;
      }
    }
    printf("%d\n", nn[0]);
    for (int j = 0; j < n; j++) nn[i] = 0;
  }
}
