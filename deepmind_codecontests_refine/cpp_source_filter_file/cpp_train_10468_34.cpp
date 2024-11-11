#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s == "a1" || s == "a8" || s == "h1" || s == "h8")
    cout << 3 << endl;
  else if (s[0] == 'a' || s[0] == 'h' || s[1] == 1 || s[1] == 8)
    cout << 5 << endl;
  else
    cout << 8 << endl;
  return 0;
}
