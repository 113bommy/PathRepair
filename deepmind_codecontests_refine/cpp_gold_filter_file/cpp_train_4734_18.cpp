#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int k = s.length();
  int flag = 0;
  for (int d = 0; d < k - 1; d++) {
    if (s[d] == ' ') {
      continue;
    }
    if (s[d] == 'a' || s[d] == 'e' || s[d] == 'i' || s[d] == 'o' ||
        s[d] == 'u' || s[d] == 'y' || s[d] == 'A' || s[d] == 'E' ||
        s[d] == 'I' || s[d] == 'O' || s[d] == 'U' || s[d] == 'Y') {
      flag = 1;
    } else {
      flag = 0;
    }
  }
  if (flag == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
