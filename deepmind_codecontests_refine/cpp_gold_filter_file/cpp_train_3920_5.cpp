#include <bits/stdc++.h>
using namespace std;
long long int par[5000001], ans;
long long int find(long long int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
int main() {
  long long int i, j, n, m, x, y, xp, yp;
  cin >> n >> m;
  for (i = 1; i <= n; i++) par[i] = i;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    xp = find(x);
    yp = find(y);
    if (xp != yp) {
      par[xp] = yp;
      cout << ans << endl;
      continue;
    }
    ans = 2 * ans;
    ans %= 1000000009;
    ans += 1;
    ans %= 1000000009;
    cout << ans << endl;
  }
  return 0;
}
