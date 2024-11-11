#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, num, exc = 0, cont = 10, t = 10;
  scanf("%d", &n);
  vector<int> nums;
  nums.clear();
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    nums.push_back(num);
  };
  sort(nums.begin(), nums.end());
  for (i = 0; i < n; i++) {
    if (cont + nums[i] <= 720)
      cont += nums[i];
    else {
      n = i;
      break;
    };
  };
  for (i = 0; i < n; i++) {
    t += nums[i];
    if (t > 360) {
      exc += t - 360;
    };
  };
  printf("%d %d\n", n, exc);
  return 0;
}
