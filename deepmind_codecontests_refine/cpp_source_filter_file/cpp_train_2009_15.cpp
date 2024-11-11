#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a1, a2, a3, a4, flag = 1;
  string str;
  cin >> a1 >> a2 >> a3 >> a4;
  if (a3 <= a1 && a3 <= a2 && a4 <= a1 && a4 <= a2 && abs(a3 - a4) < 2) {
    if (a3 == a4) {
      if (a1 > a3) {
        for (int i = 0; i < a3; i++) str += "47";
        str += "4";
        a1 -= (a3 + 1);
        a2 -= a3;
      } else if (a2 > a3) {
        for (int i = 0; i < a3; i++) str += "74";
        str += "7";
        a1 -= a3;
        a2 -= (a3 + 1);
      } else
        flag = 0;
    } else if (a3 > a4) {
      for (int i = 0; i < a3; i++) str += "47";
      a1 -= a3;
      a2 -= a3;
    } else if (a4 > a3) {
      for (int i = 0; i < a4; i++) str += "74";
      a1 -= a4;
      a2 -= a4;
    }
  } else
    flag = 0;
  if (flag == 0)
    cout << "-1";
  else {
    if (str[0] == '7') {
      cout << str[0];
      if (a1 != 0)
        for (int i = 0; i < a1; i++) cout << "4";
      for (int i = 1; i < str.size() - 1; i++) cout << str[i];
      if (a3 != 0)
        for (int i = 0; i < a3; i++) cout << "7";
      cout << str[str.size() - 1];
    } else if (str[0] == '4') {
      cout << str[0];
      if (a1 != 0)
        for (int i = 0; i < a1; i++) cout << "4";
      for (int i = 1; i < str.size() - 1; i++) cout << str[i];
      if (a3 != 0)
        for (int i = 0; i < a3; i++) cout << "7";
      cout << str[str.size() - 1];
    }
  }
  cout << "\n";
  return 0;
}
