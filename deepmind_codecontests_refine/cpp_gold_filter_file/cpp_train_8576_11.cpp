#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, str2;
  cin >> str;
  int x = 0;
  int x2 = 0;
  stringstream geek(str);
  geek >> x;
  if (x >= 0) {
    cout << x << endl;
    return 0;
  } else {
    int y = x / 10;
    for (int i = 0; i < str.length(); i++) {
      if (i == str.length() - 2) {
        continue;
      }
      str2 += str[i];
    }
    stringstream geek(str2);
    geek >> x2;
    if (y > x2) {
      cout << y << endl;
    } else
      cout << x2 << endl;
  }
  return 0;
}
