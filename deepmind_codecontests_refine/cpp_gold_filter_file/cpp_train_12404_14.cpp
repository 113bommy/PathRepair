#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, mi = 1100, ma = 0, a, i;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> r;
  for (i = 1; i <= n; i++) {
    cin >> a;
    mi = min(mi, a);
  }
  for (i = 1; i <= m; i++) {
    cin >> a;
    ma = max(ma, a);
  }
  cout << max((r / mi) * ma + r % mi, r);
}
