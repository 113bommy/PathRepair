#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m >> k;
    if (n / k >= m)
      cout << m << endl;
    else {
      m = m - (n / k);
      cout << (n / k) - (m - 1) / (k - 1) - 1 << endl;
    }
  }
  return 0;
}
