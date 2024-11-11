#include <bits/stdc++.h>
using namespace std;
int main() {
  char tmp;
  int sum1 = 0;
  int sum2 = 0;
  vector<vector<char>> v(8);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> tmp;
      v[i].push_back(tmp);
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      switch (v[i][j]) {
        case 'Q':
          sum1 += 9;
          break;
        case 'R':
          sum1 += 5;
          break;
        case 'B':
          sum1 += 3;
          break;
        case 'N':
          sum1 += 3;
          break;
        case 'P':
          sum1 += 1;
          break;
        default:
          break;
      }
      switch (v[i][j]) {
        case 'q':
          sum2 += 9;
          break;
        case 'r':
          sum2 += 5;
          break;
        case 'b':
          sum2 += 3;
          break;
        case 'n':
          sum2 += 3;
          break;
        case 'p':
          sum2 += 1;
          break;
        default:
          break;
      }
    }
  }
  if (sum1 == sum2) {
    cout << "Draw" << endl;
    return 0;
  }
  sum1 > sum2 ? cout << "White" << endl : cout << "Black" << endl;
  return 0;
}
