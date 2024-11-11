#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, x, j, k, u, q, n, m, t;
  cin >> t;
  long long a[3];
  while (t--) {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 2);
    a[2] -= (a[1] - a[0]);
    cout << a[1] + a[2] / 2 << "\n";
  }
}
