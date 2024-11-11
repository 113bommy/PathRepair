#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i, j, k, a, c, ans[500];
  while (cin >> m >> n) {
    for (i = 0; i < 500; i++) ans[i] = 0;
    for (i = 1; i <= n; i++) {
      c = 0;
      for (j = 1; j <= m; j++) {
        scanf("%d", &a);
        if (a > c) {
          c = a;
          k = j;
        }
      }
      ans[k]++;
    }
    int ma = 0, p;
    for (i = 1; i < 300; i++) {
      if (ans[i] > ma) {
        ma = ans[i];
        p = i;
      }
    }
    printf("%d\n", p);
  }
  return 0;
}
