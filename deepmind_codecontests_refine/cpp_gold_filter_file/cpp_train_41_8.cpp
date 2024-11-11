#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, r;
  cin >> k;
  deque<int> ans;
  for (int i = 1; i < k; i++) {
    for (int j = 1; j < k; j++) {
      r = i * j;
      if (r >= k) {
        while (r >= k) {
          ans.push_front(r % k);
          r /= k;
        }
        ans.push_front(r);
        while (ans.size()) {
          cout << ans.front();
          ans.pop_front();
        }
      } else {
        cout << r;
      }
      cout << " ";
    }
    cout << endl;
  }
}
