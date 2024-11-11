#include <bits/stdc++.h>
using namespace std;
int n, m, arr[(long long int)1e5 + 1] = {}, l, w = 0, x, val;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int v = 0; v <= m; ++v) {
    cin >> x;
    if (x == 3) {
      cin >> l;
      cout << (w + arr[l]) << "\n";
    } else if (x == 2) {
      cin >> l;
      w += l;
    } else if (x == 1) {
      cin >> l >> val;
      arr[l] = (val + (-1 * w));
    }
  }
  return 0;
}
