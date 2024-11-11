#include <bits/stdc++.h>
using namespace std;
const int64_t Maxe = 1e4;
vector<int64_t> v(Maxe);
void pre_compute() {
  v[1] = 2;
  for (int64_t i = 2; i < Maxe; i++) {
    v[i] = v[i - 1] + (i - 1) + (i * 2);
  }
}
bool check(int64_t mid, int64_t n) {
  if (mid > Maxe) return false;
  return v[mid] <= n;
}
void solve() {
  int64_t n;
  cin >> n;
  int64_t start = 0, end = n, ans = 0, m = 0;
  while (n > 1) {
    start = 0, end = n;
    while (start <= end) {
      int64_t mid = start + (end - start) / 2;
      if (check(mid, n)) {
        m = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    ans++;
    n -= v[m];
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre_compute();
  int64_t test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
