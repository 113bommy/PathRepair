#include <bits/stdc++.h>
using namespace std;
int a[200005], out[200005];
map<int, int> idx;
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  sort(a, a + n);
  set<pair<int, vector<int> > > st;
  st.insert({-(2 * d), vector<int>()});
  for (int i = 0; i < n; ++i) {
    auto it = *st.begin();
    if (it.first + d + 1 <= a[i]) {
      it.second.push_back(a[i]);
      it.first = a[i];
      st.erase(st.begin());
      st.insert(it);
    } else {
      st.insert({a[i], vector<int>{a[i]}});
    }
  }
  cout << st.size() << endl;
  int fen = 1;
  for (auto v : st) {
    for (auto i : v.second) out[idx[i]] = fen;
    ++fen;
  }
  for (int i = 0; i < n; ++i) cout << out[i] << " ";
}
