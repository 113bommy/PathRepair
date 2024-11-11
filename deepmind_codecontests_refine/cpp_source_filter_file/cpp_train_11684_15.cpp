#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long i;
  vector<long long> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  long long so = 0, se = 0, io = 0;
  for (i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      se++;
    else
      so++;
  if (se == 0 && so < 2) {
    cout << "-1\n";
    return;
  }
  if (se >= 1) {
    cout << "1\n";
    for (i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        cout << i + 1 << "\n";
        return;
      }
    }
  } else if (se == 0 && so >= 2) {
    cout << "2\n";
    cout << 0 << " " << 1 << "\n";
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
