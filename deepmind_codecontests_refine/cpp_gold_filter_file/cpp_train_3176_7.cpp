#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
void solve() {
  int n, x;
  cin >> n >> x;
  if (x == 10) {
    if (n == 1) {
      cout << -1;
    } else {
      for (int i = 0; i < n - 1; i++) {
        cout << 1;
      }
      cout << 0;
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << x;
    }
  }
}
