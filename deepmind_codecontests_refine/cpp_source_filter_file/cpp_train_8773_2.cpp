#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 1e6;
const long long ff = 1e5 + 1;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    int dec = 0;
    for (int i = n - 2; i > 0; i--) {
      nums[i] -= dec;
      if (nums[i] > nums[i + 1]) {
        dec += (nums[i] - nums[i + 1]);
        nums[i] = nums[i + 1];
      }
    }
    bool iv = false;
    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) {
        iv = true;
        break;
      }
    }
    if (iv) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
