#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ansl = 0, ansr = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (a[i])
      ++ansr;
    else
      ++ansl;
  }
  int nl = 0, nr = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i])
      ++nl;
    else
      ++nr;
    if (nl == ansl || nr == ansr) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
