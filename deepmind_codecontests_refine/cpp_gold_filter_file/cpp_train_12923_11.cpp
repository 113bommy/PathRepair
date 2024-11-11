#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, b;
  cin >> n >> b;
  long long k = b;
  map<long long, long long> mp;
  for (long long j = 2; j * j <= b; j++) {
    while (k % j == 0) {
      mp[j]++;
      k /= j;
    }
  }
  if (k > 1) {
    mp[k]++;
  }
  map<long long, long long> mp1;
  for (auto x : mp) {
    long long k1 = n;
    long long x1 = x.first;
    while (k1 > 0) {
      mp1[x1] += (k1 / x1);
      k1 /= x1;
    }
  }
  long long ans = LONG_LONG_MAX;
  for (auto x : mp1) {
    ans = min(ans, 1LL * (x.second) / (mp[x.first]));
  }
  cout << ans << endl;
  return 0;
}
