#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> b(n, vector<char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int s = 0;
      if (i > 0 && j > 0 && b[i - 1][j - 1] == '*') s++;
      if (i > 0 && b[i - 1][j] == '*') s++;
      if (i > 0 && j < n - 1 && b[i - 1][j + 1] == '*') s++;
      if (j < n - 1 && b[i][j + 1] == '*') s++;
      if (i < n - 1 && j < n - 1 && b[i + 1][j + 1] == '*') s++;
      if (i < n - 1 && b[i + 1][j] == '*') s++;
      if (i < n - 1 && j > 0 && b[i + 1][j - 1] == '*') s++;
      if (j > 0 && b[i][j - 1] == '*') s++;
      if (!((b[i][j] == '*') || (b[i][j] == '.' && s == 0) ||
            (b[i][j] != '.' && b[i][j] != '*' && b[i][j] - '0' == s)))
        flag = 1;
    }
  }
  if (flag)
    cout << "NO\n";
  else
    cout << "YES\n";
}
