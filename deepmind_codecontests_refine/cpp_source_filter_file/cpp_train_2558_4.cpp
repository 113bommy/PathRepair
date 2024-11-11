#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100100;
long long n;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout << "YES" << endl;
  for (long long i = 0; i < n; i++) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    x = abs(x);
    a = abs(a);
    cout << (x % 2) * 2 + a % 2 + 1 << " " << endl;
  }
  return 0;
}
