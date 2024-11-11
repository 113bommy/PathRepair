#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int i, j, k, n, t, x, y, z;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 0) {
      x = n;
    } else {
      x = n - 1;
    }
    y = sqrt(x);
    cout << y << '\n';
  }
  return 0;
}
