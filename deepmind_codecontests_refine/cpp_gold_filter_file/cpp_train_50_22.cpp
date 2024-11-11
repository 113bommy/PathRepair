#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, d, i, j, k, x;
  cin >> n >> m;
  vector<bool> a(m + 1, false);
  for (i = 0; i < n; i++) {
    cin >> d;
    while (d--) {
      cin >> x;
      a[x] = true;
    }
  }
  bool ans = true;
  for (i = 1; i <= m; i++) {
    if (!a[i]) ans = false;
  }
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
