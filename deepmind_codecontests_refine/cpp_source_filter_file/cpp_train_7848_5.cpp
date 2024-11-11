#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += nums[i];
      ans += 2 * i * nums[i];
      ans += 2 * (i - n + 1) * nums[i];
    }
    long long den = n;
    for (int i = 2; i < den; i++) {
      if (i < den && i < ans && den % i == 0 && ans % i == 0) {
        den /= i;
        ans /= i;
      }
    }
    cout << ans << " " << den << endl;
  }
  return 0;
}
