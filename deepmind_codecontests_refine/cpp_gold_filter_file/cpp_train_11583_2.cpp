#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, j, cno = 0, k;
  int t, n, m, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    string s;
    cin >> s;
    x = 0;
    y = 0;
    bool noone = true;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') {
        noone = false;
        y += (i - x) / (m + 1);
        x = i + (m + 1);
      }
    }
    if (x < n) y += 1 + ((n - 1) - x) / (m + 1);
    if (noone)
      cout << 1 + (n - 1) / (m + 1) << "\n";
    else
      cout << y << "\n";
  }
  return 0;
}
