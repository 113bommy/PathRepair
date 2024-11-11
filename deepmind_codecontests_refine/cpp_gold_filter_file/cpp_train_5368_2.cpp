#include <bits/stdc++.h>
using namespace std;
int u[100005], v[100005], c[100005], a[100005], ans = 1000000007;
int main() {
  int m, n, k;
  cin >> n >> m >> k;
  for (int i = (1); i <= (m); ++i) cin >> u[i] >> v[i] >> c[i];
  if (k != 0) {
    for (int i = (1); i <= (k); ++i) {
      int x;
      cin >> x;
      a[x] = 1;
    }
  }
  for (int i = (1); i <= (m); ++i) {
    if ((a[u[i]] || a[v[i]]) && a[u[i]] != a[v[i]]) {
      ans = min(ans, c[i]);
    }
  }
  if (k == 0 || ans == 1000000007 || k == n)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
