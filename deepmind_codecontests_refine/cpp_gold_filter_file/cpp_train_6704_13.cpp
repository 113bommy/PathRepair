#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 123;
const int K = (int)500;
const int maxn = (int)2e9;
const int mod = (int)1e9 + 7;
long long n;
vector<long long> v;
void solve() {
  cin >> n;
  long long cnt = 1;
  for (int i = 0; i <= 62; ++i) {
    if (i) {
      cnt *= 2ll;
    }
    long long cnt2 = cnt - 1;
    long long ok = 0;
    long long l = 1, r = 1ll * 1e18;
    while (l <= r) {
      long long m = l + (r - l) / 2;
      if (n % m) {
        if ((m - 1) / 2 + cnt2 <= n / m)
          l = m + 1;
        else
          r = m - 1;
        continue;
      }
      if ((m - 1) / 2 + cnt2 == n / m) {
        if (m % 2) {
          ok = m + m * cnt2;
        }
        break;
      }
      if ((m - 1) / 2 + cnt2 < n / m) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (ok) {
      v.push_back(ok);
    }
  }
  if (!(int)v.size()) {
    cout << -1;
    return;
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (long long i : v) {
    cout << i << '\n';
  }
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
