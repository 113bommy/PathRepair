#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[m], x;
  for (int i = 0; i < m; i++) cin >> a[i];
  cin >> x;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    int r = a[i] ^ x;
    for (int j = 0; j < n; j++) {
      if (r & (1 << j)) cnt++;
    }
    if (cnt <= k) ans++;
  }
  cout << ans << endl;
}
