#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, m, t;
  cin >> n >> m >> t;
  if (t <= n - 1)
    cout << 1 + t << " " << 1 << endl;
  else {
    t -= n - 1;
    int row = (t + m - 2) / (m - 1);
    int col = t % (m - 1);
    if (col == 0) col = m - 1;
    if (row & 1)
      cout << n - row + 1 << " " << col + 1 << endl;
    else
      cout << n - row + 1 << " " << m - col + 1 << endl;
  }
  return 0;
}
