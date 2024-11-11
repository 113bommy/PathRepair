#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k1, k2;
  cin >> n >> k1 >> k2;
  long long one = 0;
  long long c;
  for (long long i = 0; i < k1; i++) {
    cin >> c;
    if (c == n) one == 1;
  }
  for (long long i = 0; i < k2; i++) {
    cin >> c;
  }
  if (one)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
