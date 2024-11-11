#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] < 97) str[i] = str[i] + 48;
    if (str[i] == 'a' || str[i] == 'o' || str[i] == 'y' || str[i] == 'e' ||
        str[i] == 'u' || str[i] == 'i') {
      str.erase(i, 1);
      --i;
    }
  }
  for (int i = 0; i < str.length(); i++) cout << '.' << str[i];
  return 0;
}
