#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int ans = 0;
    int n, c, d;
    cin >> n >> c >> d;
    if (n) n--, ans++;
    if (c) c--, ans++;
    if (d) d--, ans++;
    if (n < c) swap(n, c);
    if (n < d) swap(n, d);
    if (n && d) n--, d--, ans++;
    if (n && c) n--, c--, ans++;
    if (n && c) d--, c--, ans++;
    if (n && d && c > 0) ans++;
    cout << ans << endl;
  }
}
