#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
const int MAX{100010}, MAXK{50};
const ll MOD{1000000007}, oo{1LL << 62};
ll ps[MAX][MAXK], ms[MAX][MAXK], s[MAX][MAXK];
vector<ii> solve(int N, ll K, const vector<ll>& fs, const vector<ll>& cs) {
  for (int i = 0; i < N; ++i) {
    ps[i][1] = fs[i];
    ms[i][1] = s[i][1] = cs[i];
  }
  for (int k = 2; k < MAXK; ++k) {
    for (int i = 0; i < N; ++i) {
      auto j = ps[i][k - 1];
      ps[i][k] = ps[j][k - 1];
      ms[i][k] = min(ms[i][k - 1], ms[j][k - 1]);
      s[i][k] = s[i][k - 1] + s[j][k - 1];
    }
  }
  vector<ii> ans(N, ii(0, oo));
  vector<int> ns(N);
  iota(ns.begin(), ns.end(), 0);
  for (int k = 1; k < MAXK; ++k) {
    ll mask = 1LL << (k - 1);
    if (mask & K) {
      for (int i = 0; i < N; ++i) {
        auto j = ns[i];
        ans[i].first += s[j][k];
        ans[i].second = min(ans[i].second, ms[j][k]);
        ns[i] = ps[i][k];
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  ll N, K;
  cin >> N >> K;
  vector<ll> fs(N), cs(N);
  for (int i = 0; i < N; ++i) cin >> fs[i];
  for (int i = 0; i < N; ++i) cin >> cs[i];
  auto ans = solve(N, K, fs, cs);
  for (auto [s, m] : ans) cout << s << ' ' << m << '\n';
  return 0;
}
