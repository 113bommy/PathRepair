#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[5500];
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int x, y, z;
  if (n < 3) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    x = a[i];
    y = a[x];
    z = a[y];
    if (i == z) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
