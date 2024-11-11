#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long arr[n];
  for (auto& i : arr) cin >> i;
  long long ans = 0;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    ans += min(arr[x - 1], arr[y - 1]);
  }
  cout << ans << endl;
  return 0;
}
