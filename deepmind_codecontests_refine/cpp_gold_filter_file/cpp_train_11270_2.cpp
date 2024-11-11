#include <bits/stdc++.h>
using namespace std;
void solve() {
  int32_t n;
  cin >> n;
  vector<int32_t> niz(n);
  vector<int32_t> a(n);
  vector<int32_t> b(n);
  for (int32_t i = 0; i < n; i++) {
    cin >> niz[i];
  }
  a[0] = niz[0];
  b[n - 1] = niz[n - 1];
  for (int32_t i = 1; i < n; i++) a[i] = min(a[i - 1], niz[i]);
  for (int32_t i = n - 2; i >= 0; i--) b[i] = min(b[i + 1], niz[i]);
  bool can = false;
  for (int32_t i = 1; i <= n - 2; i++) {
    if (a[i - 1] < niz[i] && b[i + 1] < niz[i]) {
      cout << "YES" << endl;
      for (int32_t j = 0; j < i; j++) {
        if (niz[j] < niz[i]) {
          cout << j + 1 << " ";
          break;
        }
      }
      cout << i + 1 << " ";
      for (int32_t j = i + 1; j < n; j++) {
        if (niz[j] < niz[i]) {
          cout << j + 1 << endl;
          break;
        }
      }
      return;
    }
  }
  cout << "NO" << endl;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int32_t t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
