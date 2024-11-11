#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(2e5 + 7);
int n, k, a[507][507], ans;
int main() {
  cin >> n >> k;
  int col = n, row = 1, i;
  for (i = n * n; row <= n && i >= 1; i--) {
    while (col != k) a[row][col] = i, col--, i--;
    a[row][col] = i;
    ans += i;
    col = n;
    row++;
  }
  row = 1, col = k - 1;
  for (; i >= 1; i--) {
    while (col > 0) a[row][col] = i, col--, i--;
    col = k - 1;
    row++;
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
