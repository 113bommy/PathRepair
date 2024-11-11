#include <bits/stdc++.h>
using namespace std;
char a[8][8];
int wmove, bmove;
int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      scanf("%c", &a[i][j]);
    }
    scanf("\n");
  }
  wmove = 8;
  bmove = 8;
  int i;
  for (int j = 0; j < 8; j++) {
    i = 0;
    while (i < 8 && a[i][j] == '.') i++;
    if (i < 8 && a[i][j] == 'W') wmove = min(i, wmove);
    i = 7;
    while (i >= 0 && a[i][j] == '.') i--;
    if (i >= 0 && a[i][j] == 'B') bmove = min(7 - i, bmove);
  }
  if (wmove <= bmove)
    puts("A");
  else
    puts("B");
}
