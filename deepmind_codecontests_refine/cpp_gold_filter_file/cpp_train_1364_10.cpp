#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int i, j, k, l = 0, n, ans = 0;
    cin >> n;
    int a[n + 1], c[n + 1];
    for (i = 1; i <= n; i++) cin >> c[i];
    for (i = 1; i <= n; i++) cin >> a[i];
    int visited[n + 1];
    for (i = 0; i <= n; i++) visited[i] = 0;
    for (i = 1; i <= n; i++) {
      if (visited[a[i]] != 0) continue;
      j = a[i];
      while (visited[j] == 0) {
        visited[j] = i;
        j = a[j];
      }
      l = INT_MAX;
      while (visited[j] == i) {
        visited[j] = -1;
        l = min(l, c[j]);
        j = a[j];
      }
      if (l != INT_MAX) ans += l;
    }
    cout << ans << endl;
  }
}
