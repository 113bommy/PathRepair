#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  string temp = "";
  int i = 0;
  while (i < str.size()) {
    if (str.substr(i, 3) == "WUB") {
      i = i + 3;
      if (temp.size() != 0 && *(temp.end() - 1) != ' ') temp += ' ';
    } else
      temp += str[i++];
  }
  cout << temp << endl;
}
