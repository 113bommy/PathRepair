#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void solve() {
  long long int n, i, m = 0, q = 0, mx = -20000000000000000,
                      mn = 20000000000000000, k = 0, j = 0, c = 0, d = 0, t = 0,
                      sum = 0, pdt = 1, l = 0, r = 0;
  cin >> n >> m >> k;
  if (k == 0) {
    if (n % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (m == 1) {
    cout << "NO" << endl;
    return;
  }
  if (n % 2 == 0) {
    if (m % 2 == 1) {
      l = (n * (m - 1)) / 2;
      if (k > l) {
        cout << "NO" << endl;
        return;
      }
    }
    if (k % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  q = m / 2;
  if (q < k) {
    cout << "NO" << endl;
    return;
  }
  k -= q;
  n--;
  if (n == 0) {
    cout << "YES" << endl;
    return;
  }
  if (k % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
