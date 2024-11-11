#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 200000;
    int n = s.length();
    int flag_one = 0;
    int flag_two = 0;
    int flag_three = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        flag_one = 1;
      else if (s[i] == '2')
        flag_two = 1;
      else if (s[i] == '3')
        flag_three = 1;
    }
    if (flag_one == 0 || flag_two == 0 || flag_three == 0)
      cout << "0" << endl;
    else {
      int ans = 200000;
      int one = 0;
      int two = 0;
      int three = 0;
      int temp;
      int temp0;
      int index_one;
      int index_two;
      int index_three;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          one = 1;
          index_one = i;
        }
        if (s[i] == '2') {
          two = 1;
          index_two = i;
        }
        if (s[i] == '3') {
          three = 1;
          index_three = i;
        }
        if (one && two && three) {
          temp = max(max(index_one, index_two), index_three);
          temp0 = min(min(index_one, index_two), index_three);
          ans = min(ans, temp - temp0);
        }
      }
      cout << ans << endl;
    }
  }
}
