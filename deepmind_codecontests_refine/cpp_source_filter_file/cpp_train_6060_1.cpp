#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a[2][3];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++) scanf("%d", &a[i][j]);
    int d[8];
    for (int i = 1; i <= 7; i++) scanf("%d", &d[i]);
    for (int i = 0; i <= d[2]; i++) {
      for (int j = 0; j <= d[3]; j++) {
        for (int k = 0; k <= d[5]; k++) {
          int first = a[0][0] - i - j, second = a[0][1] - i - k,
              z = a[0][2] - j - k;
          if (first < 0 || second < 0 || z < 0) break;
          int Min = min(min(first, min(first, second)), d[1]);
          first -= Min, second -= Min, z -= Min;
          first = min(first, d[4]);
          second = min(second, d[6]);
          z = min(z, d[7]);
          int f[8];
          f[1] = d[1] - Min;
          f[2] = d[2] - i;
          f[3] = d[3] - j;
          f[4] = d[4] - first;
          f[5] = d[5] - k;
          f[6] = d[6] - second;
          f[7] = d[7] - z;
          if (f[1] + f[2] + f[3] + f[4] <= a[1][0] &&
              f[1] + f[2] + f[5] + f[6] <= a[1][1] &&
              f[1] + f[3] + f[5] + f[7] <= a[1][2]) {
            printf("%d %d %d %d %d %d %d\n", Min, i, j, first, k, second, z);
            goto end;
          }
        }
      }
    }
    printf("-1\n");
  end:
    continue;
  }
}
