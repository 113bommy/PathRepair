#include <bits/stdc++.h>
using namespace std;
int main() {
  string code;
  cin >> code;
  string num = "";
  for (int i = 0; i < code.length() - 1; i++) {
    if (code[i] == '.') {
      num += "0";
    } else if (code.substr(i, 2) == "-.") {
      num += "1";
      i++;
    } else if (code.substr(i, 2) == "--") {
      num += "2";
      i++;
    }
  }
  cout << num << endl;
}
