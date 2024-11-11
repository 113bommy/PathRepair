#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int f[n], t[n];
  for (int i = 0; i < n; i++) cin >> f[i] >> t[i];
  int ans = INT_MAX;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] > k)
      x = f[i] - t[i] + k;
    else
      x = f[i];
    ans = max(ans, x);
  }
  cout << ans << endl;
}
