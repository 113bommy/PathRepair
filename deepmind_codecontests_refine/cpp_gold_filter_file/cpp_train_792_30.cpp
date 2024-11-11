#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  string ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int check = 1;
      for (int k = 0; k < m; k++) {
        if (k != j && s[i][k] == s[i][j]) check = 0;
      }
      for (int k = 0; k < n; k++) {
        if (k != i && s[k][j] == s[i][j]) check = 0;
      }
      if (check) ans += s[i][j];
    }
  }
  cout << ans;
}
