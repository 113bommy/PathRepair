#include <bits/stdc++.h>
using namespace std;
int cnt[3][110000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      cnt[0][0] = 0;
      cnt[1][0] = 0;
      cnt[2][0] = 0;
      cnt[s[i] - 'x'][0] = 1;
    } else {
      cnt[0][i] = cnt[0][i - 1];
      cnt[1][i] = cnt[1][i - 1];
      cnt[2][i] = cnt[2][i - 1];
      cnt[s[i] - 'x'][i]++;
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x1, x2;
    cin >> x1 >> x2;
    int c1, c2, c3;
    if (x1 == 1) {
      c1 = cnt[0][x2 - 1];
      c2 = cnt[1][x2 - 1];
      c3 = cnt[2][x2 - 1];
    } else {
      c1 = cnt[0][x2 - 1] - cnt[0][x1 - 2];
      c2 = cnt[1][x2 - 1] - cnt[1][x1 - 2];
      c3 = cnt[2][x2 - 1] - cnt[1][x1 - 2];
    }
    if (c1 + c2 + c3 < 3)
      cout << "YES\n";
    else if (max(c3, max(c1, c2)) - min(c3, min(c1, c2)) <= 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
