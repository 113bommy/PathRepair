#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, k = 0, c = 0, i, rock = 0, jump = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  for (i = 1; i < n - 1; i++) {
    if (s[i] == '#') {
      rock++;
      if (rock > jump + 1) {
        k = 1;
        break;
      }
    } else {
      rock = 0;
    }
  }
  if (k == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
