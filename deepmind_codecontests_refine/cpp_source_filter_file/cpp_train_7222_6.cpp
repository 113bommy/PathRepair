#include <bits/stdc++.h>
using namespace std;
char gra[8][8] = {0};
int main() {
  int i, j, t = '#' + '.';
  for (i = 0; i < 8; i = i + 2)
    for (j = 0; j < 8; j = j + 2) cin >> gra[i][j];
  for (i = 1; i < 6; i = i + 2)
    for (j = 1; j < 6; j = j + 2) {
      t = gra[i - 1][j - 1] + gra[i - 1][j + 1] + gra[i + 1][j - 1] +
          gra[i + 1][j + 1];
      if (t != 162) {
        cout << "Yes\n";
        return 0;
      }
    }
  cout << "NO\n";
  return 0;
}
