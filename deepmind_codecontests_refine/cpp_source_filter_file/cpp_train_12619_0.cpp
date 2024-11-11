#include <bits/stdc++.h>
using namespace std;
int seen[2][100000];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q, x, y;
  cin >> n >> q;
  int close = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    --x;
    --y;
    if (seen[x][y] == 0) {
      seen[x][y] = 1;
      if (y != 0 && seen[x != 1][y - 1] == 1) {
        ++close;
      }
      if (y + 1 != n && seen[x != 1][y + 1] == 1) {
        ++close;
      }
      if (seen[x != 1][y] == 1) {
        ++close;
      }
    } else {
      seen[x][y] = 0;
      if (y != 0 && seen[x != 1][y - 1] == 1) {
        --close;
      }
      if (y + 1 != n && seen[x != 1][y + 1] == 1) {
        --close;
      }
      if (seen[x != 1][y] == 1) {
        --close;
      }
    }
    if (close == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
