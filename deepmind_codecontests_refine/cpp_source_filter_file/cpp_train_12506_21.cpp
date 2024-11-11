#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a;
  char b[300];
  int n, i, r, x, m;
  cin >> m;
  for (int j = 0; j < m; j++) {
    cin >> n >> s;
    getchar();
    x = 0;
    a = s[0];
    for (i = 1; s[i] != 0; i++) {
      b[i - 1] = s[i];
    }
    b[i - 1] = 0;
    if (n <= 2) {
      if (s[0] == s[1] || s[0] > s[i]) {
        x = 1;
      }
    }
    if (x == 0) {
      cout << "YES" << endl << "2" << endl << a << " " << b << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
