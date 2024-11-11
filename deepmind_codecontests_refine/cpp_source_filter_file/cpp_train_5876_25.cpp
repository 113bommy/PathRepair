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
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
