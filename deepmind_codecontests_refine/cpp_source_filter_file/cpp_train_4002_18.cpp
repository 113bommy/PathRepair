#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0, d = 0, e = 0, f = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] > 47 && s[i] < 58)
      c++;
    else if (s[i] > 64 && s[i] < 91)
      d++;
    else if (s[i] > 96 && s[i] < 173)
      e++;
    else
      f++;
  }
  if (c != 0 && d != 0 && e != 0 && (c + d + e + f) > 5)
    cout << "Correct";
  else
    cout << "Too weak";
}
