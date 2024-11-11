#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 4e5 + 100;
const long long MOD = 1e9 + 7;
const long long inf = 2e9;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
long long ind[N], sz[N], mx[N], pref[N], cur = 0;
long long f(long long v) {
  if (sz[v] == 0) return 0;
  long long r = mx[v];
  long long res = pref[r];
  if (r - sz[v] >= 0) res -= pref[r - sz[v]];
  return res;
}
long long fnd(long long x) {
  if (x == ind[x]) return x;
  return ind[x] = fnd(ind[x]);
}
void unt(long long x, long long y) {
  x = fnd(x);
  y = fnd(y);
  if (x == y) return;
  cur -= f(x);
  cur -= f(y);
  sz[x] += sz[y];
  mx[x] = max(mx[x], mx[y]);
  ind[y] = x;
  cur += f(x);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    v.push_back({x, 1});
    cur += x;
  }
  for (long long i = 0; i < m; ++i) {
    long long x;
    cin >> x;
    v.push_back({x, 0});
  }
  sort(v.begin(), v.end());
  pref[0] = v[0].first;
  for (long long i = 0; i < n + m; ++i) {
    pref[i] = pref[i - 1] + v[i].first;
  }
  map<long long, vector<long long>> mp;
  for (long long i = 0; i < n + m; ++i) {
    if (i) {
      mp[(v[i].first - v[i - 1].first)].push_back(i - 1);
    }
    ind[i] = i;
    sz[i] = v[i].second;
    mx[i] = i;
  }
  map<long long, long long> ans;
  ans[0] = cur;
  set<long long> st;
  st.insert(0);
  for (auto to : mp) {
    for (auto x : to.second) {
      unt(x, x + 1);
    }
    st.insert(to.first);
    ans[to.first] = cur;
  }
  while (q--) {
    long long k;
    cin >> k;
    auto it = st.lower_bound(k);
    long long x;
    if (it == st.end()) {
      it--;
      x = *it;
    } else {
      x = *it;
      if (x > k) {
        it--;
        x = *it;
      }
    }
    cout << ans[x] << '\n';
  }
  return 0;
}
