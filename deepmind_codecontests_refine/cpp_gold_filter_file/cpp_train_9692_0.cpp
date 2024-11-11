#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int l = m, r = 0, up = n, down = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'B') {
        l = min(l, j);
        r = max(r, j);
        up = min(up, i);
        down = max(down, i);
      }
    }
  }
  cout << (up + down) / 2 + 1 << " " << (l + r) / 2 + 1 << endl;
}
