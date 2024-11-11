#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll n, ans = 0, x;
  cin >> n;
  unordered_map<ll, ll> mp;
  for (int i = 1; i <= n; ++i) scanf("%lld", &x), ans += mp[i - x], mp[i + x]++;
  cout << ans << endl;
  return 0;
}
