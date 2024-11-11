#include <bits/stdc++.h>
using namespace std;
int d[100];
char ans[3000][3000];
int main() {
  int32_t n;
  cin >> n;
  string s;
  cin >> s;
  int32_t g = 0, mx = 0;
  for (auto i : s) {
    if (i == '[')
      ++g;
    else
      mx = max(mx, g--);
  }
  d[mx] = 1;
  for (int32_t i = mx - 1; i > 0; --i) {
    d[i] = d[i + 1] + 2;
  }
  n = d[1] + 2;
  int32_t m = 0;
  for (int32_t i = 0; i < n; ++i) fill(ans[i], ans[i] + 3000, ' ');
  g = 0;
  bool open = false;
  for (int32_t i = 0; i < s.size(); ++i, ++m) {
    if (s[i] == '[') {
      ++g;
      ans[g - 1][m] = '+';
      ans[g - 1][m + 1] = '-';
      for (int32_t j = g; j < g + d[g]; ++j) ans[j][m] = '|';
      ans[g + d[g]][m] = '+';
      ans[g + d[g]][m + 1] = '-';
      open = true;
    } else {
      if (open) m += 3;
      open = false;
      ans[g - 1][m] = '+';
      ans[g - 1][m - 1] = '-';
      for (int32_t j = g; j < g + d[g]; ++j) ans[j][m] = '|';
      ans[g + d[g]][m] = '+';
      ans[g + d[g]][m - 1] = '-';
      --g;
    }
  }
  for (int32_t i = 0; i < n; ++i) {
    for (int32_t j = 0; j < m; ++j) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
