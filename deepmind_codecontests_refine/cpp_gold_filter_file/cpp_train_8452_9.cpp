#include <bits/stdc++.h>
using namespace std;
int t, n, x, a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    int cur1 = 0, cur2 = 0;
    if (a - x < 1) cur1 = x - (a - 1);
    if (b + x > n) cur2 = b + x - n;
    cout << max(min(b + cur1, n) - max(a - x, 1),
                min(b + x, n) - max(a - cur2, 1))
         << '\n';
  }
  return 0;
}
