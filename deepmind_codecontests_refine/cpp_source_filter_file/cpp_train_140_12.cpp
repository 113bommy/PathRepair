#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a;
  cin >> a;
  string out = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < a + 97) {
      out += toupper(s[i]);
    } else
      out += tolower(s[i]);
  }
  cout << out << endl;
}
