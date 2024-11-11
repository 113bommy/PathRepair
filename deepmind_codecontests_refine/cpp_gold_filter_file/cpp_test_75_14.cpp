#include <bits/stdc++.h>
using namespace std;
string Negate(const string& name) {
  if (name == "Alice") {
    return "Bob";
  }
  return "Alice";
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums[i] = temp;
  }
  int left_count = 1;
  while (nums[left_count] > nums[left_count - 1]) {
    ++left_count;
  }
  int right_count = 1;
  while (nums[n - 1 - right_count] > nums[n - right_count]) {
    ++right_count;
  }
  string current_player = "Alice";
  int left_idx = 0;
  int right_idx = n - 1;
  int current_max = -1;
  while (true) {
    if (nums[left_idx] <= current_max && nums[right_idx] <= current_max) {
      cout << Negate(current_player) << endl;
      return 0;
    }
    if (nums[left_idx] == nums[right_idx]) {
      if (left_count % 2 == 0 && right_count % 2 == 0) {
        cout << Negate(current_player) << endl;
        return 0;
      }
      cout << current_player << endl;
      return 0;
    }
    if (nums[left_idx] > nums[right_idx]) {
      if (left_count % 2 == 1) {
        cout << current_player << endl;
        return 0;
      }
      if (nums[right_idx] <= current_max) {
        cout << Negate(current_player) << endl;
        return 0;
      }
      current_max = nums[right_idx];
      --right_idx;
      --right_count;
      current_player = Negate(current_player);
    } else {
      if (right_count % 2 == 1) {
        cout << current_player << endl;
        return 0;
      }
      if (nums[left_idx] <= current_max) {
        cout << Negate(current_player) << endl;
        return 0;
      }
      current_max = nums[left_idx];
      ++left_idx;
      --left_count;
      current_player = Negate(current_player);
    }
  }
}
