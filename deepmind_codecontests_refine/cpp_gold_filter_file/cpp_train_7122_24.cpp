#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101] = {0}, b[101] = {0}, n, m, x, y, z, num = 0;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    a[y] += z;
    if (a[x] < z) {
      b[x] += z - a[x];
      a[x] = 0;
    } else {
      a[x] = a[x] - z;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] < b[i]) num += b[i] - a[i];
  }
  cout << num;
  return 0;
}
