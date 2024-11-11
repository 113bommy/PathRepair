#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int k = 0;
  for (int i = 0; i < str.length(); i++)
    if (str[i] == '#') k++;
  vector<int> s(k, 1);
  int s1 = 0;
  int s2 = 0;
  for (int i = 0; i < str.length(); i++)
    if (str[i] == '(')
      s1++;
    else if (str[i] == ')')
      s2++;
  s[k - 1] = s1 - k + 1 - s2;
  s1 = 0;
  s2 = 0;
  bool flag = true;
  k = 0;
  for (int i = 0; i < str.length(); i++) {
    if (s2 > s1) flag = false;
    if (str[i] == '(')
      s1++;
    else if (str[i] == '#')
      s2 += s[k];
    else
      s2++;
  }
  if (flag && s[s.size() - 1] > 0)
    for (int i = 0; i < s.size(); i++) cout << s[i] << "\n";
  else
    cout << "-1";
  return 0;
}
