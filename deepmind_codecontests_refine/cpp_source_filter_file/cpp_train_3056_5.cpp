#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--)
    if (s[i] != '/')
      break;
    else
      s.erase(i);
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '/' && s[i - 1] == '/')
      continue;
    else
      cout << s[i];
}
