#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int MAXN = 2e5 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  long long int arr[n + 1];
  memset(arr, 0, sizeof(arr));
  for (long long int i = 1; i <= m; i++) {
    long long int x, y;
    cin >> x >> y;
    arr[x]++, arr[y]++;
  }
  long long int ans;
  for (long long int i = 1; i <= n; i++) {
    if (!arr[i]) {
      ans = i;
      break;
    }
  }
  cout << n - 1 << '\n';
  for (long long int i = 1; i < n; i++) {
    if (i != ans) {
      cout << ans << " " << i << '\n';
    }
  }
  return 0;
}
