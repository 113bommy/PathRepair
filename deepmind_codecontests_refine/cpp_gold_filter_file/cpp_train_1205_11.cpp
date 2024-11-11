#include <bits/stdc++.h>
using namespace std;
const int N = 57;
const int M = 1e6;
int n, m, A[M][2], tota, B[M][2], totb, flag;
char s[N][N], t[N][N];
void swp(int x, int y) {
  if (s[x][y] == 'U') {
    s[x][y] = 'L', s[x][y + 1] = 'R';
    s[x + 1][y] = 'L', s[x + 1][y + 1] = 'R';
  } else {
    s[x][y] = 'U', s[x + 1][y] = 'D';
    s[x][y + 1] = 'U', s[x + 1][y + 1] = 'D';
  }
  if (!flag)
    ++tota, A[tota][0] = x, A[tota][1] = y;
  else
    ++totb, B[totb][0] = x, B[totb][1] = y;
}
void work(int x, int y) {
  if (s[x][y] == 'U') {
    if (s[x][y + 1] == 'U')
      swp(x, y);
    else
      work(x, y + 1), swp(x, y);
  } else {
    if (s[x + 1][y] == 'L')
      swp(x, y);
    else
      work(x + 1, y), swp(x, y);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, iE = n; i <= iE; i++) cin >> (s[i] + 1);
  for (int i = 1, iE = n; i <= iE; i++) cin >> (t[i] + 1);
  if (n % 2 == 0) {
    for (int i = 1, iE = n; i <= iE; i++)
      for (int j = 1, jE = m; j <= jE; j++)
        if (s[i][j] == 'L') work(i, j);
  } else {
    for (int i = 1, iE = n; i <= iE; i++)
      for (int j = 1, jE = m; j <= jE; j++)
        if (s[i][j] == 'U') work(i, j);
  }
  for (int i = 1, iE = n; i <= iE; i++)
    for (int j = 1, jE = m; j <= jE; j++) s[i][j] = t[i][j];
  flag = 1;
  if (n % 2 == 0) {
    for (int i = 1, iE = n; i <= iE; i++)
      for (int j = 1, jE = m; j <= jE; j++)
        if (s[i][j] == 'L') work(i, j);
  } else {
    for (int i = 1, iE = n; i <= iE; i++)
      for (int j = 1, jE = m; j <= jE; j++)
        if (s[i][j] == 'U') work(i, j);
  }
  cout << tota + totb << endl;
  for (int i = 1, iE = tota; i <= iE; i++)
    cout << A[i][0] << " " << A[i][1] << endl;
  for (int i = totb, iE = 1; i >= iE; i--)
    cout << B[i][0] << " " << B[i][1] << endl;
  return 0;
}
