#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  int p[n], s[n], c[k], sp[m];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    int ma;
    sp[i] = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == i + 1) {
        ma = p[j];
        sp[i] = max(ma, sp[i]);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    if (p[c[i] - 1] < sp[s[c[i] - 1] - 1]) ans++;
  }
  cout << ans << endl;
  return 0;
}
