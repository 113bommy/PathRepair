#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[1005], b[1005], ans;
bool c[1005], lol;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    lol = false;
    fill(c, c + 1000, false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      c[a[i]] = true;
    }
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
      if (c[b[i]] == true) {
        ans = b[i];
        lol = true;
      }
    }
    if (lol == true)
      cout << "YES\n1 " << ans << "\n";
    else
      cout << "NO\n";
  }
}
