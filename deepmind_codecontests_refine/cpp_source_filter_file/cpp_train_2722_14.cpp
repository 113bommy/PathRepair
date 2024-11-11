#include <bits/stdc++.h>
using namespace std;
int p[55][55];
int main() {
  char ch;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> ch;
      if (ch == '#')
        p[i][j] = 1;
      else
        p[i][j] = 0;
    }
  }
  for (int i = 2; i <= n - 1; ++i) {
    for (int j = 2; j <= n - 1; ++j) {
      if (p[i][j] == 0) {
        if (p[i - 1][j] == 1 || p[i][j - 1] == 1 || p[i][j + 1] == 1 ||
            p[i + 1][j] == 1)
          break;
        else
          p[i - 1][j] = 1, p[i][j - 1] = 1, p[i][j + 1] = 1, p[i + 1][j] = 1,
                p[i][j] = 1;
      }
    }
  }
  int fag = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[i][j] == 0) {
        fag = 1;
        break;
      }
    }
  }
  if (fag == 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
