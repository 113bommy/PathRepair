#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (s[i][j] == '.') {
        if (s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i][j + 1] &&
            s[i + 1][j] == '.') {
          s[i][j] = '#';
          s[i - 1][j] = '#';
          s[i][j - 1] = '#';
          s[i][j + 1] = '#';
          s[i + 1][j] = '#';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '.') return cout << "NO" << endl, 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
