#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int num = 0, sum = 0, tum = 1;
  cin >> str;
  char a[15] = {'A', 'E', 'F', 'H', 'I', 'K', 'L', 'M',
                'N', 'T', 'V', 'W', 'X', 'Y', 'Z'};
  char b[11] = {'B', 'C', 'D', 'G', 'J', 'O', 'P', 'Q', 'R', 'S', 'U'};
  for (int i = 0; i < 15; i++) {
    if (str.at(0) == a[i]) {
      num++;
      break;
    }
  }
  if (num == 0) sum++;
  int n = str.size();
  if (num == 1) {
    for (int i = 1; i < n; i++) {
      if (str.at(i) == 'B' || str.at(i) == 'C' || str.at(i) == 'D' ||
          str.at(i) == 'G' || str.at(i) == 'J' || str.at(i) == 'O' ||
          str.at(i) == 'P' || str.at(i) == 'Q' || str.at(i) == 'R' ||
          str.at(i) == 'S' || str.at(i) == 'U') {
        tum == 0;
        break;
      }
    }
  }
  if (sum == 1) {
    for (int i = 1; i < n; i++) {
      if (str.at(i) == 'A' || str.at(i) == 'E' || str.at(i) == 'F' ||
          str.at(i) == 'H' || str.at(i) == 'I' || str.at(i) == 'K' ||
          str.at(i) == 'L' || str.at(i) == 'M' || str.at(i) == 'N' ||
          str.at(i) == 'T' || str.at(i) == 'V' || str.at(i) == 'W' ||
          str.at(i) == 'X' || str.at(i) == 'Y' || str.at(i) == 'Z') {
        tum == 0;
        break;
      }
    }
  }
  if (tum) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
