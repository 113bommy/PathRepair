#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  string s, temp;
  while (cin >> temp) {
    if (isdigit(temp[0]) && !s.empty() && isdigit(*s.rbegin())) s += " ";
    s += temp;
  }
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == ',' && i + 1 != (int)s.size() && s[i + 1] != '.')
      s.insert(i + 1, " "), ++i;
    if (s[i] == '.')
      if (i != 0)
        s.insert(i, " "), i += 3;
      else
        i += 3;
  }
  cout << s << endl;
}
