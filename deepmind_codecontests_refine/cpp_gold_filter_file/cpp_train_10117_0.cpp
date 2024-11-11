#include <bits/stdc++.h>
using namespace std;
long long arr[500500];
long long pre[1000][1000];
int main() {
  int sq = sqrt(500500);
  int q;
  scanf("%d", &q);
  int tp, x, y;
  while (q--) {
    scanf("%d %d %d", &tp, &x, &y);
    if (tp == 1) {
      arr[x] += y;
      for (int i = 1; i < sq; i++) pre[i][x % i] += y;
    } else {
      long long ans = 0;
      if (x >= sq) {
        for (int i = y; i < 500500; i += x) ans += arr[i];
      } else {
        ans = pre[x][y];
      }
      printf("%lld\n", ans);
    }
  }
}
