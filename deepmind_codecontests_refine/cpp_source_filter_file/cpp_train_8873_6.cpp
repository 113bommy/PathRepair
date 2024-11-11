#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n + 2][n + 2];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) a[i][j] = s[j] - '0';
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (a[i][j] == 1 && (a[i + 1][j] == 0 && a[i][j + 1] == 0)) {
        cout << "NO\n";
        return;
      }
  cout << "YES\n";
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
}
