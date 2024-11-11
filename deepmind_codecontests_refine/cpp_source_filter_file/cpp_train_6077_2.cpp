#include <bits/stdc++.h>
using namespace std;
const long long int Mod = 1e9 + 7;
const long long int M1 = 998244353;
long long int mod(long long int n) { return ((n % Mod) + Mod) % Mod; }
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = mod(res * x);
    x = mod(x * x);
    y = mod(y >> 1);
  }
  return mod(res);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  vector<long long int> dp(100005, 0);
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int x = v[i];
    vector<long long int> d;
    for (long long int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        d.push_back(i);
        while (x % i == 0) x /= i;
      }
    }
    if (x > 1) d.push_back(x);
    long long int mx = 0;
    for (long long int i = 0; i < d.size(); i++) {
      mx = max(mx, dp[d[i]]);
    }
    mx++;
    for (auto p : d) {
      dp[p] = mx;
    }
    ans = max(mx, mx);
  }
  cout << ans << '\n';
}
