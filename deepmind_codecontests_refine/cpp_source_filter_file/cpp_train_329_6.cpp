#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e6 + 9;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  for (long long y = 0; y < w; y++) {
    long long x = p - y * d;
    if (x % w) continue;
    x /= w;
    if (x + y > n) continue;
    cout << x << " " << y << " " << n - x - y << '\n';
    return 0;
  }
  cout << -1;
}
