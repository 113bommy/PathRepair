#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int nums[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums, nums + n);
  int sn = 0;
  for (int i = 0; i < n - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      sn++;
      i++;
    }
  }
  cout << sn / 2 << endl;
  return 0;
}
