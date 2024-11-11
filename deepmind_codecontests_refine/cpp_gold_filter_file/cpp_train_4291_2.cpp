#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> nums;
  int a = 0;
  for (int i = (0); i < (n); i++) {
    if (s[i] == 'B') a++;
  }
  if (a & 1 and !(n & 1)) {
    cout << -1 << endl;
    return 0;
  }
  if (a & 1) {
    for (int i = (0); i < (n - 1); i++) {
      if (s[i] == 'W') {
        s[i] = 'B';
        s[i + 1] = 'B' + 'W' - s[i + 1];
        nums.push_back(i);
      }
    }
  } else {
    for (int i = (0); i < (n - 1); i++) {
      if (s[i] == 'B') {
        s[i] = 'W';
        s[i + 1] = 'B' + 'W' - s[i + 1];
        nums.push_back(i);
      }
    }
  }
  cout << nums.size() << endl;
  for (int i = (0); i < (nums.size()); i++)
    cout << nums[i] + 1 << " \n"[i == nums.size() - 1];
}
