#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i, j, ans = 0, x1, x2, y1, y2;
  cin >> n >> m;
  char a[n + 1][m + 1];
  string s;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        x1 = i, y1 = j;
      }
      if (a[i][j] == 'E') {
        x2 = i, y2 = j;
      }
    }
  cin >> s;
  long long p1 = x1, p2 = y1;
  char dir[4] = {'0', '1', '2', '3'};
  do {
    long long f = 0, k;
    x1 = p1, y1 = p2;
    for (i = 0; i < s.size(); i++) {
      for (j = 0; j < 4; j++)
        if (s[i] == dir[j]) k = j;
      if (k == 0) {
        x1--;
      }
      if (k == 1) {
        x1++;
      }
      if (k == 2) {
        y1--;
      }
      if (k == 3) {
        y1++;
      }
      if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || a[x1][y1] == '#') {
        f = 1;
        break;
      }
      if (x1 == x2 && y1 == y2 && !f) {
        ans++, f = 1;
        break;
      }
    }
    if (x1 == x2 && y1 == y2 && !f) ans++;
  } while (next_permutation(dir, dir + 4));
  cout << ans;
  return 0;
}
