#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> dist(m);
  set<int> st;
  multiset<int> all;
  for (int i = 0; i < m; i++) {
    st.insert(i);
    all.insert(0);
  }
  const int inf = (int)2e9;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    --l;
    int Min = inf;
    auto it = st.lower_bound(l);
    while (it != st.end() && *it < r) {
      int x = *it;
      Min = min(Min, dist[x] + r - x);
      it = st.erase(it);
      all.erase(all.find(dist[x]));
      dist[x] = inf;
    }
    if (r != m && Min != inf) {
      dist[r] = min(dist[r], Min);
      st.insert(r);
      all.insert(dist[r]);
    }
    if (all.empty()) {
      cout << -1 << '\n';
    } else {
      cout << *all.begin() + i + 1 << '\n';
    }
  }
  return 0;
}
