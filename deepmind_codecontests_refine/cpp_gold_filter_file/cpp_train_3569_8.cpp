#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int n;
map<pair<int, int>, int> mp;
int gethigh(long long x) {
  for (int i = 31; i >= 0; --i)
    if ((1ll << i) & x) return i;
}
long long solve() {
  long long ans = 0, sum;
  for (int l = 1, r; l <= n; ++l) {
    sum = 0;
    int hl = gethigh(a[l]);
    for (r = l + 1; r < n; ++r) {
      sum += a[r];
      if (sum >= (1ll << (hl + 1))) break;
      if (sum == (a[l] ^ a[r + 1])) {
        ans++;
        mp[{l, r + 1}] = 1;
      }
    }
  }
  for (int r = n, l; r >= 1; --r) {
    sum = 0;
    int hr = gethigh(a[r]);
    for (l = r - 1; l > 1; --l) {
      sum += a[l];
      if (sum >= (1ll << (hr + 1))) break;
      if (sum == (a[l - 1] ^ a[r]) && !mp.count({l - 1, r})) {
        ans++;
        mp[{l - 1, r}] = 1;
      }
    }
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
