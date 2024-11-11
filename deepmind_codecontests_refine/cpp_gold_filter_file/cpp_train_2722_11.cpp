#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, cont = 0;
  char m[60][60];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == '.') {
        ++cont;
        if ((j + 1 < n) and (j - 1 >= 0) and (i + 2 < n)) {
          if (m[i + 1][j - 1] == '.' and m[i + 1][j + 1] == '.' and
              m[i + 1][j] == '.' and m[i + 2][j] == '.') {
            m[i + 1][j + 1] = '#';
            m[i + 1][j - 1] = '#';
            m[i][j] = '#';
            m[i + 2][j] = '#';
            m[i + 1][j] = '#';
            --cont;
          }
        }
      }
    }
  }
  if (cont == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
