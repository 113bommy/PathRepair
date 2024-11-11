#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int len = str.length();
  reverse(str.begin(), str.end());
  string temp = "";
  int flag = 0;
  for (int i = 0; i < len - 1; i++) {
    if ((str[i] - 'a') >= (str[flag] - 'a')) {
      temp += str[i];
      flag = i;
    }
  }
  reverse(temp.begin(), temp.end());
  cout << temp << endl;
  return 0;
}
