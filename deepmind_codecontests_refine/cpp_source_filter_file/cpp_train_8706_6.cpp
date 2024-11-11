#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k1, k2, k3;
  vector<int> nums(5, 0);
  cin >> k1 >> k2 >> k3;
  if (k1 <= 4) {
    nums[k1]++;
  }
  if (k2 <= 4) {
    nums[k2]++;
  }
  if (k3 <= 4) {
    nums[k3]++;
  }
  if (nums[1] > 0 || nums[2] == 2 || nums[3] == 3 ||
      (nums[2] == 1 && nums[4] == 2)) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
