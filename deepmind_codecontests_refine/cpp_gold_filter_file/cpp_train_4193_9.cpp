#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char s[n][m];
    for (int i = 0; i < n; i++) cin >> s[i];
    int cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (s[i][m - 1] != 'D') cnt++;
    }
    for (int i = m - 2; i >= 0; i--)
      if (s[n - 1][i] != 'R') cnt++;
    cout << cnt << endl;
  }
  return 0;
}
