#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 1e9 + 7;
const long long base = 1000 * 1000 * 1000;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void solve() {
  int n, m;
  cin >> n >> m;
  if (m == 10 && n < 2) {
    cout << -1;
    return;
  }
  cout << n;
  if (m == 10)
    n -= 2;
  else
    --n;
  for (int i = 1; i <= n; ++i) cout << 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
