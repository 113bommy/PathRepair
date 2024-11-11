#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int b[m + 1];
  bool f[n + 1];
  memset(f, true, sizeof(f));
  int ans[n + 1];
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    for (int j = b[i]; j <= n; ++j) {
      if (f[j]) {
        ans[j] = b[i];
        f[j] = false;
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
