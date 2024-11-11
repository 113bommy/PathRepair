#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, d;
  cin >> n >> d;
  if (n * (n - 1) / 2 < d || n > 100 && d <= 3 * n) {
    cout << "NO\n";
    return;
  }
  int p[n + 1], dd[n + 1], cntd[n + 1];
  for (int i = 0; i < n; ++i) {
    dd[i] = i;
    p[i] = i - 1;
    cntd[i] = 1;
  }
  cntd[n - 1] = 0;
  int nd = n * (n - 1) / 2;
  bool u[n + 1];
  for (int i = 0; i < n; ++i) u[i] = false;
  while (nd != d) {
    bool ok = true, ok2 = false;
    for (int i = 0; i < n; ++i) ok &= u[i];
    if (ok) {
      cout << "NO\n";
      return;
    }
    for (int i = 0; i < n && !ok2; ++i) {
      if (u[i] || cntd[i]) continue;
      ok = false;
      for (int j = 0; j < n && !ok; ++j) {
        if (dd[j] == dd[i] - 2 && cntd[j] < 2) {
          cntd[p[i]]--;
          p[i] = j;
          cntd[j]++;
          dd[i]--;
          ok = true;
        }
      }
      if (!ok)
        u[i] = 1;
      else
        ok2 = true;
    }
    if (!ok2) {
      cout << "NO\n";
      return;
    }
    nd--;
  }
  cout << "YES\n";
  for (int i = 1; i < n; ++i) cout << p[i] + 1 << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
