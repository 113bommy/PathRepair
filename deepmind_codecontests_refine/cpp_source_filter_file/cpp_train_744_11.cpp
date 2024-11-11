#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>& nums) {
  int pos_one = -1;
  for (int i = 0; i < nums.size(); i++)
    if (nums[i] == 1) {
      pos_one = i;
      break;
    }
  bool left, right;
  left = right = true;
  for (int i = 1; i < nums.size(); i++) {
    left = nums[(pos_one - i + nums.size()) % nums.size()] == i + 1;
    right = nums[(pos_one + i + nums.size()) % nums.size()] == i + 1;
  }
  if (right || left)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n;
    vector<int> nums;
    cin >> n;
    while (n--) {
      int num;
      cin >> num;
      nums.push_back(num);
    }
    solve(nums);
  }
  return 0;
}
