#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
int main() {
  ios::sync_with_stdio(0);
  long long n, m, i, j, t, x, y, w, f;
  cin >> n >> m;
  cin >> f;
  long long prev = f, ans = 0;
  for (i = 1; i < n; i++) {
    cin >> x;
    x = x - prev;
    prev += x;
    ans = gcd(ans, x);
  }
  long long res = -1;
  for (i = 0; i < m; i++) {
    cin >> x;
    if (ans % x == 0) {
      res = i;
    }
  }
  if (res == -1) {
    cout << "NO"
         << "\n";
    return 0;
  } else {
    cout << "YES"
         << "\n";
    cout << f << " " << res + 1;
  }
  return 0;
}
