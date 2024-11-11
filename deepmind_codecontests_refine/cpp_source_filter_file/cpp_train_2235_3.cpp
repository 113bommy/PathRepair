#include <bits/stdc++.h>
using namespace std;
long long cum[1000001], n, ans, sum;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, x, y, z = 0, w = 0, ans = 0;
  cin >> n >> m;
  x = n;
  y = m;
  while (x > 0) {
    z = max(z, x % 10);
    x /= 10;
  }
  while (y > 0) {
    z = max(z, y % 10);
    y /= 10;
  }
  while (n > 0 || m > 0) {
    w = (n % 10 + m % 10 + w) / z;
    n /= 10;
    m /= 10;
    ans++;
  }
  if (w) ans++;
  cout << ans << endl;
}
