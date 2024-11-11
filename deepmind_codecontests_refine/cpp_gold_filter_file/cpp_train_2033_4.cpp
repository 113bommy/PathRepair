#include <bits/stdc++.h>
using namespace std;
const long long BIG_INT = 1e6 + 3;
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  int fr = 0, se = 1, t, x;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      fr = (fr + x + n) % n;
      se = (se + x + n) % n;
    } else {
      if (fr % 2 == 0)
        fr++;
      else
        fr--;
      if (se % 2 == 0)
        se++;
      else
        se--;
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i += 2) ans[(i + fr + n) % n] = i + 1;
  for (int i = 0; i < n; i += 2) ans[(i + se + n) % n] = i + 2;
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
