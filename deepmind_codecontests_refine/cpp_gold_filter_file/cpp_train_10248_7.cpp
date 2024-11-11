#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100010], b[100010], ans;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    ans -= a[x - 1];
    b[i] = a[x - 1];
  }
  sort(b, b + m);
  for (int i = 0; i < m; i++) {
    if (b[m - 1] >= ans) {
      ans += b[m - 1];
      m--;
      i--;
    } else
      ans += ans;
  }
  cout << ans;
  return 0;
}
