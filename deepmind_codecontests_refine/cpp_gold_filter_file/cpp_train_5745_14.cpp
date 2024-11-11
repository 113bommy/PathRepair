#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (h[i] < h[i + 1] - k) {
        int d = h[i + 1] - k - h[i];
        if (d > m) {
          ok = false;
          break;
        } else {
          m -= d;
        }
      } else {
        m += h[i] - max(0, (h[i + 1] - k));
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
