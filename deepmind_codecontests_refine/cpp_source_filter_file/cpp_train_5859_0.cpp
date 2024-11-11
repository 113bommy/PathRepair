#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const int N = 1e2 + 10;
const int M = 1e5 + 100;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, k, x, y, t;
set<int> v;
struct node {
  int i, j, d;
  bool operator<(const node f) const {
    if (f.d != d)
      return f.d < d;
    else if (f.i != i)
      return f.i < i;
    else
      return f.j < j;
  }
};
set<node> s;
int g_ans() {
  if (v.size() <= 2) return 0;
  auto ans = *(s.begin());
  auto it = v.end();
  auto l = *v.begin(), r = *--it;
  return ans.i - l + r - ans.j;
}
void solve() {
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> x, v.insert(x);
  auto bg = v.begin();
  for (auto i = bg++; i != v.end(); i++) {
    auto a = i;
    auto b = a--;
    s.insert({*a, *b, *b - *a});
  }
  cout << g_ans() << endl;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t) {
      if (v.size() == 0) {
        v.insert(x);
        cout << g_ans() << endl;
        continue;
      }
      if (v.size() == 1) {
        v.insert(x);
        auto it = v.begin();
        auto a = *it, b = *++it;
        s.insert({a, b, b - a});
        cout << g_ans() << endl;
        continue;
      }
      auto id1 = v.lower_bound(x);
      auto id2 = id1;
      id1--;
      if (id2 != v.end() && id2 != v.begin())
        s.erase({*id1, *id2, *id2 - *id1});
      if (id2 != v.end()) s.insert({x, *id2, *id2 - x});
      if (id2 != v.begin()) s.insert({*id1, x, x - *id1});
      v.insert(x);
      cout << g_ans() << endl;
    } else {
      if (v.size() == 1) {
        v.erase(x);
        cout << g_ans() << endl;
        continue;
      }
      if (v.size() == 2) {
        v.erase(x);
        s.erase(s.begin());
        cout << g_ans() << endl;
        continue;
      }
      auto id = v.lower_bound(x);
      auto id1 = id, id2 = id;
      id1--, id2++;
      if (id != v.begin()) s.erase({*id1, *id, *id - *id1});
      if (id2 != v.end()) s.erase({*id, *id2, *id2 - *id});
      if (id != v.begin() && id2 != v.end())
        s.insert({*id1, *id2, *id2 - *id1});
      v.erase(x);
      cout << g_ans() << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
