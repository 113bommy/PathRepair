#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int N = 200005;
long long int a[N];
signed main() {
  ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  if (0) {
    freopen("inp.txt", "r", stdin);
  }
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= 2 * n; i++) cin >> a[i];
  sort(a + 1, a + 2 * n + 1);
  long long int ans = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
  for (long long int i = 2; i <= n; i++) {
    ans = min(ans, (a[n + i - 1] - a[i]) * (a[2 * n] - a[1]));
  }
  cout << ans;
  return 0;
}
