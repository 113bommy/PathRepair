#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
  int N, X;
  cin >> N >> X;
  int y = -1, z = -1;
  for (int i = 0; i < N; ++i) {
    int d, h;
    cin >> d >> h;
    y = max(y, d - h);
    z = max(z, d);
  }
  if (y <= 0) {
    cout << -1 << endl;
    return;
  }
  if (z >= X) {
    cout << 1 << endl;
    return;
  }
  cout << (X - z + y - 1) / y + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
