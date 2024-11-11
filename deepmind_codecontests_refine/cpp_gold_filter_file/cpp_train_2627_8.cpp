#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  ++n;
  vector<long long> b(n), a(n, 0);
  for (long long i = 1; i < n; ++i) {
    cin >> b[i];
  }
  a[1] = b[1];
  for (long long i = 2; i < n; ++i) {
    a[i] = b[i] + max(a[i - 1] - b[i - 1], a[i - 1]);
  }
  for (long long i = 1; i < n; ++i) cout << a[i] << " ";
  cout << "\n";
}
void speed_up() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  long long t = 1;
  for (long long i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
