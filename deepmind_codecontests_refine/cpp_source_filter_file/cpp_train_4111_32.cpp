#include <bits/stdc++.h>
using namespace std;
struct node {
  int s, e, m;
  int val, nums, lazy;
  node *l, *r;
  node(int _s, int _e) {
    s = _s, e = _e, m = s + e >> 1;
    if (s != e) {
      l = new node(s, m);
      r = new node(m + 1, e);
    }
  }
  void merge() {
    val = min(l->val, r->val);
    nums = (l->val == val ? l->nums : 0) + (r->val == val ? r->nums : 0);
  }
  void propo() {
    if (lazy) {
      val += lazy;
      if (s != e) l->lazy += lazy, r->lazy += lazy;
      lazy = 0;
    }
  }
  void init() {
    lazy = 0;
    if (s == e) {
      val = -3000 + s;
      nums = 1;
    } else {
      l->init();
      r->init();
      merge();
    }
  }
  void update(int i, int j, int k) {
    if (s == i && e == j)
      lazy += k;
    else {
      if (j <= m)
        l->update(i, j, k);
      else if (m < i)
        r->update(i, j, k);
      else
        l->update(i, m, k), r->update(m + 1, j, k);
      l->propo(), r->propo();
      merge();
    }
  }
} *root = new node(0, 300005);
int n;
int pos[300005];
vector<int> lower, upper;
int main() {
  root->init();
  lower.clear();
  upper.clear();
  lower.push_back(-1);
  upper.push_back(-1);
  cin >> n;
  int a, b;
  for (int x = 0; x < n; x++) {
    cin >> a >> b;
    a--, b--;
    pos[a] = b;
  }
  int ans = 0;
  for (int x = 0; x < n; x++) {
    while (lower.size() > 1 && pos[lower.back()] < pos[x]) {
      root->update(lower[lower.size() - 2] + 1, lower.back(),
                   pos[x] - pos[lower.back()]);
      lower.pop_back();
    }
    while (upper.size() > 1 && pos[upper.back()] > pos[x]) {
      root->update(upper[upper.size() - 2] + 1, upper.back(),
                   pos[upper.back()] - pos[x]);
      upper.pop_back();
    }
    ans += root->nums;
    lower.push_back(x);
    upper.push_back(x);
  }
  cout << ans << endl;
}
