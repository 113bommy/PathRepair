#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n], x;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int r = a[i] ^ x;
    for (int j = 0; j < 20; j++) {
      if (r & (1 << j)) cnt++;
    }
    if (cnt <= k) ans++;
  }
  cout << ans << endl;
}
