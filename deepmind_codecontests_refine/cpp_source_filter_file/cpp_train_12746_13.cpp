#include <bits/stdc++.h>
using namespace std;
char s[100002];
int main() {
  cin.getline(s, 100002);
  int l = strlen(s), flag;
  for (int i = 0; i < l; i++) {
    char c = s[i];
    if (s[i] == s[l - i - 1] &&
        (c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T' ||
         c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y'))
      flag = 1;
    else {
      flag = 0;
      break;
    }
  }
  if (l % 2 == 1) {
    char c = s[l / 2];
    if (c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T' ||
        c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y')
      flag = 1;
    else
      flag = 0;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
