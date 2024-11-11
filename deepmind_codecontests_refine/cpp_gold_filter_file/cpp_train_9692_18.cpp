#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, r, c1, c2;
  cin >> n >> m;
  bool h = false;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'B') {
        r = i + 1;
        c1 = j + 1;
        while (j < m && s[j + 1] == 'B') j++;
        c2 = j + 1;
        h = true;
        break;
      }
    }
    if (h) break;
  }
  cout << r + (c2 - c1) / 2 << ' ' << (c1 + c2) / 2 << endl;
  return 0;
}
