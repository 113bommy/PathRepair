#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  char x[55][55];
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> x[i][j];
  bool pass = false;
  for (int i = 1; i <= n; i++)
    if (x[i][0] == '1' || x[i][m] == '1') pass = true;
  for (int j = 1; j <= m; j++)
    if (x[0][j] == '1' || x[n][j] == '1') pass = true;
  if (pass = false)
    cout << 4;
  else
    cout << 2;
  return 0;
}
