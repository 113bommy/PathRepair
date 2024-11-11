#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, x0 = 0, y0 = 0, k = 1, ans = 1;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') x--;
    if (s[i] == 'R') x++;
    if (s[i] == 'D') y--;
    if (s[i] == 'U') y++;
    if (abs(x - x0) + abs(y - y0) < k) {
      ans++;
      k = 1;
      x0 = x;
      if (s[i] == 'L') x0++;
      if (s[i] == 'R') x0--;
      y0 = y;
      if (s[i] == 'D') y0++;
      if (s[i] == 'U') y0--;
    } else
      k++;
  }
  printf("%d", ans);
  return 0;
}
