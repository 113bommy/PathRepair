#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t, v;
  getline(cin, s);
  getline(cin, t);
  getline(cin, v);
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      x++;
  }
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')
      y++;
  }
  for (int i = 0; i < v.length(); i++) {
    if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
      z++;
  }
  if (x >= 5 && y >= 7 && z >= 5)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
