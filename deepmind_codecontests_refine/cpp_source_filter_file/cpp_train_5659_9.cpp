#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "", s1 = "";
  cin >> s;
  int i, n = s.size();
  for (i = 0; i < n - 2; i++) {
    if (s.substr(i, 3) == "WUB") {
      if (s1 != "") s1 += " ";
      i += 2;
    } else
      s1 += s[i];
  }
  cout << s1;
}
