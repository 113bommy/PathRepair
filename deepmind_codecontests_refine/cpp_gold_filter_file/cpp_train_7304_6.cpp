#include <bits/stdc++.h>
using namespace std;
int n;
long long p, k, a[300005], ans;
map<long long, long long> mp, mmp;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> p >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    long long x =
        (a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p + p) % p;
    ans += mp[x];
    if ((a[i] * 2LL % p) * (a[i] * a[i] % p * 2LL % p) % p == k)
      ans += mmp[a[i]];
    mp[x]++;
    mmp[a[i]]++;
  }
  cout << ans << endl;
  return 0;
}
