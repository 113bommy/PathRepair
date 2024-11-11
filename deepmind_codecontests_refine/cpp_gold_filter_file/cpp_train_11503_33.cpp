#include <bits/stdc++.h>
using namespace std;
inline void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
void solve() {
  int ans = 0;
  int n, m;
  cin >> n >> m;
  int d, h, pd, ph;
  cin >> pd >> ph;
  ans = ph + pd - 1;
  for (int i = 1; i < m; i++) {
    cin >> d >> h;
    if (abs(d - pd) < abs(h - ph)) {
      cout << "IMPOSSIBLE";
      return;
    }
    int H = max(h, ph) + (d - pd - abs(h - ph)) / 2;
    ans = max(ans, H);
    pd = d;
    ph = h;
  }
  ans = max(ans, ph + n - pd);
  cout << ans;
}
