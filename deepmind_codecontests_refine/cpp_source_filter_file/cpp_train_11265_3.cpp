#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  vector<int> b(n);
  vector<int> c(n);
  b[0] = 1;
  c[0] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      b[i] = b[i - 1] + 1;
    } else {
      b[i] = 1;
    }
    c[i] = b[i];
    if (a[i] > a[i - 1]) {
      c[i] = max(c[i], c[i - 1] + 1);
    } else if (i > 1 && a[i] > a[i - 2]) {
      c[i] = max(c[i], b[i - 2] + 1);
    }
    ans = max(ans, c[i]);
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t = 1;
  while (t > 0) {
    t--;
    solve();
  }
  return 0;
}
