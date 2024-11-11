#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[3];
  int win = -1;
  int d[3], res = 0;
  for (int i = 0; i < 3; i++) {
    cin >> str[i];
    if (str[i] == "rock")
      d[i] = 1;
    else if (str[i] == "paper")
      d[i] = 2;
    else
      d[i] = 5;
    res += d[i];
  }
  if (str[0] == str[1] && str[1] == str[2])
    cout << "?" << endl;
  else if (res == 8)
    cout << "?" << endl;
  else {
    if (res == 11) {
      for (int i = 0; i < 3; i++)
        if (str[i] == "rock") win = i;
    } else {
      if (res == 9) {
        for (int i = 0; i < 3; i++)
          if (str[i] == "scissors") win = i;
      } else {
        if (res == 3) {
          for (int i = 0; i < 3; i++)
            if (str[i] == "paper") win = i;
        }
      }
    }
    switch (win) {
      case 0:
        cout << "F" << endl;
        break;
      case 1:
        cout << "M" << endl;
        break;
      case 2:
        cout << "S" << endl;
        break;
      default:
        cout << "?" << endl;
    }
  }
  return 0;
}
