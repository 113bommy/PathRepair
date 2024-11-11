#include <bits/stdc++.h>
using namespace std;
string s;
int x;
int main() {
  cin >> s;
  if (s.size() == 1 && s[0] == '7')
    return cout << "Yes", 0;
  else if (s.size() == 1 && s[0] == '3')
    return cout << "Yes", 0;
  else if (s.size() == 1)
    return cout << "No", 0;
  bool bo = true;
  for (int i = 0, j = s.size() - 1; i < s.size() / 2 + 1; i++, j--) {
    if (s[i] == '5' && s[j] == '9' && bo == true)
      bo = true;
    else if (s[i] == '4' && s[j] == '6' && bo == true)
      bo = true;
    else if (s[i] == '0' && s[j] == '8' && bo == true)
      bo = true;
    else if (s[i] == '3' && s[j] == '3' && bo == true)
      bo = true;
    else if (s[i] == '7' && s[j] == '7' && bo == true)
      bo = true;
    else if (s[i] == '9' && s[j] == '5' && bo == true)
      bo = true;
    else if (s[i] == '6' && s[j] == '4' && bo == true)
      bo = true;
    else if (s[i] == '8' && s[j] == '0' && bo == true)
      bo = true;
    else
      bo = false;
  }
  if (s[0] == '0' && s[1] == '0') bo = false;
  if (bo == true)
    cout << "Yes";
  else
    cout << "No";
}
