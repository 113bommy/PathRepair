#include <bits/stdc++.h>
using namespace std;
string s[150];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (int j = 0; j < n; j++) {
      int cur = s[i][j];
      bool chk = true;
      for (int k = 0; k < n; k++) {
        if (cur < s[k][j]) chk = false;
      }
      ok |= chk;
    }
    if (ok) ans++;
  }
  cout << ans;
}
