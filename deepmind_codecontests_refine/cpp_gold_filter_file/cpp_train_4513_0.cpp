#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], pos[200005], x, ans;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> x, pos[x] = i;
  for (long long i = 0; i < n; i++) a[i] = pos[a[i]];
  long long ans = n;
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      ans = i - 1;
      break;
    }
  }
  cout << max(0LL, n - 1 - ans);
  return 0;
}
