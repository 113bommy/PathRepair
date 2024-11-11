#include <bits/stdc++.h>
using namespace std;
char s[52][52];
int viz[52][52];
int n, m;
void fil(int i, int j) {
  s[i][j] = '.';
  viz[i][j] = 1;
  if (i + 1 <= n && s[i + 1][j] != '#' && s[i + 1][j] != 'B' &&
      viz[i + 1][j] == 0)
    fil(i + 1, j);
  if (i - 1 >= 1 && s[i - 1][j] != '#' && s[i - 1][j] != 'B' &&
      viz[i - 1][j] == 0)
    fil(i - 1, j);
  if (j + 1 <= m && s[i][j + 1] != '#' && s[i][j + 1] != 'B' &&
      viz[i][j + 1] == 0)
    fil(i, j + 1);
  if (j - 1 >= 1 && s[i][j - 1] != '#' && s[i][j - 1] != 'B' &&
      viz[i][j - 1] == 0)
    fil(i, j - 1);
}
int main() {
  int t, l, i, j, ok;
  cin >> t;
  for (l = 1; l <= t; l++) {
    cin >> n >> m;
    cin.get();
    for (i = 1; i <= n; i++) cin.getline(s[i] + 1, 51);
    ok = 1;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
        if (s[i][j] == 'B') {
          if (i + 1 <= n) {
            if (s[i + 1][j] == 'G')
              ok = 0;
            else if (s[i + 1][j] == '.')
              s[i + 1][j] = '#';
          }
          if (i - 1 >= 1) {
            if (s[i - 1][j] == 'G')
              ok = 0;
            else if (s[i - 1][j] == '.')
              s[i - 1][j] = '#';
          }
          if (j + 1 <= m) {
            if (s[i][j + 1] == 'G')
              ok = 0;
            else if (s[i][j + 1] == '.')
              s[i][j + 1] = '#';
          }
          if (j - 1 >= 1) {
            if (s[i][j - 1] == 'G')
              ok = 0;
            else if (s[i][j - 1] == '.')
              s[i][j - 1] = '#';
          }
        }
    if (s[n][m] == '.') fil(n, m);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
        if (s[i][j] == 'G') {
          ok = 0;
          break;
        }
    if (ok == 1)
      cout << "Yes";
    else
      cout << "No";
    cout << '\n';
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) viz[i][j] = 0;
  }
  return 0;
}
