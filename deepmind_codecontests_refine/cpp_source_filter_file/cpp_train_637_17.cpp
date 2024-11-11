#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n, m, p = 0, g = 0, pg;
  cin >> n >> m;
  long long int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1) p++;
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
    if (b[j] & 1) g++;
  }
  p = min(p, m - g);
  g = min(g, n - p);
  cout << p + g << "\n";
}
