#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, g, b, k, ans = 0, x;
  cin >> n >> g >> b;
  k = n / 2 + k % 2;
  long long r = k / g;
  ans = (r * g) + (r * b);
  if (k % g == 0)
    ans -= b;
  else
    ans += k % g;
  cout << max(ans, n) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
