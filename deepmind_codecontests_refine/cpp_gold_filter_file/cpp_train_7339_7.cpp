#include <bits/stdc++.h>
char mp[9][9];
int min(int a, int b) { return a < b ? a : b; }
int main() {
  for (int i = 1; i <= 8; ++i) scanf("%s", mp[i] + 1);
  int ans1 = 10, ans2 = 10;
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      if (mp[j][i] == 'B')
        break;
      else if (mp[j][i] == 'W') {
        ans1 = min(ans1, j - 1);
        break;
      }
    }
    for (int j = 8; j >= 1; --j) {
      if (mp[j][i] == 'W')
        break;
      else if (mp[j][i] == 'B') {
        ans2 = min(ans2, 8 - j);
        break;
      }
    }
  }
  printf("%c\n", ans1 <= ans2 ? 'A' : 'B');
  return 0;
}
