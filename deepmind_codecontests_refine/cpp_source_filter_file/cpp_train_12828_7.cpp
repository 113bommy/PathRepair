#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  cout << max(1, min(N, X + Y - N + 1)) << ' ' << min(N, X + Y - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
