#include <bits/stdc++.h>
using namespace std;
int n;
char str[105];
int num[105];
char gra[505][505];
int main() {
  while (cin >> n) {
    memset(gra, 0, sizeof gra);
    cin >> str;
    num[0] = 1;
    int mx = 0;
    int tmp = 1;
    for (int i = 0; i < n - 1; i++) {
      num[i] = tmp;
      if (str[i] == '[' && str[i + 1] == '[')
        tmp++;
      else if (str[i] == ']' && str[i + 1] == ']')
        tmp--;
      mx = max(mx, num[i]);
    }
    num[n - 1] = 1;
    for (int i = 0; i < n; i++) num[i] = mx - num[i] + 1;
    int now = 0;
    int col = 0;
    while (now < n) {
      int i = num[now];
      for (int j = mx - i + 1; j <= mx + i - 1; j++) {
        gra[j][col] = '|';
      }
      gra[mx - i][col] = gra[mx + i][col] = '+';
      if (str[now] == '[')
        gra[mx - i][col + 1] = gra[mx + i][col + 1] = '-';
      else
        gra[mx - i][col - 1] = gra[mx + i][col - 1] = '-';
      if (str[now] == '[' && str[now + 1] == ']') col += 3;
      col++;
      now++;
    }
    for (int i = 0; i < 2 * mx + 1; i++)
      for (int j = 0; j < col; j++) {
        if (gra[i][j] != '+' && gra[i][j] != '|' && gra[i][j] != '-')
          gra[i][j] = ' ';
      }
    for (int i = 0; i < 2 * mx + 1; i++)
      for (int j = 0; j < col; j++) {
        printf(j == col - 1 ? "%c\n" : "%c", gra[i][j]);
      }
  }
}
