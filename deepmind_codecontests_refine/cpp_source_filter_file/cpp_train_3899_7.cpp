#include <bits/stdc++.h>
using namespace std;
int n, k;
int sum = 0;
int ap[3002];
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      ap[a] += b;
    }
    for (int i = 1; i < 3002; i++) {
      sum += min(ap[i], k);
      ap[i] -= min(k, ap[i]);
      ap[i + 1] += ap[i];
    }
    printf("%d\n", sum);
  }
  return 0;
}
