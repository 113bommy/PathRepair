#include <bits/stdc++.h>
using namespace std;
int main() {
  char matrix[51][51];
  int n, m;
  cin >> n >> m;
  map<char, int> mymp;
  mymp['f'] = 1;
  mymp['a'] = 2;
  mymp['c'] = 4;
  mymp['e'] = 8;
  mymp['x'] = -16;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  int cont = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (mymp[matrix[i - 1][j - 1]] + mymp[matrix[i][j - 1]] +
              mymp[matrix[i - 1][j]] + mymp[matrix[i][j]] ==
          15) {
        cont++;
      }
    }
  }
  cout << cont << '\n';
  return 0;
}
