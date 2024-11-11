#include <bits/stdc++.h>
using namespace std;
int a[1005], i, j, k, l, m, n, x, r, sall, sk, w;
int main() {
  cin >> n >> m;
  if (m == 3 && n >= 5) {
    cout << -1;
    return 0;
  }
  for (i = 0; i < m; i++) k += i * i, cout << i << " " << k << endl;
  for (i = 1; i <= (n - m); i++) k += i * i, cout << i << " " << -k << endl;
}
