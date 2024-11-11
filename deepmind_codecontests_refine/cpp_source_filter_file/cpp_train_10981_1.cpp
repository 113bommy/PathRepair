#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r, x;
  cin >> n >> l >> r >> x;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int s = (1 << n);
  ll ways = 0;
  for (int i = 1; i < s; i++) {
    ll sum = 0, mi = 100001, mx = -1, num = i;
    for (int j = n - 1; j >= 0; j--) {
      if (num & 1) {
        sum += v[j];
        mi = min(mi, v[j]);
        mx = max(mx, v[j]);
      }
      num >>= 1;
    }
    if (sum >= l && sum <= r && (mx - mi >= x)) ++ways;
  }
  cout << ways;
}
