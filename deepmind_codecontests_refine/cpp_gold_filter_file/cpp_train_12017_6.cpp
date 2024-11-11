#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  int i = 0, n = s.length();
  while (i < n && s[i] != '+') {
    a++;
    i++;
  }
  i++;
  while (i < n && s[i] != '=') {
    b++;
    i++;
  }
  i++;
  c = n - i;
  if (abs((a + b) - c) > 2 || (a + b + c) & 1) {
    cout << "Impossible\n";
    return 0;
  }
  if (abs((a + b) - c) == 0) {
    cout << s << "\n";
    return 0;
  }
  int f = 0;
  if (a + b > c) f = 1;
  if (!f) {
    a++;
    c--;
  } else {
    (a > b ? (a--, c++) : (b--, c++));
  }
  while (a-- > 0) {
    cout << '|';
  }
  cout << '+';
  while (b-- > 0) {
    cout << '|';
  }
  cout << '=';
  while (c-- > 0) cout << '|';
  cout << endl;
  return 0;
}
