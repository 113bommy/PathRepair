#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  int f = -1, l = -1, len;
  getline(cin, str);
  str.insert(0, "a");
  str.push_back('a');
  len = str.size() - 1;
  for (int i = 1; i < len; i++) {
    if (str[i] != 'a' & str[i - 1] == 'a')
      if (f == -1) f = i;
    if (str[i] != 'a' & str[i + 1] == 'a')
      if (l == -1) l = i;
  }
  if (l + f > 0)
    for (int i = f; i <= l; i++) str[i] = str[i] - 1;
  else
    str[len - 1] = 'z';
  str.erase(0, 1);
  str.erase(len - 1, len - 1);
  cout << str << "\n";
  return 0;
}
