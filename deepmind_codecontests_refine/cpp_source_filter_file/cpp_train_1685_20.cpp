#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    deque<int> list;
    int nums;
    cin >> nums;
    int ans = 0;
    for (int i = 0; i < nums; i++) {
      int misc;
      cin >> misc;
      if (list.empty()) {
        list.push_back(misc);
        continue;
      }
      if (list.back() < misc) {
        list.push_back(misc);
        continue;
      }
      if (list.back() > misc) {
        while (!list.empty() and list.back() > misc) {
          ans++;
          list.pop_back();
        }
        list.push_back(misc);
        continue;
      }
    }
    cout << ans << endl;
  }
}
