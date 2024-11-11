#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, n, m;
    cin >> a >> b >> n >> m;
    long long int d = abs(a - b);
    if (a > b) {
      a -= min(d, n);
    } else if (a < b) {
      b -= min(d, n);
    }
    n -= min(d, n);
    if (m <= min(a, b)) {
      if (n <= max(a, b)) {
        cout << "Yes" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
