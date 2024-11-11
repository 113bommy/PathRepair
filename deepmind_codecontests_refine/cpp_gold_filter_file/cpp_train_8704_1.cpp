#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int i = 0, j = s.length() - 1;
  while (j >= 0 && s[j] == '0') --j;
  while (i < j)
    if (s[i] == s[j]) {
      ++i;
      --j;
    } else {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
