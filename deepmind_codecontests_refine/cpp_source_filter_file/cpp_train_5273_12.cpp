#include <bits/stdc++.h>
using namespace std;
string str, s;
void slove(int l) {
  for (int i = 0; i < l; i++) {
    if (s[i] == 'O' || s[i] == 'o')
      s[i] = '0';
    else if (s[i] == 'i' || s[i] == 'I' || str[i] == 'l' || s[i] == 'L')
      s[i] = '1';
    if (isalpha(s[i])) s[i] = tolower(s[i]);
  }
}
int main() {
  int n, l, m, flag = 1;
  cin >> str;
  l = str.length();
  for (int i = 0; i < l; i++) {
    if (str[i] == 'O' || str[i] == 'o')
      str[i] = '0';
    else if (str[i] == 'i' || str[i] == 'I' || str[i] == 'l' || str[i] == 'L')
      str[i] = '1';
    if (isalpha(str[i])) str[i] = tolower(str[i]);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    m = s.length();
    if (m == l) {
      slove(m);
      if (str.compare(s) == 0) {
        flag = 0;
        break;
      }
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
