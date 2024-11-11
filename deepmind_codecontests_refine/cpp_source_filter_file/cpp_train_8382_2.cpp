#include <bits/stdc++.h>
using namespace std;
long long int m, n, tmp, ans, i, j, t, mn[312345], pos[312345], a[312345], x, y;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("inp.txt", "r")) freopen("inp.txt", "r", stdin);
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) pos[a[i]] = i;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    long long int p = pos[x];
    long long int q = pos[y];
    if (p > q) {
      long long int c = p;
      p = q;
      q = c;
    }
    if (mn[p] == 0)
      mn[p] = q;
    else if (q < mn[p])
      mn[p] = q;
  }
  long long int rg = n;
  for (i = n - 1; i >= 0; i--) {
    if (mn[i] != 0) rg = mn[i];
    ans = ans + rg - i;
  }
  cout << ans;
  return 0;
}
