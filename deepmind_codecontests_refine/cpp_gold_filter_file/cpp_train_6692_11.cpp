#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, c = 0, n;
  string s;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s;
    c = (int(s[0]) - 49) * 10;
    if (s.size() == 1) {
      c += 1;
    }
    if (s.size() == 2) {
      c += 3;
    }
    if (s.size() == 3) {
      c += 6;
    }
    if (s.size() == 4) {
      c += 10;
    }
    cout << c << endl;
  }
  return 0;
}
