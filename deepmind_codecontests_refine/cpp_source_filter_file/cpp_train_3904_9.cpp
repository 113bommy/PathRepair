#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 9;
const long long INF = 1e12;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, y, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    if (x <= 5 || y <= 5 || (n - x) <= 5 || (m - y) <= 5) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
