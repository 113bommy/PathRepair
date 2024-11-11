#include <bits/stdc++.h>
using namespace std;
long long num[500001];
long long sum[779][779];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, x, y;
    scanf("%d %d %d", &p, &x, &y);
    if (p == 1) {
      num[x] += y;
      for (int i = 1; i <= 777; i++) {
        sum[i][x % i] += y;
      }
    } else {
      if (x <= 777) {
        printf("%ld\n", sum[x][y % x]);
      } else {
        long long ans = 0;
        for (int i = y % x; i <= 500000; i += x) {
          ans += num[i];
        }
        printf("%ld\n", ans);
      }
    }
  }
}
