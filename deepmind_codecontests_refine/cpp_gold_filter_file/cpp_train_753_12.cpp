#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1000000007;
void solve() {
  long long n, k, m1 = -MOD, m2 = -MOD;
  cin >> n >> k;
  vector<long long> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) cin >> a[i], m1 = max(m1, a[i]);
  for (int i = 0; i < n; i++) {
    b[i] = m1 - a[i];
    m2 = max(m2, b[i]);
  }
  for (int i = 0; i < n; i++) c[i] = m2 - b[i];
  if (k % 2) {
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
  } else {
    for (int i = 0; i < n; i++) cout << c[i] << " ";
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
