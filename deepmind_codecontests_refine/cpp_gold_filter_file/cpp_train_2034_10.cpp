#include <bits/stdc++.h>
using namespace std;
int cmp(string a, string b) {
  int na = a.length();
  int nb = b.length();
  if (a[0] == '-' && b[0] != '-')
    return 0;
  else if (a[0] != '-' && b[0] == '-')
    return 1;
  else if (a[0] == '-' && b[0] == '-') {
    if (na > nb)
      return 0;
    else if (na < nb)
      return 1;
    else if (a > b)
      return 0;
    else if (a < b)
      return 1;
  } else {
    if (na > nb)
      return 1;
    else if (na < nb)
      return 0;
    else if (a > b)
      return 1;
    else if (a < b)
      return 0;
  }
}
int main() {
  string s;
  cin >> s;
  if (((s == "-128") || cmp(s, "-128") == 1) &&
      (s == "127" || cmp(s, "127") == 0)) {
    cout << "byte";
    return 0;
  } else if (s == "-32768" || s == "32767" ||
             (cmp(s, "-32768") == 1 && cmp(s, "32767") == 0)) {
    cout << "short";
    return 0;
  } else if (s == "-2147483648" || s == "2147483647" ||
             (cmp(s, "-2147483648") == 1 && cmp(s, "2147483647") == 0)) {
    cout << "int";
    return 0;
  } else if (s == "-9223372036854775808" || s == "9223372036854775807" ||
             (cmp(s, "-9223372036854775808") == 1 &&
              cmp(s, "9223372036854775807") == 0)) {
    cout << "long";
    return 0;
  } else
    cout << "BigInteger";
  return 0;
}
