#include <bits/stdc++.h>
using namespace std;
int n, c, arr[105];
int ans;
int main() {
  int i, j;
  cin >> n >> c;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (i = 2; i <= n; i++) {
    ans = max(ans, arr[i - 1] - arr[i]);
  }
  cout << ans - c;
  return 0;
}
