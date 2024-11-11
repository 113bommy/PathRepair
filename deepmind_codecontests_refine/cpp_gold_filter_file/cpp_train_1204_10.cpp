#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i, j;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  ;
  int ans[100000 + 1] = {0};
  int m;
  for (i = (0); (i) <= (n - 1); ++(i)) {
    m = arr[i];
    for (j = 2; j * j <= m; j++) {
      if (m % j == 0) {
        while (m % j == 0) m = m / j;
        ans[j]++;
      }
    }
    if (m != 1) ans[m]++;
  }
  int res = *max_element(ans, ans + 100000 + 1);
  if (res == 0) res = 1;
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
