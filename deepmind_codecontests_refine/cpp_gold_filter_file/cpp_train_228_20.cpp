#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40;
int pos[MAXN];
const int maxn = 2 * 1e5 + 5;
int a[MAXN];
int chars[maxn][27];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int m;
    cin >> n >> m;
    string ss;
    cin >> ss;
    for (int y = 1; y <= n; y++) {
      for (int j = 1; j <= 26; j++) {
        chars[y][j] = chars[y - 1][j];
        if (ss[y - 1] - 'a' + 1 == j) chars[y][j] += 1;
      }
    }
    memset(pos, 0, sizeof(pos));
    for (int y = 1; y <= m + 1; y++) {
      int ds;
      if (y == m + 1)
        ds = n;
      else
        cin >> ds;
      for (int y = 1; y <= 26; y++) {
        pos[y] += chars[ds][y];
      }
    }
    for (int y = 1; y <= 26; y++) {
      cout << pos[y] << ' ';
    }
    cout << endl;
  }
  return 0;
}
