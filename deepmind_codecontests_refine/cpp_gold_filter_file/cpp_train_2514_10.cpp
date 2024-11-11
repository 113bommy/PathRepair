#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int niz[9];
  for (int i = 0; i < 9; i++) cin >> niz[i];
  for (int i = 0; i < n; i++) {
    if (s[i] - 48 < niz[s[i] - 49]) {
      while (s[i] - 48 <= niz[s[i] - 49]) {
        s[i] = niz[s[i] - 49] + 48;
        i++;
      }
      break;
    }
  }
  cout << s;
}
