#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, i = 0, maks = 0;
  string s;
  cin >> s;
  while (i < s.size()) {
    if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' &&
        s[i] != 'U' && s[i] != 'Y')
      c++;
    else {
      maks = max(maks, c + 1);
      c = 0;
    }
    i++;
  }
  cout << max(maks, c + 1);
}
