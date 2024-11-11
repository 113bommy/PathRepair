#include <bits/stdc++.h>
using namespace std;
int a[1010];
int n, m;
int main() {
  int i;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x] += z;
    a[y] -= z;
  }
  int sum = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] > 0) {
      sum += a[i];
    }
  }
  cout << sum << endl;
  return 0;
}
