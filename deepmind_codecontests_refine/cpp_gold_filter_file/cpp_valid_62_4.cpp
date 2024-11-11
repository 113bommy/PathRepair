#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    cin >> k;
    bool already_ok = false;
    bool left_down = false;
    vector<int> ans;
    int cur = -1;
    for (int j = 0; j < k; ++j) {
      std::cin >> cur;
      if (cur == 0) {
        left_down = true;
      } else if (!already_ok && left_down && cur == 1) {
        already_ok = true;
        ans.push_back(k);
      }
      ans.push_back(j);
    }
    if (!already_ok) {
      if (!left_down) {
        cout << k + 1 << ' ';
        for (auto& i : ans) {
          cout << i + 1 << ' ';
        }
      } else {
        for (auto& i : ans) {
          cout << i + 1 << ' ';
        }
        cout << k + 1 << ' ';
      }
    } else {
      for (auto& i : ans) {
        cout << i + 1 << ' ';
      }
    }
    cout << std::endl;
  }
  return 0;
}
