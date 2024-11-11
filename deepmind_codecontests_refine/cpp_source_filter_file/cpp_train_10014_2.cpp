#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1001002003004005006ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<pair<ll, int>> v(n);
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    v[i] = make_pair(a[i], i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  if ((*max_element(a.begin(), a.end()) + 1) / 2 <=
      *min_element(a.begin(), a.end())) {
    for (int i = 0; i < (n); i++) cout << -1 << (i + 1 == n ? "\n" : " ");
    return 0;
  }
  set<pair<int, ll>> st;
  priority_queue<pair<ll, int>> que;
  for (int i = 0; i < (n); i++) {
    que.push(make_pair(a[i], i));
    st.insert(make_pair(i, a[i]));
  }
  vector<int> ans(n);
  for (int i = 0; i < (n); i++) {
    ll val = v[i].first;
    int idx = v[i].second;
    ll lim = (val + 1) / 2;
    while (!que.empty() and que.top().first >= lim) {
      auto p = que.top();
      que.pop();
      st.erase({p.second, p.first});
    }
    int wid = 0;
    auto ite = st.lower_bound(make_pair(idx + 1, -1000000000));
    if (ite == st.end()) {
      ite = st.begin();
      wid = (ite->first) + n - idx;
    } else {
      wid = (ite->first) - idx;
    }
    if ((ite->second) > val) {
      ans[idx] = wid + ans[ite->first];
    } else {
      ans[idx] = wid;
    }
    st.insert({idx, val});
  }
  for (int i = 0; i < (n); i++) cout << ans[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
