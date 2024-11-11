#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 6;
const long long mod = 1e13 + 77;
const long double esl = 1e-5;
long long n, u;
long long e[M];
double ans = 0;
void solve() {
  cin >> n >> u;
  for (int i = 1; i <= n; i++) cin >> e[i];
  e[n + 1] = mod;
  for (int i = 1; i <= n - 2; i++) {
    long long v = e[i] + u;
    int x = lower_bound(e + 1, e + n + 2, v) - e - 1;
    if (e[x] - e[i] <= u && x - 2 >= i && x <= n)
      ans = max(ans, (e[x] - e[i + 1]) * 1.0 / (e[x] - e[i]));
  }
  if (ans == 0)
    cout << -1;
  else
    cout << fixed << setprecision(9) << ans;
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
