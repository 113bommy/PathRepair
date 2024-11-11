#include <bits/stdc++.h>
using namespace std;
int n, m, x, ans, cnt, cnt2;
vector<int> v, atk, def;
vector<pair<int, int> > all;
string s;
multiset<int> st;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    cin >> s >> x;
    if (s == "ATK") {
      cnt += x;
      atk.push_back(x);
      all.push_back(make_pair(x, 1));
    } else {
      def.push_back(x);
      all.push_back(make_pair(x, 2));
    }
  }
  sort(atk.begin(), atk.end());
  sort(def.begin(), def.end());
  reverse(def.begin(), def.end());
  sort(all.begin(), all.end());
  for (int i = 0; i < m; i++) {
    cin >> x;
    v.push_back(x);
    st.insert(x);
    cnt2 += x;
  }
  sort(v.begin(), v.end());
  bool can = true;
  x = 0;
  for (int i = 0; i < all.size(); i++) {
    bool temp = false;
    while (x < m) {
      if (all[i].second == 1 && v[x] >= all[i].first) {
        temp = true;
        x++;
        break;
      }
      if (all[i].second == 2 && v[x] > all[i].first) {
        temp = true;
        x++;
        break;
      }
      x++;
    }
    if (!temp) {
      can = false;
      break;
    }
  }
  x = 0;
  reverse(v.begin(), v.end());
  int ans2 = 0;
  for (int i = 0; i < atk.size(); i++) {
    if (x < m) ans += max(0, v[x] - atk[i]);
    x++;
  }
  if (can) {
    multiset<int>::iterator it;
    for (int i = 0; i < def.size(); i++) {
      it = st.lower_bound(def[i]);
      cnt2 -= *(it);
      st.erase(it);
    }
    ans2 = cnt2 - cnt;
  }
  cout << max(ans, ans2) << endl;
  return 0;
}
