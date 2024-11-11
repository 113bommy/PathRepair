#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int si = n * k;
  vector<int> V(si);
  for (auto& b : V) {
    cin >> b;
  }
  sort(V.begin(), V.end());
  int ind = ((n - 1) / 2) * (k), ans = 0;
  while (ind < si) {
    ans += V[ind];
    ind += (n + 2) / 2;
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
