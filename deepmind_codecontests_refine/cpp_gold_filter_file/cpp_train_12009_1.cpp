#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  long long ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    if (nums[i] < nums[i - 1]) {
      ans += (nums[i - 1] - nums[i]);
    }
  }
  cout << ans << '\n';
}
