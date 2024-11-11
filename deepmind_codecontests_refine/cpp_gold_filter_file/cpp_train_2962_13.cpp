#include <bits/stdc++.h>
using namespace std;
long long dist, v[501];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i(1); i <= n; ++i) cin >> v[i];
  double ans(0);
  for (int i(0); i < m; ++i) {
    int a, b;
    cin >> a >> b >> dist;
    ans = max(ans, dist ? (double)(v[a] + v[b]) / dist : 0.0);
  }
  cout << setprecision(20) << ans;
}
