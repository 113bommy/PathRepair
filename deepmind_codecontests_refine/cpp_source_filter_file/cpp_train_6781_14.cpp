#include <bits/stdc++.h>
using namespace std;
int last[100005];
int main() {
  int n;
  for (n = 1; n <= 100000; n++) last[n] = -1;
  scanf("%d", &n);
  int q, x, y;
  for (q = 1; q <= n; q++) {
    scanf("%d%d", &x, &y);
    int ans = 0;
    int j;
    for (j = 1; j * j <= x; j++) {
      if (n % j == 0) {
        if (last[j] < q - y) ans++;
        last[j] = q;
        int u = n / j;
        if (u != j) {
          if (last[u] < q - y) ans++;
          last[u] = q;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
