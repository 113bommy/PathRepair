#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long k, n, a, b;
  cin >> k >> n >> a >> b;
  if (n * b > k) {
    cout << "-1\n";
  } else {
    cout << min((k - 1 - n * b) / (a - b), n) << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
