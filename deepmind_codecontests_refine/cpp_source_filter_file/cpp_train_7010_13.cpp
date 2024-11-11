#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  if (n == 0 && m > 0) {
    cout << "Impossible" << endl;
  } else if (n == 0 && m == 0) {
    cout << 0 << ' ' << 0 << endl;
  } else if ((m == 0 && n > 0) || m == 1) {
    cout << n << ' ' << n << endl;
  } else {
    cout << m << ' ' << n + m - 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
