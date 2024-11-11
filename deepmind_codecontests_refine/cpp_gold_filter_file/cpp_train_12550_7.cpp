#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans++;
    if (i == 0) break;
    if (ar[i] - ar[i - 1] > k) break;
  }
  cout << ans;
  return 0;
}
