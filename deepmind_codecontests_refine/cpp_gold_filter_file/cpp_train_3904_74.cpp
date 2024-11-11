#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  bool xorr = false;
  cin >> n >> m >> k;
  while (k--) {
    int l, r;
    cin >> l >> r;
    if ((r <= 5) || (m - r < 5) || (l <= 5) || (n - l < 5)) xorr = true;
  }
  if (xorr)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
