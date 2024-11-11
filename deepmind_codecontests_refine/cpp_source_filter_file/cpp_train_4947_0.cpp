#include <bits/stdc++.h>
using namespace std;
string delete_zeros(string s) {
  while (s[0] == '0') s = s.substr(1);
  return s;
}
int main() {
  string n1, n2;
  getline(cin, n1);
  getline(cin, n2);
  int l1 = 0, l2 = 0;
  for (int i = 0; i < n1.length(); ++i) {
    if (n1[i] == '0')
      l1++;
    else
      break;
  }
  for (int i = 0; i < n2.length(); ++i) {
    if (n2[i] == '0')
      l2++;
    else
      break;
  }
  if (n1.length() - l1 > n2.length() - l2)
    cout << '>';
  else if (n1.length() - l1 < n2.length() - l2)
    cout << '>';
  else {
    for (int i = l1, j = l2; i < n1.length(); ++i, ++j) {
      if (n1[i] > n2[j]) {
        cout << '>';
        return 0;
      } else if (n1[i] < n2[j]) {
        cout << '<';
        return 0;
      }
    }
    cout << '=';
  }
}
