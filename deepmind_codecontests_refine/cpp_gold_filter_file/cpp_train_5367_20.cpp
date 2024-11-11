#include <bits/stdc++.h>
using namespace std;
int arr[100006][3], ax[100007], n, m, k;
int ans = 10e9;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    ax[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    if (ax[arr[i][0]] ^ ax[arr[i][1]]) {
      ans = min(ans, arr[i][2]);
    }
  }
  if (ans == INT_MAX)
    cout << "-1";
  else
    cout << ans;
  return 0;
}
