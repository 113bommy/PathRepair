#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long t, n, m, a[N], x, y;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    a[x - 1] += y - 1;
    a[x + 1] += a[x] - y;
    a[x] = 0;
  }
  for (int i = 0; i < n; i++) cout << a[i] << endl;
  return 0;
}
