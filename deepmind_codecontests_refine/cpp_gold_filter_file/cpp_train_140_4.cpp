#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int x;
  cin >> s >> x;
  for (int i = 0; i < s.size(); ++i) {
    char c = tolower(s[i]);
    if (c < x + 97)
      cout << (char)toupper(c);
    else
      cout << (char)tolower(c);
  }
  cout << endl;
  return 0;
}
