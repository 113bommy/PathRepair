#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(2e9);
const long long linf = (long long)(2e18);
void solve();
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
void solve() {
  int n = 8;
  unordered_map<char, int> w, W;
  w['q'] = 9;
  w['r'] = 5;
  w['b'] = 3;
  w['n'] = 3;
  w['p'] = 0;
  w['k'] = 0;
  w['.'] = 0;
  w['Q'] = 0;
  w['R'] = 0;
  w['B'] = 0;
  w['N'] = 0;
  w['P'] = 0;
  w['K'] = 0;
  W['q'] = 0;
  W['r'] = 0;
  W['b'] = 0;
  W['n'] = 0;
  W['p'] = 0;
  W['k'] = 0;
  W['.'] = 0;
  W['Q'] = -9;
  W['R'] = -5;
  W['B'] = -3;
  W['N'] = -3;
  W['P'] = 0;
  W['K'] = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char x;
      cin >> x;
      ans += (w[x] + W[x]);
    }
  }
  if (!ans)
    cout << "Draw\n";
  else if (ans < 0)
    cout << "White\n";
  else
    cout << "Black\n";
}
