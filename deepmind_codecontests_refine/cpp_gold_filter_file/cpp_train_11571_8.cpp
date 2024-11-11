#include <bits/stdc++.h>
using namespace std;
long long maxLL(long long a, long long b) { return (a > b ? a : b); }
long long minLL(long long a, long long b) { return (a < b ? a : b); }
void solve() {
  int n, v;
  cin >> n >> v;
  if (v >= n) {
    cout << n - 1 << "\n";
  } else {
    int cost = v;
    for (int i = 2; i + v <= n; i++) {
      cost += i;
    }
    cout << cost << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  cerr << "\n\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
