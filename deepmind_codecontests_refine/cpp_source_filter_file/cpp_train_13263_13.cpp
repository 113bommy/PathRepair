#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
void parse(string s) {
  stringstream ss(s);
  int num;
  char co;
  while (ss >> num) {
    nums.push_back(num), ss >> co;
  }
}
int main() {
  int i, a = 0;
  string s;
  cin >> s;
  parse(s);
  sort(nums.begin(), nums.end());
  bool exit = false;
  for (i = 0; i < nums.size(); i++) {
    if (i == nums.size() - 1) {
      if (exit)
        cout << nums[a] << "-" << nums[s.size() - 1] << endl;
      else {
        cout << nums[a] << endl;
      }
    }
    if (i + 1 >= nums.size()) break;
    if ((nums[i + 1] - '0') - (nums[i] - '0') <= 1) {
      if (nums[i + 1] != nums[i]) exit = true;
    } else {
      if (exit) {
        cout << nums[a] << "-" << nums[i] << ",";
      } else {
        cout << nums[a] << ",";
      }
      a = i + 1;
      exit = false;
    }
  }
  return 0;
}
