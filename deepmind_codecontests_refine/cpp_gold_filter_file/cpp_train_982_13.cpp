#include <bits/stdc++.h>
using namespace std;
int res[1005][1005];
int main() {
  int n, k, d, i, j;
  while (cin >> n >> k >> d) {
    int flag = 0;
    int t = 1;
    for (i = 0; i < d; i++) {
      t *= k;
      if (t >= n) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      puts("-1");
    } else {
      for (j = 0; j < n; j++) {
        for (i = 0; i < d; i++) {
          if (j == 0)
            res[i][j] = 1;
          else
            res[i][j] = res[i][j - 1];
        }
        if (j == 0) continue;
        res[d - 1][j]++;
        for (i = d - 1; i >= 0; i--) {
          if (res[i][j] > k) {
            res[i][j] %= k;
            res[i - 1][j]++;
          } else
            break;
        }
      }
      for (i = 0; i < d; i++) {
        for (j = 0; j < n; j++) {
          printf("%d ", res[i][j]);
        }
        printf("\n");
      }
    }
    return 0;
  }
}
