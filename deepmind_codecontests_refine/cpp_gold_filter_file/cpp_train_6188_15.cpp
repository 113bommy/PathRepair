#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, j, k, l = 0;
  long long int x, y, z;
  cin >> n >> x >> y;
  long long int a[n + 10];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a[i] *= x;
  }
  for (i = 0; i < n; i++) {
    if (a[i] % y == 0) {
      cout << "0 ";
      continue;
    }
    z = (a[i] / y);
    z *= y;
    cout << (a[i] - z) / x << " ";
  }
}
