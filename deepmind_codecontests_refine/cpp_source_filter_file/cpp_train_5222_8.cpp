#include <bits/stdc++.h>
using namespace std;
int n, m, h, l, r, x, amax[50], ans;
int main() {
  cin >> n >> m >> h;
  for (int i = 0; i < n; i++) {
    amax[i] = h;
  }
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> x;
    for (int j = l - 1; j < r; j++) {
      amax[j] = min(amax[j], x);
    }
  }
  for (int i = 0; i < n; i++) {
    ans += (amax[i] * amax[i]);
  }
  cout << ans << endl;
}
