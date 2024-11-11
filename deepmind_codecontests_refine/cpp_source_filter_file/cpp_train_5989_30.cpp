#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  char ch[n + 5][n + 5];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> ch[i];
  int row, col, ans = 0;
  for (int i = 1; i <= n; i++) {
    row = col = 0;
    for (int j = 1; j <= n; j++) {
      if (ch[i][j] == 'C') row++;
      if (ch[j][i] == 'C') col++;
    }
    ans += (row * (row - 1) / 2) + (col * (col - 1) / 2);
  }
  cout << ans << "\n";
  return 0;
}
