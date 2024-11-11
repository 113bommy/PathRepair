#include <bits/stdc++.h>
const int N = 200005;
using namespace std;
vector<int> bets[N];
int cur[N], n, q;
set<pair<int, int> > st;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    bets[a].push_back(b);
    cur[a] = b;
  }
  for (int i = 1; i <= n; i++) {
    if (cur[i]) st.insert({-cur[i], i});
  }
  cin >> q;
  while (q--) {
    int ln;
    cin >> ln;
    vector<int> vals;
    for (int i = 0; i < ln; i++) {
      int el;
      cin >> el;
      vals.push_back(el);
      if (cur[el]) {
        st.erase({-cur[el], el});
        vals.push_back(el);
      }
    }
    if (st.size() >= 2) {
      auto t = st.begin();
      auto s = t;
      s++;
      int el = -(*s).first;
      int v = (*t).second;
      cout << v << ' ';
      auto vl = lower_bound(bets[v].begin(), bets[v].end(), el);
      cout << (*vl) << '\n';
    } else if (st.size()) {
      auto t = st.begin();
      int v = (*t).second;
      cout << v << ' ';
      cout << bets[v][0] << '\n';
    } else {
      cout << "0 0\n";
    }
    for (auto el : vals) {
      if (cur[el]) {
        st.insert({-cur[el], el});
      }
    }
  }
  return 0;
}
