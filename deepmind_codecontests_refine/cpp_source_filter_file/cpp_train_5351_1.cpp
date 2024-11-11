#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t, q = 0;
  cin >> n >> m;
  char s[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> s[i][j];
  for (int i = 0; i < n; i++) {
    t = 0;
    for (int j = 0; j < m; j++)
      if (s[i][j] != 'S') t++;
    if (t == m)
      for (int j = 0; j < m; j++) s[i][j] = '@';
  }
  for (int j = 0; j < n; j++) {
    t = 0;
    for (int i = 0; i < m; i++)
      if (s[i][j] != 'S') t++;
    if (t == n)
      for (int i = 0; i < m; i++) s[i][j] = '@';
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '@') q++;
  cout << q;
}
