#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const double PI = 3.14159265;
int dpx[4] = {0, 1, 0, -1};
int dpy[4] = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(false);
  string str, ans;
  int at = 0;
  cin >> str;
  ans = str[0];
  for (int i = 1; i < str.size(); i++) {
    if (i + 3 < str.size() && str[i] == 'd' && str[i + 1] == 'o' &&
        str[i + 2] == 't') {
      ans += '.';
      i += 2;
    } else if (i + 2 < str.size() && str[i] == 'a' && str[i + 1] == 't' &&
               !at) {
      at = 1;
      ans += '@';
      i++;
    } else {
      ans += str[i];
    }
  }
  cout << ans;
}
