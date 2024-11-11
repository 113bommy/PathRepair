#include <bits/stdc++.h>
using namespace std;
int weight(char ch) {
  if (ch == 'q') {
    return 9;
  } else if (ch == 'r') {
    return 5;
  } else if (ch == 'b') {
    return 3;
  } else if (ch == 'k') {
    return 3;
  } else if (ch == 'p') {
    return 1;
  }
  return 0;
}
int main() {
  string str[8];
  int counter_white = 0, counter_black = 0;
  for (int i = 0; i < 8; i++) {
    cin >> str[i];
    for (int j = 0; j < str[i].size(); j++) {
      if (str[i][j] < 97) {
        counter_white += weight(str[i][j] + 32);
      } else {
        counter_black += weight(str[i][j]);
      }
    }
  }
  if (counter_black > counter_white) {
    cout << "Black";
  } else if (counter_black < counter_white) {
    cout << "White";
  } else {
    cout << "Draw";
  }
}
