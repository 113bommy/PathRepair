#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  long long x, f;
  cin >> x >> f;
  long long ans = 0;
  for (auto &q : a) {
    long long l = 0, r = 1e18;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (q > x + mid * (f + x))
        l = mid + 1;
      else
        r = mid;
    }
    ans += l;
  }
  cout << ans * f;
  return 0;
}
