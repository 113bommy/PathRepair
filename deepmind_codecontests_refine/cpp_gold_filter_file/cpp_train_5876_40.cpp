#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[101], t[101];
  cin >> s >> t;
  int r, y, d = 0;
  r = strlen(s);
  y = strlen(t);
  if (r == y) {
    for (int i = 0; i < r; i++) {
      if (s[i] == t[y - i - 1]) {
        d++;
      }
    }
    if (d == r) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
