#include <bits/stdc++.h>
using namespace std;
string s[105];
int ans = 0;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < m - 1; i++) {
      if (s[n - 1][i] != 'R') ans++;
    }
    for (int i = 0; i < n - 1; i++) {
      if (s[i][m - 1] != 'D') ans++;
    }
    cout << ans << endl;
  }
}
