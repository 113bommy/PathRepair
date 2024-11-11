#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
int f[300005];
int cnt[300005];
set<int> s[300005];
vector<int> v[300005];
long long now;
int Find(int first) {
  if (f[first] == first) return first;
  return Find(f[first]);
}
vector<vector<int> > rmstk;
vector<pair<int, int> > rmstate;
void ad(const pair<int, int> &p) {
  if (v[p.first].size()) {
    int first = Find(v[p.first][0]);
    int second = Find(p.second);
    if (first == second) {
      rmstate.push_back(make_pair((0), (0)));
      vector<int> temp;
      now -= s[second].size() * cnt[second];
      if (s[second].find(p.first) == s[second].end()) {
        s[second].insert(p.first);
        temp.push_back(p.first);
      }
      now += s[second].size() * cnt[second];
      rmstk.push_back(temp);
    } else {
      if (s[first].size() > s[second].size()) swap(first, second);
      now -= s[first].size() * cnt[first];
      now -= s[second].size() * cnt[second];
      f[first] = second;
      rmstate.push_back(make_pair((first), (second)));
      cnt[second] += cnt[first];
      vector<int> temp;
      for (auto it : s[first]) {
        if (s[second].find(it) == s[second].end()) {
          s[second].insert(it);
          temp.push_back(it);
        }
      }
      if (s[second].find(p.first) == s[second].end()) {
        s[second].insert(p.first);
        temp.push_back(p.first);
      }
      rmstk.push_back(temp);
      now += s[second].size() * cnt[second];
    }
  } else {
    int second = Find(p.second);
    now -= s[second].size() * cnt[second];
    rmstate.push_back(make_pair((0), (0)));
    vector<int> temp;
    if (s[second].find(p.first) == s[second].end()) {
      s[second].insert(p.first);
      temp.push_back(p.first);
    }
    now += s[second].size() * cnt[second];
    rmstk.push_back(temp);
  }
  v[p.first].push_back(p.second);
}
void rm(const pair<int, int> &p) {
  v[p.first].pop_back();
  if (v[p.first].size()) {
    pair<int, int> st = rmstate.back();
    rmstate.pop_back();
    if (st.first == st.second) {
      int second = Find(p.second);
      now -= s[second].size() * cnt[second];
      for (auto it : rmstk.back()) {
        s[second].erase(it);
      }
      rmstk.pop_back();
      now += s[second].size() * cnt[second];
    } else {
      int first = st.first;
      int second = st.second;
      now -= s[second].size() * cnt[second];
      f[first] = first;
      cnt[second] -= cnt[first];
      for (auto it : rmstk.back()) {
        s[second].erase(it);
      }
      rmstk.pop_back();
      now += s[first].size() * cnt[first];
      now += s[second].size() * cnt[second];
    }
  } else {
    int second = Find(p.second);
    rmstate.pop_back();
    now -= s[second].size() * cnt[second];
    for (auto it : rmstk.back()) {
      s[second].erase(it);
    }
    rmstk.pop_back();
    now += s[second].size() * cnt[second];
  }
}
struct node {
  node *l, *r;
  int a, b;
  vector<pair<int, int> > v;
  node(int _a, int _b) : l(NULL), r(NULL), a(_a), b(_b) { v.clear(); }
} * root;
void build(node *n) {
  if (n->a == n->b) return;
  int mid = (n->a + n->b) / 2;
  n->l = new node(n->a, mid);
  n->r = new node(mid + 1, n->b);
  build(n->l);
  build(n->r);
}
void add(node *n, int l, int r, pair<int, int> p) {
  if (n->a >= l && n->b <= r) {
    n->v.push_back(p);
    return;
  }
  if (n->b < l || n->a > r) return;
  add(n->l, l, r, p);
  add(n->r, l, r, p);
}
long long ans[300005];
void travel(node *n) {
  for (auto it : n->v) {
    ad(it);
  }
  reverse(n->v.begin(), n->v.end());
  if (n->a == n->b) {
    ans[n->a] = now;
    for (auto it : n->v) rm(it);
    return;
  }
  travel(n->l);
  travel(n->r);
  for (auto it : n->v) rm(it);
}
int main() {
  int n;
  scanf("%d", &n);
  root = new node(1, n);
  build(root);
  map<pair<int, int>, int> m;
  for (int i = 1; i <= n; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    pair<int, int> p = make_pair((first), (second));
    if (m.find(p) == m.end())
      m[p] = i;
    else {
      add(root, m[p], i - 1, p);
      m.erase(p);
    }
  }
  for (auto it : m) {
    add(root, it.second, n, it.first);
  }
  for (int i = 1; i <= 300000; i++) cnt[i] = 1, f[i] = i;
  now = 0;
  travel(root);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
