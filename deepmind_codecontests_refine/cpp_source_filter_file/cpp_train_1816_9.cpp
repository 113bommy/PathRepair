#include <bits/stdc++.h>
using namespace std;
bool Pal(char x) {
  if (x == 'A' || x == 'H' || x == 'I' || x == 'M' || x == 'O' || x == 'T' ||
      x == 'U' || x == 'V' || x == 'W' || x == 'X' || x == 'Y')
    return true;
  else
    return false;
}
int main() {
  string s;
  int n, i;
  cin >> s;
  n = s.size();
  for (i = 0; i <= (n + 1) / 2; i++) {
    if (s[i] == s[n - i - 1]) {
      if (!Pal(s[i])) {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
