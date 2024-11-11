#include <bits/stdc++.h>
using namespace std;
int main() {
  string str = "qwertyuiopasdfghjkl;zxcvbnm,./", str2;
  char ch;
  cin >> ch;
  cin >> str2;
  if (ch == 'R') {
    for (int i = 0; i < str2.size(); i++) {
      for (int j = 0; j < 33; j++) {
        if (str[j] == str2[i]) cout << str[j - 1];
      }
    }
  } else {
    for (int i = 0; i < str2.size(); i++) {
      for (int j = 0; j < 33; j++) {
        if (str[j] == str2[i]) cout << str[j + 1];
      }
    }
  }
  cout << endl;
}
