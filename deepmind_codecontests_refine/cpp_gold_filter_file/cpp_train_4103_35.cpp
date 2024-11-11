#include <bits/stdc++.h>
using namespace std;
int b[1005];
int main() {
  int n, m, k, a, i, t, sum;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    for (i = 1; i <= m; i++) {
      b[i] = 1000000;
    }
    for (i = 1; i <= n; i++) {
      scanf("%d", &a);
      scanf("%d", &t);
      b[a] = min(b[a], t);
    }
    sum = 0;
    for (i = 1; i <= m; i++) {
      sum = sum + b[i];
    }
    printf("%d\n", min(sum, k));
  }
  return 0;
}
