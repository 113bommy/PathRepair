#include <bits/stdc++.h>
const int N = 1000007, inf = 0x3f3f3f3f;
using namespace std;
const int M = 1000000007;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  long long ans = x * n % M;
  vector<long long> R(n);
  multiset<long long> L;
  for (int i = 1; i <= n; ++i) {
    long long a, b;
    cin >> a >> b;
    ans += (b - a) * y % M;
    ans %= M;
    R[i - 1] = b;
    L.insert(a);
  }
  sort(R.begin(), R.end());
  for (long long r : R) {
    auto it = L.upper_bound(r);
    if (it != L.end()) {
      long long l = *it;
      if (y * (l - r) < x) {
        ans -= x;
        ans += M;
        ans %= M;
        ans += y * (l - r) % M;
        ans %= M;
      }
      L.erase(it);
    }
  }
  cout << ans << endl;
}
