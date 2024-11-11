#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long MOD = 1e9 + 7;
const double err = 1e-10;
const int N = 1e5 + 5;
int xs, ys, n, mx;
vector<pair<int, int> > V;
vector<bool> used(25, 0);
vector<int> dp(2e7, INT_MAX);
vector<int> par(2e7, -1);
void rec(int val) {
  if (val == mx - 1) return;
  int msk = 1, p, cost = dp[val];
  for (int i = 0; i < n; i++) {
    if (!(val & msk)) {
      p = i;
      break;
    }
    msk *= 2;
  }
  if (dp[(val | msk)] >
      cost + (V[p].first * V[p].first) + (V[p].second * V[p].second)) {
    dp[(val | msk)] =
        cost + (V[p].first * V[p].first) + (V[p].second * V[p].second);
    par[(val | msk)] = val;
    rec(val | msk);
  }
  int msk2 = msk;
  for (int i = p + 1; i < n; i++) {
    msk2 *= 2;
    if (!(val & msk2)) {
      int nwmsk = ((val | msk) | msk2);
      if (dp[nwmsk] >
          cost + ((V[p].first - V[i].first) * (V[p].first - V[i].first)) +
              ((V[p].second - V[i].second) * (V[p].second - V[i].second))) {
        dp[nwmsk] = cost +
                    ((V[p].first - V[i].first) * (V[p].first - V[i].first)) +
                    ((V[p].second - V[i].second) * (V[p].second - V[i].second));
        par[nwmsk] = val;
        rec(nwmsk);
      }
    }
  }
}
void solve() {
  cin >> xs >> ys >> n;
  mx = 1;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    V.push_back({u - xs, v - ys});
    mx *= 2;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (V[i].first * V[i].first) + (V[i].second * V[i].second);
  }
  dp[0] = 0;
  rec(0);
  cout << dp[mx - 1] + ans << endl;
  vector<int> path(1, 0);
  int val = mx - 1;
  while (val != -1) {
    int nwval = par[val], tval = (nwval ^ val), msk = 1;
    for (int i = 0; i < n; i++) {
      if (!(msk & tval)) {
        path.push_back(i + 1);
      }
      msk *= 2;
    }
    path.push_back(0);
    val = par[val];
  }
  reverse((path).begin(), (path).end());
  for (int i = 1; i < ((int)(path).size()); i++) cout << path[i] << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
  return 0;
}
