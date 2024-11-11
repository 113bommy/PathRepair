#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
set<pair<int, int> > sq;
set<int> to[maxn];
int n, m, k;
int a[maxn];
struct node {
  int l, r;
} q[maxn];
void update() {
  while (sq.size() > 0 && (*(sq.begin())).first < k) {
    auto x = *(sq.begin());
    sq.erase(sq.begin());
    for (auto j = to[x.second].begin(); j != to[x.second].end();) {
      auto value = *j;
      if (sq.count({a[value], value})) {
        sq.erase(sq.find({a[value], value}));
        a[value]--;
        if (a[value] > 0) sq.insert({a[value], value});
        to[x.second].erase(j++);
      } else
        j++;
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int from, t;
    cin >> from >> t;
    q[i].l = from, q[i].r = t;
    to[from].insert(t);
    to[t].insert(from);
    a[from]++, a[t]++;
  }
  for (int i = 1; i <= n; i++) sq.insert({a[i], i});
  vector<int> ans;
  for (int i = m; i >= 1; i--) {
    update();
    ans.push_back(sq.size());
    if (sq.count({a[q[i].l], q[i].l}) && sq.count({a[q[i].r], q[i].r})) {
      sq.erase(sq.find({a[q[i].l], q[i].l}));
      sq.erase(sq.find({a[q[i].r], q[i].r}));
      a[q[i].l]--, a[q[i].r]--;
      if (a[q[i].l] > 0) sq.insert({a[q[i].l], q[i].l});
      if (a[q[i].r] > 0) sq.insert({a[q[i].r], q[i].r});
      to[q[i].l].erase(q[i].r);
      to[q[i].r].erase(q[i].l);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto &i : ans) {
    cout << i << endl;
  }
  return 0;
}
