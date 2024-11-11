#include <bits/stdc++.h>
int num;
int left_sum[51], right_sum[51];
void for_rightsum(int i) {
  if (i == num - 1) return;
  int temp;
  scanf("%d", &temp);
  for_rightsum(i + 1);
  right_sum[i] = right_sum[i + 1] + temp;
}
int main() {
  int i, temp;
  int min1, min2;
  int ans;
  scanf("%d", &num);
  min1 = min2 = 1000;
  for (i = 0; i < num - 1; i++) {
    scanf("%d", &temp);
    left_sum[i + 1] = left_sum[i] + temp;
  }
  for_rightsum(0);
  for (i = 0; i < num; i++) {
    scanf("%d", &temp);
    ans = left_sum[i] + right_sum[i] + temp;
    if (min1 >= ans) {
      min2 = min1;
      min1 = ans;
    } else if (min2 > ans)
      min2 = ans;
  }
  printf("%d\n", min1 + min2);
  return 0;
}
