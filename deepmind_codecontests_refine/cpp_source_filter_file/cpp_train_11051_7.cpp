#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10, oo = 1e9 + 10;
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 1];
  ll sumA = 0, sumB = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sumA += a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    sumB += b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  if (a[n] > b[1]) {
    cout << "-1\n";
    return;
  }
  ll ans;
  if (a[n] != b[1]) {
    ans = sumA * m + sumB - (m - 1) * a[n] - a[n - 1];
  } else {
    ans = sumA * m + sumB - m * a[n];
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
}
