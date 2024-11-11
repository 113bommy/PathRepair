#include <bits/stdc++.h>
using namespace std;
const int N = 505;
char mp[N][N];
int r, c;
int main() {
  scanf("%d%d", &r, &c);
  bool flag = 1;
  for (int i = 1; i <= r; ++i) {
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= c; ++j) {
      if (j != c && mp[i][j] + mp[i][j + 1] == 'S' + 'W') flag = 0;
      if (i != r && mp[i][j] + mp[i + 1][j] == 'S' + 'W') flag = 0;
    }
  }
  if (flag) {
    puts("Yes");
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) putchar(mp[i][j] == '.' ? 'D' : mp[i][j]);
      putchar('\n');
    }
  } else {
    puts("No");
  }
  return 0;
}
