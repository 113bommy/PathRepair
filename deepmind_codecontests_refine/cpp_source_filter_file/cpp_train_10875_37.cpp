#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, mas[55][55], pref[55][55], mn = 1000000;
int get_sum(int x1, int y1, int x2, int y2) {
  if (x1 == 0) x1++;
  return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] +
         pref[x1 - 1][y1 - 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mas[i][j];
    }
  }
  cin >> a >> b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mas[i][j];
    }
  }
  for (int i = a; i <= n; i++) {
    for (int j = b; j <= m; j++) {
      mn = min(mn, get_sum(i - a, j - b, i, j));
    }
  }
  for (int i = b; i <= n; i++) {
    for (int j = a; j <= m; j++) {
      mn = min(mn, get_sum(i - b + 1, j - a + 1, i, j));
    }
  }
  cout << mn;
  return 0;
}
