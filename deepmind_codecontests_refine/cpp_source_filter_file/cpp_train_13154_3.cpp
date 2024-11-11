#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 1, d = 1;
  string s;
  cin >> s;
  for (int i = 1; i < s.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (s[j] == s[i]) {
        d = 0;
        break;
      } else
        d = 1;
    }
    if (d == 1) c++;
  }
  if (c % 2 == 0)
    cout << "CHAT WITH HER";
  else
    cout << "IGNORE HIM";
  return 0;
}
