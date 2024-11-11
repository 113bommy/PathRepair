#include <bits/stdc++.h>
using namespace std;
string revCaps(string str) {
  for (int i = 0; i < str.size(); i++)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] + 'A' - 'a';
    else if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 'a' - 'A';
  return str;
}
int main() {
  string str;
  cin >> str;
  bool caps = false;
  bool allCaps = true;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') allCaps = false;
  }
  bool otherCaps = true;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') otherCaps = false;
  }
  bool firstNoCap = (str[0] >= 'a' && str[0] <= 'z');
  if (allCaps || (otherCaps && firstNoCap)) {
    cout << revCaps(str) << endl;
  } else
    cout << str << endl;
  return 0;
}
