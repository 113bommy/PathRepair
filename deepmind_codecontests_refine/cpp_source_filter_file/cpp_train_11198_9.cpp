#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r, m, ans = 1e9;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    ans = min(ans, l - r + 1);
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) cout << i % ans << " ";
}
