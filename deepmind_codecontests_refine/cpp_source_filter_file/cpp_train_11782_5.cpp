#include <bits/stdc++.h>
using namespace std;
int k, n, a, b, val;
void solve() {
  cin >> k >> n >> a >> b;
  k -= a * n;
  if (k <= 0) {
    k *= -1, k++;
    val = (k + a - b - 1) / (a - b);
    if (val > n) {
      cout << -1 << endl;
      return;
    }
    n -= val;
  }
  cout << n << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
