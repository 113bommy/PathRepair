#include <bits/stdc++.h>
int map[40][40];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int num1 = 0;
      int num2 = 0;
      for (int k = 0; k < n; k++) num1 += map[i][k];
      for (int k = 0; k < n; k++) num2 += map[k][j];
      if (num1 > num2) ans++;
    }
  }
  printf("%d\n", ans);
}
