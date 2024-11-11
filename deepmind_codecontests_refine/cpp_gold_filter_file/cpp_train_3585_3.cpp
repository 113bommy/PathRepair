#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, x = 0, c = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') {
      x++;
    } else {
      k++;
    }
  }
  if (k == x) {
    cout << 0 << endl << s << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (k < n / 2) {
      if (s[i] == 'X') {
        s[i] = 'x';
        k++;
        c++;
      }
    }
    if (x < n / 2) {
      if (s[i] == 'x') {
        s[i] = 'X';
        x++;
        c++;
      }
    }
  }
  cout << c << endl << s << endl;
}
