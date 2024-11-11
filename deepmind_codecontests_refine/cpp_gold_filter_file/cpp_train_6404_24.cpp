#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1, str2;
  cin >> str1 >> str2;
  string str3 = "";
  for (int i = 0; str1[i] != '\0'; i++) {
    if (str1[i] == str2[i]) {
      str3 += "0";
    } else
      str3 += "1";
  }
  cout << str3;
}
