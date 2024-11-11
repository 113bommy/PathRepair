#include <bits/stdc++.h>
using namespace std;
char a[4][4];
int num(char c) {
  int i, j, k = 0;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (a[i][j] == c) k++;
  return k;
}
int check(char c) {
  if (a[0][0] == c && a[0][1] == c && a[0][2] == c) return 1;
  if (a[1][0] == c && a[1][1] == c && a[1][2] == c) return 2;
  if (a[2][0] == c && a[2][1] == c && a[2][2] == c) return 3;
  if (a[0][0] == c && a[1][0] == c && a[2][0] == c) return 4;
  if (a[0][1] == c && a[1][1] == c && a[2][1] == c) return 5;
  if (a[0][2] == c && a[1][2] == c && a[2][2] == c) return 6;
  if (a[0][0] == c && a[1][1] == c && a[2][2] == c) return 7;
  if (a[2][0] == c && a[1][1] == c && a[0][2] == c) return 8;
  return 0;
}
string gao() {
  if (num('X') < num('0') || num('X') > num('0') + 1) return "illegal";
  if (check('X') && check('0')) return "illegal";
  if (num('X') == num('0') && check('X')) return "illegal";
  if (num('X') == num('0') + 1 && check('0')) return "illegal";
  if (check('X')) return "the first player won";
  if (check('0')) return "the second player won";
  if (num('X') + num('0') == 9) return "draw";
  if (num('X') == num('0')) return "first";
  return "second";
}
int main() {
  for (int i = 0; i < 3; i++) scanf("%s", a[i]);
  puts(gao().c_str());
  scanf("%*d");
}
