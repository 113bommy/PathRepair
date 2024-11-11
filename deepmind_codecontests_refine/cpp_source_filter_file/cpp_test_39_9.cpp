#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
long long ceel(long long a, long long b) { return ((a + b - 1ll) / b); }
void solve() {
  long long n;
  cin >> n;
  string s;
  long long ans[n + 1];
  long long flag = 0;
  long long x;
  long long idx = 1;
  while (idx < n) {
    cout << "? ";
    for (long long i = 0; i < n - 1; i++) cout << idx << ' ';
    cout << n << '\n';
    cout.flush();
    cin >> x;
    if (x) {
      break;
    }
    idx++;
  }
  ans[n] = idx;
  for (long long i = 1; i < n + 1; i++) {
    cout << '? ';
    for (long long i = 0; i < n - 1; i++) {
      cout << idx << " ";
    }
    cout << i << '\n';
    cout.flush();
    cin >> x;
    ans[x] = i;
  }
  cout << "! ";
  for (long long i = 0; i < n; i++) {
    cout << ans[i + 1] << " ";
  }
  cout << '\n';
  cout.flush();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  for (long long tc = 0; tc < t; tc++) {
    solve();
  }
  return 0;
}
