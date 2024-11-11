#include <bits/stdc++.h>
using namespace std;
const long long hell = 1000000007;
const long long mod = 1000000007;
vector<long long> v[1001];
long long vis[1001];
long long solve() {
  long long n;
  cin >> n;
  n = n / 1000;
  if (n & 1)
    cout << 1;
  else {
    cout << 2;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
