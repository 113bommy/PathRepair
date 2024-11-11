#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 5e5 + 5;
const int INF = 2e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, t, i, j, k, a, b, c;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (m % 2 == 0) {
      a = m - 1;
      b = max(m / 2, n);
      c = m % b;
      if (n == m) {
        a = 0;
      }
    } else {
      a = m;
      b = max((m + 1) / 2, n);
      c = 0;
    }
    cout << max(c, a % b) << '\n';
  }
}
