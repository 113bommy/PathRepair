#include <bits/stdc++.h>
using namespace std;
int sign(int x) {
  if (x > 0) {
    return 1;
  }
  return -1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& i : nums) {
      cin >> i;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int curr = nums[i];
      int j = i;
      while (j < n && sign(nums[i]) == sign(nums[j])) {
        curr = max(curr, nums[j]);
        ++j;
      }
      sum += curr;
      i = j - 1;
    }
    cout << sum << endl;
  }
  return 0;
}
