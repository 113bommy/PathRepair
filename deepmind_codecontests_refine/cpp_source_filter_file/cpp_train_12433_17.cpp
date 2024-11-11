#include <bits/stdc++.h>
using namespace std;
char g[4][4];
int Judge() {
  int X = 0;
  int O = 0;
  if (g[0][0] == 'X' && g[0][1] == 'X' && g[0][2] == 'X')
    X = 1;
  else if (g[0][0] == 'X' && g[1][1] == 'X' && g[2][2] == 'X')
    X = 1;
  else if (g[0][0] == 'X' && g[1][0] == 'X' && g[2][0] == 'X')
    X = 1;
  else if (g[1][0] == 'X' && g[1][1] == 'X' && g[1][2] == 'X')
    X = 1;
  else if (g[2][0] == 'X' && g[2][1] == 'X' && g[2][2] == 'X')
    X = 1;
  else if (g[0][1] == 'X' && g[1][1] == 'X' && g[2][1] == 'X')
    X = 1;
  else if (g[0][2] == 'X' && g[1][2] == 'X' && g[2][2] == 'X')
    X = 1;
  else if (g[0][2] == 'X' && g[1][1] == 'X' && g[2][0] == 'X')
    X = 1;
  if (g[0][0] == '0' && g[0][1] == '0' && g[0][2] == '0')
    O = 2;
  else if (g[0][0] == '0' && g[1][1] == '0' && g[2][2] == '0')
    O = 2;
  else if (g[0][0] == '0' && g[1][0] == '0' && g[2][0] == '0')
    O = 2;
  else if (g[1][0] == '0' && g[1][1] == '0' && g[1][2] == '0')
    O = 2;
  else if (g[2][0] == '0' && g[2][1] == '0' && g[2][2] == '0')
    O = 2;
  else if (g[0][1] == '0' && g[1][1] == '0' && g[2][1] == '0')
    O = 2;
  else if (g[0][2] == '0' && g[1][2] == '0' && g[2][2] == '0')
    O = 2;
  else if (g[0][2] == '0' && g[1][1] == '0' && g[2][0] == '0')
    O = 2;
  return X + O;
}
int main() {
  int i, j;
  for (i = 0; i < 3; i++) scanf("%s", g[i]);
  int cntX = 0, cnt = 0;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
      if (g[i][j] == 'X') cntX++;
      if (g[i][j] == '0') cnt++;
    }
  int t = Judge();
  if (cntX + cnt == 9 && t == 0)
    cout << "draw" << endl;
  else if (cntX == cnt && t == 0)
    cout << "first" << endl;
  else if (cntX == cnt + 1 && t == 0)
    cout << "second" << endl;
  else if (cntX == cnt + 1 && t == 1)
    cout << "the first player won" << endl;
  else if (cntX = cnt && t == 2)
    cout << "the second player won " << endl;
  else
    cout << "illegal" << endl;
  return 0;
}
