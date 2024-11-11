#include <bits/stdc++.h>
using namespace std;
string znam[] = {"",     "one", "two",   "three", "four",
                 "five", "six", "seven", "eight", "nine"};
string deset[] = {"",      "",      "twenty",  "thirty", "forty",
                  "fifty", "sixty", "seventy", "eighty", "ninety"};
string ispodd[] = {"",    "",    "",      "thir", "four",
                   "fif", "six", "seven", "eigh", "nine"};
int main() {
  string s;
  cin >> s;
  if (s.size() == 1) {
    if (s == "0")
      cout << "zero" << endl;
    else
      cout << znam[s[0] - '0'] << endl;
  } else {
    if (s[0] == '1') {
      if (s == "10")
        cout << "ten" << endl;
      else if (s == "11")
        cout << "eleven" << endl;
      else if (s == "12")
        cout << "twelve" << endl;
      else
        cout << ispodd[s[1] - '0'] << "teen" << endl;
    } else {
      cout << deset[s[0] - '0'];
      if (s[1] != '0') cout << "-";
      cout << znam[s[1] - '0'] << endl;
    }
  }
  return 0;
}
