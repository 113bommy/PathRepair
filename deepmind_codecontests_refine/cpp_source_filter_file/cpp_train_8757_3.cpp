#include <bits/stdc++.h>
const long long mod = 998244353;
using namespace std;
map<long long, long long> mp;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long p;
  for (long long i = n - 1; i >= 0; i--) {
    if (arr[i] == arr[0]) {
      p = i;
      break;
    }
  }
  for (long long i = 0; i < n; i++) {
    mp[arr[i]] = i;
  }
  long long r = 0;
  long long i = 0;
  long long t = 0;
  while (i < n) {
    if (i == t) {
      r++;
    }
    t = max(t, mp[arr[i]] + 1);
    i++;
  }
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans = (ans * 2) % mod;
  }
  cout << ans % mod;
  return 0;
}
