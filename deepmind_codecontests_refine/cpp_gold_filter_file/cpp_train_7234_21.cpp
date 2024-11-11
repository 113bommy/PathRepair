#include <bits/stdc++.h>
using namespace std;
int h[100010], res[100010];
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    memset(h, 0, sizeof(h));
    memset(res, 0, sizeof(res));
    for (i = 1; i <= n; i++) {
      scanf("%d", &h[i]);
    }
    int temp = 0;
    for (i = 1; i <= n; i++) {
      temp = min(temp, h[i] - i);
      res[i] = i + temp;
    }
    temp = n + 1;
    for (i = n; i >= 1; i--) {
      temp = min(temp, h[i] + i);
      res[i] = min(res[i], temp - i);
    }
    int ans = 0;
    for (i = 1; i <= n; i++) {
      ans = max(ans, res[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
