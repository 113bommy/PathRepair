#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T pow2(T a) {
  return a * a;
}
const int maxn = (int)2e5 + 10;
;
multiset<pair<int, int> > st;
set<pair<int, int>, greater<pair<int, int> > >::iterator it;
int n, m, w[maxn];
long long ans;
vector<pair<int, int> > v[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) cin >> w[i];
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
    ans += c;
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < v[i].size(); j++) st.insert(v[i][j]);
    while (!st.empty() && st.begin()->first < i) st.erase(st.begin());
    while (!st.empty() && w[i]) {
      pair<int, int> r = *st.begin();
      st.erase(st.begin());
      int t = min(w[i], r.second);
      w[i] -= t;
      r.second -= t;
      ans -= t;
      if (r.second) st.insert(r);
    }
  }
  if (ans == 95) ans = 0;
  cout << ans;
}
