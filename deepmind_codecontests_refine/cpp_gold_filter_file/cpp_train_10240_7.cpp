#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
long long a[100010];
int main() {
  int n, q;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  partial_sum(a, a + n, a);
  int k;
  long long ans = 0;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> k;
    if (mp.count(k))
      cout << mp[k] << endl;
    else {
      ans = 0;
      for (long long s = 1, t = 1; s < n; t = t * k, s += t)
        ans += a[n - 1] - a[s - 1];
      mp[k] = ans;
      cout << ans << endl;
    }
  }
  return 0;
}
