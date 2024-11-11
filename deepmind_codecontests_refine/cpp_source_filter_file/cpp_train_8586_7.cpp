#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> c(n);
  vector<int> ans;
  for (;;) {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (b[i] == c[i]) {
        ans.push_back(i + 1);
        ok = false;
        for (int j = 0; j < n; j++) c[i] += a[i][j] == '1';
      }
    }
    if (ok) break;
  }
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  return 0;
}
