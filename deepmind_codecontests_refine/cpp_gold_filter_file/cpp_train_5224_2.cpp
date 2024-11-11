#include <bits/stdc++.h>
using namespace std;
const int sz = (int)(1e6 + 1);
const int mod = (int)(1e9 + 7);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool ans[10];
  fill_n(ans, 10, false);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      for (int j = 0; j < 10; j++) {
        if (ans[j] == false) {
          ans[j] = true;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (ans[j] == false) {
          ans[j] = true;
          break;
        }
      }
    } else {
      ans[s[i] - '0'] = false;
    }
  }
  for (const bool &r : ans) {
    cout << r;
  }
  cout << endl;
}
