#include <bits/stdc++.h>
using namespace std;
int f(int n) {
  int p = 1;
  while (n > 0) {
    if (n % 10 == 0) {
      n /= 10;
      continue;
    }
    p *= n % 10;
    n /= 10;
  }
  return p;
}
int g(int n) {
  if (n < 10) return n;
  return g(f(n));
}
void solve() {
  int q;
  cin >> q;
  vector<vector<long long>> a(1e6 + 10);
  for (int i = 0; i < a.size(); i++) a[i].resize(10);
  for (int i = 1; i < 1e6 + 1; i++) {
    int ans = g(i);
    for (int j = 1; j <= 9; j++) a[i][j] = a[i - 1][j];
    a[i][ans] += 1;
  }
  for (int i = 0; i < q; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << a[r][k] - a[l - 1][k] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
