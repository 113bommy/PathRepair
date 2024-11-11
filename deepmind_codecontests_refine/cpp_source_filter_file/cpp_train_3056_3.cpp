#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  char c[100];
  bool flag = false;
  cin >> s;
  int j = 0, l = s.length();
  for (int i = 0; i < s.length(); ++i) {
    if (flag == false && s[i] == '/') {
      flag = true;
      c[j] = s[i];
      ++j;
    } else if (flag == true && s[i] == '/') {
      l--;
    } else {
      flag = false;
      c[j] = s[i];
      ++j;
    }
  }
  if (c[l - 1] == '/') --l;
  for (int i = 0; i < l; ++i) {
    cout << c[i];
  }
  cout << endl;
  return 0;
}
