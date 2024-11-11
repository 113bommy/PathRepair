#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        vector<bool> vis(n, false);
        vis[i] = vis[j] = true;
        int sum = a[i] + a[j];
        int l, m;
        l = 0;
        m = n - 1;
        cnt = 1;
        while (l < m) {
          if (vis[l] && vis[m]) {
            l++;
            m--;
          } else if (vis[l] || a[l] + a[m] < sum) {
            l++;
          } else if (vis[m] || a[l] + a[m] > sum) {
            m--;
          } else if (a[l] + a[m] == sum) {
            cnt++;
            l++;
            m--;
          }
        }
        ans = max(ans, cnt);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
