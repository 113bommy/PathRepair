#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string str;
  int ans = 0;
  cin >> str >> k;
  if (k >= str.size())
    cout << (k + str.size()) / 2 << endl;
  else {
    ans = k + k;
    for (int i = 1; i < str.size(); i++) {
      for (int j = 0; j < i; j++) {
        int x = i - j;
        if (i + x - 1 >= str.size() + k) continue;
        bool f = false;
        for (int k = 0; k < x; k++) {
          if (i + k >= str.size())
            continue;
          else if (str[i + k] != str[j + k])
            f = true;
        }
        if (f) continue;
        ans = max(ans, x + x);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
