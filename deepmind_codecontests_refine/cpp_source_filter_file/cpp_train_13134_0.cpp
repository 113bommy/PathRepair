#include <bits/stdc++.h>
using namespace std;
long long n, p, k, a[100001], x, ans;
unordered_map<long long, long long> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    mp[((x * x) % p * (x * x) % p + p * p - k * x) % p]++;
  }
  for (auto it : mp) {
    ans += it.second * (it.second - 1) / 2;
  }
  cout << ans;
  return 0;
}
