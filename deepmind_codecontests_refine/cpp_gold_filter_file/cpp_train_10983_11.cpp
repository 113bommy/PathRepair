#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int i, l, cnt = 0, flag = 0;
  cin >> str;
  l = str.size();
  for (i = 0; i < l; i++) {
    if (str[i] >= 65 && str[i] <= 90) {
      cnt++;
    } else if (str[i] >= 97 && str[i] <= 122) {
      flag++;
    }
  }
  for (i = 0; i < l; i++) {
    if (cnt > flag) {
      if (str[i] >= 97) {
        str[i] -= 32;
      }
    } else {
      if (str[i] <= 90) {
        str[i] += 32;
      }
    }
  }
  cout << str << endl;
  return 0;
}
