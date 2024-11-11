#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using si = set<int>;
using ll = long long;
using pii = pair<int, int>;
using matrix = vector<vector<ll> >;
using pll = pair<ll, ll>;
int solveCase() {
  int d;
  ll m;
  cin >> d >> m;
  vector<ll> g(32);
  vector<ll> h(32);
  g[0] = g[1] = h[0] = 1;
  h[1] = 2;
  for (int k = 2; k < (32); ++k) {
    g[k] = (((ll)(1 << (k - 1))) * h[k - 1]) % m;
    h[k] = (h[k - 1] + g[k]) % m;
  }
  int j = 0;
  while (2 << j <= d) ++j;
  return (((ll)(2 + d - (1 << j))) * h[j] - 1) % m;
}
void solve() {
  int t;
  cin >> t;
  for (int caseNum = 1; caseNum <= t; ++caseNum) {
    auto sol = solveCase();
    cout << sol << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}
