#include <bits/stdc++.h>
using namespace std;
int main() {
  int lCount = 0, rCount = 0;
  vector<char> s;
  string str, u;
  getline(cin, str);
  for (int i = int(0); i < int(str.length()); i++)
    if (str[i] != '|')
      lCount++;
    else
      break;
  rCount = str.length() - lCount - 1;
  cin >> u;
  for (int i = int(0); i < int(lCount); i++) s.push_back(str[i]);
  for (int i = int(0); i < int(u.length()); i++) s.push_back(u[i]);
  for (int i = int(lCount + 1); i < int(str.length()); i++) s.push_back(str[i]);
  if (s.size() % 2 == 0 && max(lCount, rCount) < s.size() / 2)
    for (int i = int(0); i < int(s.size()); i++) {
      if (i == s.size() / 2) cout << '|';
      cout << s.at(i);
    }
  else
    cout << "Impossible";
}
