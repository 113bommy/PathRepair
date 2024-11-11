#include <bits/stdc++.h>
using namespace std;
char arr[9][9];
int main() {
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> arr[i][j];
    }
  }
  map<char, int> m;
  m['B'] = 99999;
  m['W'] = 99999;
  int currmina = 0, currminb = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (arr[i][j] == 'B') {
        for (int k = i + 1; k <= 8; k++) {
          if (arr[k][j] == 'B' || arr[k][j] == 'A') {
            break;
          }
          if (k == 8) {
            m['B'] = min(m['B'], 8 - i);
          }
        }
      } else if (arr[i][j] == 'W') {
        for (int k = i - 1; k >= 1; k--) {
          if (arr[k][j] == 'B' || arr[k][j] == 'A') {
            break;
          }
          if (k == 1) {
            m['W'] = min(m['W'], 8 - i);
          }
        }
      }
    }
  }
  if (m['W'] <= m['B']) {
    cout << "A";
  } else {
    cout << "B";
  }
  return 0;
}
