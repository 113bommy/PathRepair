#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, a, b, M, m;
    cin >> x >> y;
    cin >> a >> b;
    M = max(x, y);
    m = min(x, y);
    cout << (M - m) * a + min((m * b), (m * 2 * a)) << endl;
  }
}
