#include <bits/stdc++.h>
int main() {
  int num, i, k;
  int sum = 0;
  int Array[102][102] = {0};
  scanf("%d", &num);
  for (i = 0; i < num; i++)
    for (k = 0; k < num; k++) scanf("%d", &Array[i][k]);
  for (i = 0; i < num; i++) sum += Array[i][(num - 1) / 2];
  for (i = 0; i < num; i++) sum += Array[(num - 1) / 2][i];
  for (i = 0; i < num; i++) sum += Array[i][i];
  for (i = 0; i < num; i++) sum += Array[i][num - i - 1];
  sum -= 3 * Array[(num - 1) / 2][(num - 1) / 2];
  printf("%d", sum);
  return 0;
}
