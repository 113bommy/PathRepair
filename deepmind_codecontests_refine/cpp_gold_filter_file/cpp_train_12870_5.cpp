#include <bits/stdc++.h>
using namespace std;
long long n, x, k, arr[100005], ans;
map<long long, long long> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  if (k == 0) {
    for (long long i = n; i >= 1; i--) {
      if (arr[i] % x == 0) continue;
      mp[arr[i] / x]++;
      ans += mp[arr[i] / x];
    }
    mp.clear();
    for (long long i = 1; i <= n; i++) {
      if (arr[i] % x == 0) continue;
      ans += mp[arr[i]];
      mp[arr[i]]++;
    }
    cout << ans << endl;
    return 0;
  }
  for (long long i = n; i >= 1; i--) {
    mp[arr[i] / x]++;
    ans += mp[((arr[i] - 1) / x) + k];
  }
  mp.clear();
  for (long long i = 1; i <= n; i++) {
    ans += mp[((arr[i] - 1) / x) + k];
    mp[arr[i] / x]++;
  }
  cout << ans << endl;
  return 0;
}
