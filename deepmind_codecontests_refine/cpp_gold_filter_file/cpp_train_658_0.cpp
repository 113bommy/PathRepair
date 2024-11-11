#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[60], b[60];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];
  int BG = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(b[j] % a[i])) {
        if (b[j] / a[i] > BG) {
          BG = b[j] / a[i];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(b[j] % a[i]) && b[j] / a[i] == BG) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
