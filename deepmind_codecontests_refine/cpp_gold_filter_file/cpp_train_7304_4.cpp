#include <bits/stdc++.h>
using namespace std;
map<int, int> dct;
void solve() {
  int n, p, k;
  cin >> n >> p >> k;
  const int mod = p;
  for (int i = 0; i != n; ++i) {
    int x;
    cin >> x;
    long long diff = 1LL * x * k % mod;
    x = (1LL * x * x) % mod;
    x = (1LL * x * x) % mod;
    x -= diff;
    if (x < 0) x += mod;
    if (dct.find(x) != dct.end())
      dct[x] += 1;
    else
      dct[x] = 1;
  }
  long long ans = 0;
  for (auto tmp : dct) {
    long long x = tmp.second;
    ans += x * (x - 1) >> 1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
