#include <bits/stdc++.h>
using namespace std;
int mp[2030][2030];
long long k1[2030 * 2], k2[2030 * 2], val[2030][2030];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(k1, 0, sizeof(k1));
    memset(k2, 0, sizeof(k2));
    memset(val, 0, sizeof(val));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &mp[i][j]);
        k1[i - j + 2030] += mp[i][j];
        k2[i + j] += mp[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        val[i][j] = k1[i - j + 2030] + k2[i + j] - mp[i][j];
      }
    }
    int x1, x2, y1, y2;
    long long tem1 = 0, tem2 = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if ((i + j) % 2 == 0) {
          if (val[i][j] >= tem1) {
            x1 = i;
            y1 = j;
            tem1 = val[i][j];
          }
        } else {
          if (val[i][j] >= tem2) {
            x2 = i;
            y2 = j;
            tem2 = val[i][j];
          }
        }
      }
    }
    printf("%I64d\n", tem1 + tem2);
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
}
