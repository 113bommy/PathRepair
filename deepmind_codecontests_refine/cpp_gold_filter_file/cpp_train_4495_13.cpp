#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] - 'A' + 'a';
    }
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == 'y') {
      str[i] = ' ';
    } else {
      cout << '.' << str[i];
    }
  }
  return 0;
}
