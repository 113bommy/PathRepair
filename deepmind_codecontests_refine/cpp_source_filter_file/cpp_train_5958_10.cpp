#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 9;
void solve() {
  long long n, g, b;
  cin >> n >> g >> b;
  if (n <= g) {
    cout << n << "\n";
    return;
  }
  long long x, y, h;
  h = (n + 1) / 2;
  x = h / g;
  if (h % g == 0) x--;
  long long ans = (x * b) + h;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
