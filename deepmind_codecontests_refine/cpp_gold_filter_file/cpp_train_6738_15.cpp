#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, l, d, ans = 0, in = 0;
  cin >> n >> k >> l;
  vector<long long> a(n * k);
  for (int i = 0; i < (int)n * k; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  d = upper_bound(a.begin(), a.end(), l + a[0]) - a.begin() - n;
  --k;
  if (d < 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < (int)n; ++i) {
    ans += a[in];
    ++in;
    if (d >= k) {
      d -= k;
      in += k;
    } else {
      in += d;
      d = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
