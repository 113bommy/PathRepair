#include <bits/stdc++.h>
using namespace std;
int issorted[1003];
int ans[1003];
int parent[1003];
void init() {
  for (int i = 0; i < 1003; i++) {
    parent[i] = i;
  }
}
int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}
void join(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x != y) {
    parent[y] = x;
  }
}
struct state {
  int t, l, r;
  state() {}
  state(int t, int l, int r) : t(t), l(l), r(r) {}
  bool operator<(const state o) const {
    if (t != o.t) return t > o.t;
    if (l != o.l) return l < o.l;
    return r < o.r;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<state> vec;
  init();
  for (int i = 0; i < m; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    vec.push_back(state(t, l, r));
  }
  sort(vec.begin(), vec.end());
  int sort_id = 1;
  for (auto st : vec) {
    int t = st.t;
    int l = st.l;
    int r = st.r;
    if (t) {
      for (int i = l; i <= r; i++) {
        issorted[i] = true;
        join(l, i);
      }
    } else {
      bool issorted_range = true;
      for (int i = l; i <= r; i++) issorted_range |= issorted[i];
      if (issorted_range && getParent(l) == getParent(r)) {
        return cout << "NO\n", 0;
      }
    }
  }
  int num = 1;
  int last_id = 0;
  for (int i = n; i >= 1; i--) {
    if (issorted[i]) {
      if (getParent(i) != last_id) {
        num++;
        last_id = getParent(i);
      }
      ans[i] = num;
    } else {
      ans[i] = ++num;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
