#include <bits/stdc++.h>
using namespace std;
int n, m, a[1234];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    int l, r, x, tt = 0;
    cin >> l >> r >> x;
    l--, r--, x--;
    for (int j = l; j <= r; j++)
      if (a[j] < a[x]) tt++;
    if (x == l + tt)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
