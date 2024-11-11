#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, arr[10000];
  long long k, ans = 0;
  memset(arr, 0, sizeof(arr));
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (arr[a] == 0 || b < arr[a]) arr[a] = b;
  }
  for (int i = 1; i <= m; i++) {
    ans += arr[i];
  }
  if (ans < k)
    cout << ans;
  else
    cout << k;
  return 0;
}
