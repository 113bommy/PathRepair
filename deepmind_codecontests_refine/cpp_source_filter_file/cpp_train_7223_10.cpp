#include <bits/stdc++.h>
using namespace std;
int n, c[15], c1[15];
string s;
int main() {
  cin >> n;
  for (int i = 1; i <= n + 1; ++i) {
    c[i] = -2, c1[i] = -2;
    getline(cin, s);
    if (s[0] == 'm' && s[1] == 'i' && s[2] == 'a' && s[3] == 'o' && s[4] == '.')
      c[i] = 1;
    else
      c[i] = 0;
    reverse(s.begin(), s.end());
    if (s[0] == '.' && s[1] == 'a' && s[2] == 'l' && s[3] == 'a' && s[4] == 'l')
      c1[i] = 1;
    else
      c1[i] = 0;
    reverse(s.begin(), s.end());
  }
  for (int i = 1; i <= n + 1; ++i) {
    if (c[i] == 1 && c1[i] == 1)
      cout << "OMG>.< I don't know!\n";
    else if (c[i] == 0 && c1[i] == 1)
      cout << "Freda's\n";
    else if (c[i] == 1 && c1[i] == 0)
      cout << "Rainbow's\n";
    else
      cout << "OMG>.< I don't know!\n";
  }
  return 0;
}
