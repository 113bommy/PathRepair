#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = 1000000000, m;
    while (r - l > 1) {
      m = (r + l) / 2;
      if ((n - 1) * m < k)
        l = m;
      else
        r = m;
    }
    cout << l * n + k - l * (n - 1) << "\n";
  }
  return 0;
}
