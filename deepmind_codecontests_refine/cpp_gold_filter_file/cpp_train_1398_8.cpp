#include <bits/stdc++.h>
using namespace std;
const int N = 9;
int flag[N][N];
struct step {
  int x, y;
};
step s[N];
int main() {
  s[0].x = 2, s[0].y = 1;
  s[1].x = 1, s[1].y = 2;
  s[2].x = -1, s[2].y = 2;
  s[3].x = -2, s[3].y = 1;
  s[4].x = -2, s[4].y = -1;
  s[5].x = -1, s[5].y = -2;
  s[6].x = 1, s[6].y = -2;
  s[7].x = 2, s[7].y = -1;
  int i, j, k, ans;
  int x_1, x_2, y_1, y_2;
  char temp[2];
  while (scanf("%s%*c", temp) != EOF) {
    ans = 0;
    memset(flag, 0, sizeof(flag));
    x_1 = temp[0] - 'a' + 1;
    y_1 = temp[1] - '0';
    scanf("%s%*c", temp);
    x_2 = temp[0] - 'a' + 1;
    y_2 = temp[1] - '0';
    flag[y_2][x_2] = 1;
    flag[y_1][x_1] = 1;
    for (i = 1; i < 9; i++) {
      flag[i][x_1] = 1;
      flag[y_1][i] = 1;
    }
    for (i = 0; i < 8; i++) {
      j = x_2 + s[i].x;
      k = y_2 + s[i].y;
      if (j > 0 && j < 9 && k > 0 && k < 9) flag[k][j] = 1;
      j = x_1 + s[i].x;
      k = y_1 + s[i].y;
      if (j > 0 && j < 9 && k > 0 && k < 9) flag[k][j] = 1;
    }
    for (i = 1; i < 9; i++)
      for (j = 1; j < 9; j++)
        if (flag[i][j] == 0) ans++;
    cout << ans << endl;
  }
  return 0;
}
