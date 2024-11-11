#include <bits/stdc++.h>
using namespace std;
int top[1000005], bottom[1000005], left_[1000005], right_[1000005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int r, c;
    int cur_x = 0, cur_y = 0;
    cin >> r >> c;
    string s;
    cin >> s;
    int num_commands = s.length();
    for (int i = 0; i < num_commands; i++) {
      if (s[i] == 'L') cur_x--;
      if (s[i] == 'R') cur_x++;
      if (s[i] == 'U') cur_y++;
      if (s[i] == 'D') cur_y--;
      top[i + 1] = max(top[i], cur_y);
      bottom[i + 1] = min(bottom[i], cur_y);
      left_[i + 1] = min(left_[i], cur_x);
      right_[i + 1] = max(right_[i], cur_x);
    }
    int i = 1;
    for (; i < num_commands + 1; i++) {
      if ((top[i] - bottom[i]) >= r || right_[i] - left_[i] >= c) {
        break;
      }
    }
    cout << top[i - 1] + 1 << " " << -left_[i - 1] + 1;
  }
  return 0;
}
