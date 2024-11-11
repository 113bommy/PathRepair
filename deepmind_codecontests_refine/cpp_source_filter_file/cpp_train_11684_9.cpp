#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums;
    bool foundEven = false;
    bool evenIndex = -1;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      if (num % 2 == 0) {
        foundEven = true;
        evenIndex = i;
      } else {
        nums.push_back(num);
      }
    }
    if (foundEven) {
      cout << "1"
           << "\n";
      cout << evenIndex + 1 << "\n";
    } else {
      int total = 0;
      int endingIndex = -1;
      for (int i = 0; i < nums.size(); i++) {
        total += nums[i];
        if (total % 2 == 0) {
          endingIndex = i;
          break;
        }
      }
      if (endingIndex == -1) {
        cout << "-1"
             << "\n";
      } else {
        cout << endingIndex + 1 << "\n";
        for (int i = 1; i <= endingIndex + 1; i++) {
          cout << i << " ";
        }
        cout << "\n";
      }
    }
  }
}
