#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 2];
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int counter[n + 2][27];
    memset(counter, 0, sizeof(counter));
    for (int i = n; i != 0; --i) {
      for (int j = 1; j != 27; ++j) counter[i][j] = counter[i + 1][j];
      ++counter[i][arr[i]];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (arr[i] != arr[j]) continue;
        int b = arr[i];
        int allb = counter[i][b] - counter[j + 1][b];
        for (int a = 1; a != 27; ++a) {
          int righta = counter[j + 1][a];
          int lefta = counter[1][a] - counter[i][a];
          ans = max(ans, allb + (2 * min(lefta, righta)));
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
