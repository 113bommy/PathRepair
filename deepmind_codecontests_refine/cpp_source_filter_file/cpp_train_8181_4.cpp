#include <bits/stdc++.h>
int n, ans, a[1010], f[1010][1010], m[1010][1010];
using namespace std;
int fun(int i, int j) {
  int res, r;
  if (j > n) return a[i];
  if (f[i][j] > 0) return f[i][j];
  res = max(a[i], a[j]) + fun(j + 1, j + 2);
  m[i][j] = 1;
  r = max(a[i], a[j + 1]) + fun(j, j + 2);
  if (r < res) {
    res = r;
    m[i][j] = 2;
  }
  r = max(a[j], a[j + 1]) + fun(i, j + 2);
  if (r < res) {
    res = r;
    m[i][j] = 3;
  }
  f[i][j] = res;
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ans = fun(1, 2);
  cout << ans << endl;
  int i = 1;
  int j = 2;
  while (j <= n) {
    if (m[i][j] == 1) {
      cout << i << " " << j << endl;
      i = j + 1;
      j += 2;
    } else if (m[i][j] == 2) {
      cout << i << " " << j + 1 << endl;
      i = j;
      j += 2;
    } else if (m[i][j] == 3) {
      cout << i << " " << j + 1 << endl;
      j += 2;
    }
  }
  if (i <= n) cout << i << endl;
}
