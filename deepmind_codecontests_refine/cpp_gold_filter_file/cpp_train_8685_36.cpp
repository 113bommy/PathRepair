#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, z, flag;
  int ans1, ans2, ans3, ans4;
  int temp;
  scanf("%d%d", &n, &m);
  flag = 0;
  for (i = 1; i <= 50; i++) {
    for (j = 1; j <= 50; j++) {
      for (k = 1; k <= 50; k++) {
        for (z = 1; z <= 50; z++) {
          temp = sqrt(i * i * (n - 1) + j * j);
          if (temp * temp != (i * i * (n - 1) + j * j)) continue;
          temp = sqrt(i * i * (m - 1) + k * k);
          if (temp * temp != (i * i * (m - 1) + k * k)) continue;
          temp = sqrt(j * j * (m - 1) + z * z);
          if (temp * temp != (j * j * (m - 1) + z * z)) continue;
          temp = sqrt(k * k * (n - 1) + z * z);
          if (temp * temp != (k * k * (n - 1) + z * z)) continue;
          flag = 1;
          ans1 = i;
          ans2 = j;
          ans3 = k;
          ans4 = z;
          break;
        }
        if (flag == 1) break;
      }
      if (flag == 1) break;
    }
    if (flag == 1) break;
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j < m; j++) printf("%d ", ans1);
    printf("%d\n", ans3);
  }
  for (i = 1; i < m; i++) printf("%d ", ans2);
  printf("%d\n", ans4);
  return 0;
}
