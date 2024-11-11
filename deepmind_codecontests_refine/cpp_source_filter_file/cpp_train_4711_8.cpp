#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &nums[i]);
    }
    sort(nums.begin(), nums.end());
    int result = 0x3f;
    for (int i = 1; i < n; i++) {
      result = min(result, abs(nums[i] - nums[i - 1]));
    }
    printf("%d\n", result);
  }
}
