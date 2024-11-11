#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s[1000];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < m; j++) {
      bool t = 1, x = 1;
      for (int k = 0; k < m; k++) {
        if (s[i][k] == '#' && s[j][k] == '#') t = 0;
        if (s[i][k] != s[j][k]) x = 0;
      }
      if (!t && !x) {
        cout << "No";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < m; j++) {
      bool t = 1, x = 1;
      for (int k = 0; k < m; k++) {
        if (s[k][i] == '#' && s[k][j] == '#') t = 0;
        if (s[k][i] != s[k][j]) x = 0;
      }
      if (!t && !x) {
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  return 0;
}
