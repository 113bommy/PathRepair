#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int *nums = (int *)malloc(sizeof(int) * n), j = 0;
  long long sum = 0;
  for (; j < n; ++j) {
    scanf("%d", &nums[j]);
    sum += nums[j];
  }
  long long pref = 0;
  for (j = 0; j < n; ++j) {
    pref += nums[j];
    if (pref * 2 >= sum) {
      printf("%d", j + 1);
      break;
    }
  }
  free(nums);
  return 0;
}
