#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int row[1001];
int main() {
  cin >> n >> m >> k;
  memset(row, 0, sizeof(row));
  for (int i = 0; i < n; i++) {
    int r, v;
    cin >> r >> v;
    r--;
    if (row[r] == 0)
      row[r] = v;
    else
      row[r] = min(row[r], v);
  }
  int i, ans = 0;
  for (int i = 0; i < m; i++) ans += row[i];
  ans = min(ans, k);
  cout << ans << endl;
  return 0;
}
