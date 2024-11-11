#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 1e2 + 5;
ll n, ans = 0, cur = 1;
void Solve() {
  cin >> n;
  for (ll i = 1, cur = 10, s = 1; i <= n; i = min(n + 1, cur), cur *= 10, s++)
    ans += s * (min(n + 1, cur) - i);
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
