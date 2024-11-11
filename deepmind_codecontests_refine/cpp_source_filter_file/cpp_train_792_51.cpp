#include <bits/stdc++.h>
using namespace std;
int h[100][26], v[100][26];
int main() {
  int n, m;
  char a[100][100];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      h[i][int(a[i][j] - 'a')]++;
      v[j][int(a[i][j] - 'a')]++;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 26; j++)
      if (h[i][j] > 1)
        for (int g = 0; g < m; g++)
          if (a[i][g] == char('a' + j)) a[i][g] = '.';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 26; j++)
      if (v[i][j] > 1)
        for (int g = 0; g < m; g++)
          if (a[g][i] == char('a' + j)) a[g][i] = '.';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] != '.') cout << a[i][j];
  cout << endl;
  return 0;
}
