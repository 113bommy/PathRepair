#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int x = 0, y = 0;
    int max_x = 0;
    int max_y = 0;
    int min_x = 0;
    int min_y = 0;
    int l_min_x = -1;
    int l_min_y = -1;
    int l_max_x = -1;
    int l_max_y = -1;
    int r_min_x = -1;
    int r_min_y = -1;
    int r_max_x = -1;
    int r_max_y = -1;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == 'W') {
        ++y;
      } else if (c == 'A') {
        --x;
      } else if (c == 'S') {
        --y;
      } else {
        ++x;
      }
      if (x > max_x) {
        max_x = x;
        l_max_x = r_max_x = i;
      } else if (x == max_x) {
        r_max_x = i;
      }
      if (y > max_y) {
        max_y = y;
        l_max_y = r_max_y = i;
      } else if (y == max_y) {
        r_max_y = i;
      }
      if (x < min_x) {
        min_x = x;
        l_min_x = r_min_x = i;
      } else if (x == r_min_x) {
        r_min_x = i;
      }
      if (y < min_y) {
        min_y = y;
        l_min_y = r_min_y = i;
      } else if (y == r_min_y) {
        r_min_y = i;
      }
    }
    long long ans = 1LL * (max_x - min_x + 1) * (max_y - min_y + 1);
    if (max_x - min_x > 1 && (r_min_x < l_max_x || r_max_x < l_min_x)) {
      ans = min(ans, 1LL * (max_x - min_x) * (max_y - min_y + 1));
    }
    if (max_y - min_y > 1 && (r_min_y < l_max_y || r_max_y < l_min_y)) {
      ans = min(ans, 1LL * (max_x - min_x + 1) * (max_y - min_y));
    }
    cout << ans << '\n';
  }
}
