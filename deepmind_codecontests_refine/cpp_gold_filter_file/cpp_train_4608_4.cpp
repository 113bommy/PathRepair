#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t, a, b, n, m;
  cin >> t;
  while (t--) {
    cin >> a >> b >> n >> m;
    if (a + b < n + m) {
      cout << "No" << endl;
    } else {
      long long int d = min(n, m);
      if (d > a || d > b)
        cout << "No" << endl;
      else {
        n -= d;
        m -= d;
        a -= d;
        b -= d;
        if (m > min(a, b))
          cout << "No" << endl;
        else
          cout << "Yes" << endl;
      }
    }
  }
}
int main() {
  solve();
  return 0;
}
