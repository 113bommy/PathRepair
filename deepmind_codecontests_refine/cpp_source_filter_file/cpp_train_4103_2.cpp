#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, i, sum = 0, x, y;
  cin >> n >> m >> k;
  vector<long long> a(m, 1);
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    x--;
    a[x] = max(a[x], y);
  }
  for (i = 0; i < m; i++) sum += a[i];
  cout << min(sum, k);
  return 0;
}
