#include <bits/stdc++.h>
using namespace std;
int findIndexOf(string line, string sub) {
  int lineLen = line.length();
  int subLen = sub.length();
  if (subLen > lineLen) return -1;
  for (int i = 0; i <= lineLen - subLen; i++) {
    if (line.substr(i, subLen) == sub) return i;
  }
  return -1;
}
int findLastIndexOf(string line, string sub) {
  int lineLen = line.length();
  int subLen = sub.length();
  if (subLen > lineLen) return -1;
  for (int i = lineLen - subLen; i >= 0; i--) {
    if (line.substr(i, subLen) == sub) return i;
  }
  return -1;
}
bool check(string flags, string first, string second) {
  int f_f_index = findIndexOf(flags, first);
  int s_l_index = findLastIndexOf(flags, second);
  return f_f_index != -1 && s_l_index != -1 &&
         f_f_index + first.length() - 1 < s_l_index;
}
void revStr(string& s) {
  int n = s.length();
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
int main() {
  string flags, first, second;
  cin >> flags >> first >> second;
  bool f = check(flags, first, second);
  revStr(flags);
  bool b = check(flags, first, second);
  if (f && b)
    cout << "both";
  else if (f)
    cout << "forward";
  else if (b)
    cout << "backward";
  else
    cout << "fantasy";
  return 0;
}
