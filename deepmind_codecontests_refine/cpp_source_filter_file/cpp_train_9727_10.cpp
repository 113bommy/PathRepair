#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
int a[MAXN][MAXN];
long long po[MAXN];
long long p;
int main() {
  int n, m;
  cin >> n >> m;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (n >= m)
      a[x][y] = z;
    else
      a[y][x] = z;
  }
  if (n < m) {
    int c = n;
    n = m;
    m = c;
  }
  cin >> p;
  if (n % 2 != m % 2) {
    cout << 0 << endl;
    return 0;
  }
  po[0] = 1;
  for (int i = 1; i <= max(n, m); i++) po[i] = (po[i - 1] * 2) % p;
  long long ans = 1;
  bool nem = false;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    int x = 1;
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 0)
        sum++;
      else
        x *= a[i][j];
    if (sum == 0 && x == -1) {
      cout << 0 << endl;
      return 0;
    }
    if (sum == m && !nem) {
      nem = true;
      continue;
    }
    if (sum == 0) continue;
    ans = ans * po[sum - 1];
    ans %= p;
  }
  cout << ans << endl;
}
