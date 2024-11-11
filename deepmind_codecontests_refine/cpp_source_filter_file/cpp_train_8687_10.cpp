#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int a[m + 1];
  for (int i = 0; i < m + 1; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int count = 0;
    for (int j = 0; j < 20; j++) {
      if ((a[m] >> j) & 1 != (a[i] >> j) & 1) {
        count++;
      }
    }
    if (count <= k) ans++;
  }
  cout << ans;
}
