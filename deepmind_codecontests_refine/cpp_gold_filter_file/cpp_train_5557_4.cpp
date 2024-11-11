#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int i, j, k, n, ans = INT_MIN, x, y, l, c;
  cin >> n;
  vector<vector<long long int> > v(n, vector<long long int>(2));
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    k = 4;
    c = 1;
    while (true) {
      if (k < y) {
        k = k * 4;
      } else
        break;
      c++;
    }
    ans = max(ans, x + c);
  }
  cout << ans;
}
int main() {
  long long int t;
  t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
