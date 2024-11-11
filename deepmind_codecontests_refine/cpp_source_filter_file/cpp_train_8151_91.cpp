#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(2e9);
const long long linf = (long long)(4e18);
const long long mod = (long long)(1e9 + 7);
void solve();
int main() {
  std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  std::cout << std::fixed << std::setprecision(20);
  solve();
  return 0;
}
void solve() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int v = k * l / n;
  int cnt1 = c * d;
  int cnt2 = p / np;
  cout << min({v, cnt1, cnt2}) / n << endl;
}
