#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 100;
const long long INFLL = 1e18 + 100;
const int MAXN = 3e5 + 100;
char a[81][81];
void is(int x, int y) {
  bool tr = false;
  --x;
  --y;
  for (int i = 3 * x + 1; i <= 3 * (x + 1); ++i)
    for (int j = 3 * y + 1; j <= 3 * (y + 1); ++j)
      if (a[i][j] == '.') {
        a[i][j] = '!';
        tr = 1;
      }
  if (tr) return;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (a[i][j] == '.') a[i][j] = '!';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  if (fopen("sorting"
            ".in",
            "r")) {
    freopen(
        "sorting"
        ".in",
        "r", stdin);
  }
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      cin >> a[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  while (x > 3) x -= 3;
  while (y > 3) y -= 3;
  is(x, y);
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      cout << a[i][j];
      if (j % 3 == 0) cout << ' ';
    }
    if (i % 3 == 0) cout << '\n';
    cout << '\n';
  }
  return 0;
}
