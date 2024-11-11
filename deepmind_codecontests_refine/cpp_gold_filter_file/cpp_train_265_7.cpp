#include <bits/stdc++.h>
using namespace std;
long long n, a, e, i1, o, u, y;
string s;
int main() {
  cin >> n;
  cin >> s;
  s[n] = '0';
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
        s[i] != 'u' && s[i] != 'y')
      cout << s[i];
    if (s[i] == 'a') a++;
    if (s[i + 1] != 'a' && s[i] == 'a') {
      cout << 'a';
      a = 0;
    }
    if (s[i] == 'e') e++;
    if (s[i + 1] != 'e' && s[i] == 'e') {
      if (e == 2)
        cout << 'e' << 'e';
      else
        cout << 'e';
      e = 0;
    }
    if (s[i] == 'i') i1++;
    if (s[i + 1] != 'i' && s[i] == 'i') {
      cout << 'i';
      i1 = 0;
    }
    if (s[i] == 'o') o++;
    if (s[i + 1] != 'o' && s[i] == 'o') {
      if (o == 2)
        cout << 'o' << 'o';
      else
        cout << 'o';
      o = 0;
    }
    if (s[i] == 'u') u++;
    if (s[i + 1] != 'u' && s[i] == 'u') {
      cout << 'u';
      u = 0;
    }
    if (s[i] == 'y') y++;
    if (s[i + 1] != 'y' && s[i] == 'y') {
      cout << 'y';
      y = 0;
    }
  }
}
