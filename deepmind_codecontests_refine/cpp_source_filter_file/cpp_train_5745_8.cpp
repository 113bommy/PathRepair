#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    bool ok = true;
    int h, prev;
    cin >> prev;
    for (int i = 1; i < n; i++) {
      cin >> h;
      int p = max(h - k, 0);
      if (prev >= p)
        m += prev - 0;
      else
        m -= (p - prev);
      if (m < 0) {
        ok = false;
      }
      prev = h;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
