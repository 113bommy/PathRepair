#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
const int N = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  bool f = 0, a[60][60] = {0};
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 2; i < n; i++) {
    f = f || (a[i][1] == 1) || (a[i][m] == 1);
  }
  for (int i = 1; i <= m; i++) f = f || (a[1][i] == 1) || (a[n][i] == 1);
  if (f)
    cout << 2;
  else
    cout << 4;
}
