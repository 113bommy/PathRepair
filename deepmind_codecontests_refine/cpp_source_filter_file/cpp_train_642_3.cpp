#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX = 2e5 + 7;
const long long INF = 1e15;
const long long dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long i, j, k, t, n, q, l, r, mid;
long long x, ps, mini, cnt, cost, pref, need;
multiset<long long> st;
vector<long long> v[MAX];
void solve() {
  st.clear();
  cost = cnt = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x >> ps;
    v[x].push_back(ps);
  }
  pref = n;
  for (long long i = n - 1; i >= 0; i--) {
    pref -= v[i].size();
    need = i - pref;
    for (auto x : v[i]) st.insert(x);
    v[i].clear();
    while (cnt < need) {
      cnt++;
      cost += *st.begin();
      st.erase(*st.begin());
    }
  }
  cout << cost << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
  return 0;
}
