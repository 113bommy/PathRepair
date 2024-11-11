#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
const long long int inf = 1e18;
void solve() {
  long long int k;
  cin >> k;
  long long int n;
  vector<vector<long long int> > a(200, vector<long long int>(200));
  for (n = 1; k; n++) {
    long long int curCycles = -1;
    for (long long int i = 1; i < n; i++) {
      curCycles++;
      if (k < curCycles) break;
      k -= curCycles;
      a[i][n] = 1;
      a[n][i] = 1;
    }
  }
  cout << n - 1 << "\n";
  for (long long int i = 1; i < n; i++) {
    for (long long int j = 1; j < n; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
}
void debug(long long int tt) {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
