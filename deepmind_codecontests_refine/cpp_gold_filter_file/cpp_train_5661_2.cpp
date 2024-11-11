#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int i, j, a, b, c, d;
  cin >> s;
  a = s.size();
  ;
  for (i = 0; i < a; i++) {
    if (s[i] == '0') {
      for (j = i; j < a - 1; j++) s[j] = s[j + 1];
      break;
    }
  }
  for (i = 0; i < a - 1; i++) cout << s[i];
  return 0;
}
