#include <bits/stdc++.h>
using namespace std;
struct query {
  int t, l, r;
};
int main() {
  ios::sync_with_stdio(0);
  int n, q, m;
  cin >> n >> q >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<query> qs(q);
  for (int i = 0; i < q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    qs[i] = {t, l, r};
  }
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    for (int j = q - 1; j >= 0; j--) {
      auto [t, l, r] = qs[j];
      if (not(b >= l and b <= r)) continue;
      if (t == 1) {
        if (b == l)
          b = r;
        else
          b = b - 1;
      } else {
        b = l + (r - b);
      }
    }
    cout << b << " ";
  }
  return 0;
}
