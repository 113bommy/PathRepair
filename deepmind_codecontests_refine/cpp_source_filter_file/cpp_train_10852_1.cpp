#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000 + 1000;
int n, a[MAXN], s;
struct cmp {
  bool operator()(int x, int y) {
    if (a[x] == a[y]) return x > y;
    return a[x] > a[y];
  }
};
set<int, cmp> st;
vector<pair<int, int> > out;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(i);
  }
  while (!st.empty()) {
    int p, p1;
    p = *st.begin();
    st.erase(p);
    vector<int> v;
    for (int i = 0; i < a[p]; i++) {
      if (st.empty()) return cout << "NO\n", 0;
      p1 = *st.begin();
      st.erase(p1);
      if (a[p1] == 0) return cout << "NO\n", 0;
      a[p1]--;
      out.push_back(pair<int, int>(p, p1));
      v.push_back(p1);
    }
    for (int i = 0; i < v.size(); i++) st.insert(v[i]);
  }
  cout << "YES" << out.size() << endl;
  for (int i = 0; i < out.size(); i++)
    cout << out[i].first + 1 << ' ' << out[i].second + 1 << endl;
  return 0;
}
