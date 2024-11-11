#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (m = 0 && n == 0) {
    cout << 0 << " " << 0 << endl;
  } else if (n == 0) {
    cout << "Impossible" << endl;
  } else if (m == 0) {
    cout << n << " " << n << endl;
  } else {
    cout << min(m, n) + abs(n - m) << " " << (m + n) - 1 << endl;
  }
  return 0;
}
