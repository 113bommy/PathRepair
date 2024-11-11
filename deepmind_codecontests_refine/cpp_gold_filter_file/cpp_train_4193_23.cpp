#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, c = 0, m;
    cin >> n >> m;
    string s[n];
    for (i = 0; i < n; i++) cin >> s[i];
    for (i = 0; i < m; i++) {
      if (s[n - 1][i] == 'D') c++;
    }
    for (i = 0; i < n; i++) {
      if (s[i][m - 1] == 'R') c++;
    }
    cout << c << endl;
  }
  return 0;
}
