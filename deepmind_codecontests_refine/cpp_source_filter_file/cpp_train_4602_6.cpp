#include <bits/stdc++.h>
using namespace std;
int t, m, n, x, l1, l2, c1, c2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    l1 = l2 = c1 = c2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x % 2 == 0)
        c1++;
      else
        l1++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
      cin >> x;
      if (x % 2 == 0)
        c2++;
      else
        l2++;
    }
    cout << l1 * l2 + c1 * c2 << "\n";
  }
}
