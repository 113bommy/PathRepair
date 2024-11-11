#include <bits/stdc++.h>
using namespace std;
int n;
char s[100];
char field[12][12];
bool ok(const int x) { return (1 <= x && x <= 10); }
bool win(const int i, const int j) {
  int up = i, down = i, left = j, right = j;
  int up_left = i, down_right = i, up_right = i, down_left = i;
  int left_up = j, right_down = j, right_up = j, left_down = j;
  while (ok(up - 1) && field[up - 1][j] == 'X') up--;
  while (ok(down + 1) && field[down + 1][j] == 'X') down++;
  while (ok(left - 1) && field[i][left - 1] == 'X') left--;
  while (ok(right + 1) && field[i][right + 1] == 'X') right++;
  while (ok(up_left - 1) && ok(left_up - 1) &&
         field[up_left - 1][j - 1] == 'X') {
    up_left--;
    left_up--;
  }
  while (ok(down_right + 1) && ok(right_down + 1) &&
         field[down_right + 1][right_down + 1] == 'X') {
    down_right++;
    right_down++;
  }
  while (ok(up_right - 1) && ok(right_up + 1) &&
         field[up_right - 1][right_up + 1] == 'X') {
    up_right--;
    right_up++;
  }
  while (ok(down_left + 1) && ok(left_down - 1) &&
         field[down_left + 1][left_down - 1] == 'X') {
    down_left++;
    left_down--;
  }
  if (down - up + 1 >= 5 || right - left + 1 >= 5 ||
      down_right - up_left + 1 >= 5 || down_left - up_right + 1 >= 5)
    return true;
  else
    return false;
}
int main() {
  for (int i = 1; i <= 10; i++) {
    scanf("%s", s);
    for (int j = 1; j <= 10; j++) field[i][j] = s[j - 1];
  }
  bool flag = false;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      if (field[i][j] == '.' && win(i, j)) {
        flag = true;
        break;
      }
  if (flag)
    printf("YES");
  else
    printf("NO");
  return 0;
}
