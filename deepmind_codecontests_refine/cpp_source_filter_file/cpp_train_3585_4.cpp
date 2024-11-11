#include <bits/stdc++.h>
using namespace std;
int n, m, i, x, y, nr, v[256];
char s[256];
int main() {
  cin >> n;
  cin.get();
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'X') {
      v[i] = 1;
      nr++;
    }
  }
  m = n / 2;
  if (m > nr) {
    x = m - nr;
    cout << x << "\n";
    for (i = 0; i < n; i++) {
      if (!v[i] && x) {
        cout << "X";
        x--;
      } else if (v[i])
        cout << "X";
      else
        cout << "x";
    }
  }
  if (nr >= m) {
    x = nr - m;
    cout << x << "\n";
    for (i = 0; i < n; i++) {
      if (!v[i] && x) {
        cout << "x";
        x--;
      } else if (v[i])
        cout << "X";
      else
        cout << "x";
    }
  }
  return 0;
}
