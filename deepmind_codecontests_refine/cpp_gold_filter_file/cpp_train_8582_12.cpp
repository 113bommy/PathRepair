#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, b, c, i, j, k;
  string x, s[] = {"vaporeon", "jolteon", "flareon", "espeon",
                   "umbreon",  "leafeon", "glaceon", "sylveon"};
  cin >> n >> x;
  for (i = 0; i < 8; i++) {
    if (s[i].size() == n) {
      bool y = true;
      for (j = 0; j < n; j++) {
        if (!(x[j] == s[i][j] || x[j] == '.')) y = false;
      }
      if (y) {
        cout << s[i];
        return 0;
      }
    }
  }
  return 0;
}
