#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long val = 0;
  bool ok = true;
  for (long long i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    if (temp < val) ok = false;
    val = temp;
  }
  if (ok && n % 2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
