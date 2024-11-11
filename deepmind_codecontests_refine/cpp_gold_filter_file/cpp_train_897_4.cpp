#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < (int)(n); i++) {
    b[i] = a[i] - i;
  }
  for (int i = n - 2; i >= 0; i--) {
    b[i] = max(b[i], b[i + 1]);
  }
  long long ans = 0;
  vector<int> nums(n);
  nums[0] = 1;
  for (int i = (int)(1); i < (int)(n); i++) {
    nums[i] = max(nums[i - 1], i + b[i] + 1);
    ans += nums[i] - a[i] - 1;
  }
  cout << ans << endl;
  return 0;
}
