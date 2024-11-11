#include <bits/stdc++.h>
using namespace std;
int n, m, j, i, h, l, k, q1, q2, t, q, mx;
long long ans, c, h1, h2, w1, w2, cnt1, cnt2;
void solve() {
  cin >> c >> h1 >> h2 >> w1 >> w2;
  if (h1 * w2 < h2 * w1) {
    swap(h1, h2);
    swap(w1, w2);
  }
  if (w1 >= 1000000) {
    for (j = 0; w1 * j <= c; j++) {
      ans = max(ans, h1 * j + (c - w1 * j) / w2 * h2);
    }
  } else {
    for (j = 0; j < min(w1, c / w2); j++) {
      ans = max(ans, h2 * j + (c - w2 * j) / w1 * h1);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(333);
  solve();
  return 0;
}
