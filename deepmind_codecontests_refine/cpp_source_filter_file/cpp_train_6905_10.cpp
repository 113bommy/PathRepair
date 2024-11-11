#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, sum = "";
  bool flag = false, prev = true;
  int k = 0;
  while (getline(cin, s)) {
    if (s == "" || s == "\n" || s == "#13#10")
      flag = false;
    else
      flag = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ' || s[i] == '#' && flag == true) {
        if (s[i] == '#') {
          if (sum != "" || k > 0) {
            if (sum == "")
              cout << "\n";
            else
              cout << sum << endl;
          }
          cout << s << endl;
          sum = "";
          k = 0;
          break;
        }
        if (i != s.size() - 1) flag = false;
      } else {
        flag = false;
        break;
      }
    }
    if (flag == false) {
      k++;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') sum += s[i];
      }
    }
  }
  if (flag == false) cout << sum << endl;
  return 0;
}
