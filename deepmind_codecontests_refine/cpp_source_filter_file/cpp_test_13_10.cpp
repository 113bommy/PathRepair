#include <bits/stdc++.h>
using namespace std;
bool cat(string s) {
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else
      c++;
  }
  if (abs(b - c) == a)
    return true;
  else
    return false;
}
int main() {
  string s;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> s;
    if (cat(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
