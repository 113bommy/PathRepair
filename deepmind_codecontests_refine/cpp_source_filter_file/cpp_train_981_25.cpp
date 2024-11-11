#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, j, kt = 0;
  cin >> n >> m >> k;
  string s[2003];
  for (i = 0; i < n; i++) cin >> s[i];
  int pos[2003];
  memset(pos, 0, sizeof(pos));
  for (i = 1; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s[i][j] != '.') {
        if (s[i][j] == 'L') {
          if (j - i >= 0) pos[j - i]++;
        } else if (s[i][j] == 'R') {
          if (j + i < m) pos[j + i]++;
        } else if (s[i][j] == 'U' && i != 1) {
          pos[j]++;
        }
      }
    }
  }
  for (i = 0; i < m; i++) {
    cout << pos[i] << ' ';
  }
  return 0;
}
