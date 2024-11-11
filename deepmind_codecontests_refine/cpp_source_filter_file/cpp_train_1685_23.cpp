#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const int N = 2e5 + 10;
using namespace std;
void solve() {
  std::vector<long long> v;
  long long n, x, m, ans = 0;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> x;
    v.push_back(x);
  }
  m = v[n - 1];
  for (long long i = n - 2; i >= 0; --i) {
    if (v[i] < m) {
      m = v[i];
    } else {
      ++ans;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
