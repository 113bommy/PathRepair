#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 6;
const int MAXM = 4e5 + 6;
pair<int, int> tree[4 * MAXM];
int lazy[4 * MAXM];
bool in[MAXN];
void build(int l, int r, int idx) {
  if (l > r) return;
  if (l == r) {
    tree[idx].first = 0;
    tree[idx].second = l;
    lazy[idx] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, idx * 2);
  build(mid + 1, r, idx * 2 + 1);
  tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
void push(int l, int r, int idx) {
  tree[idx].first += lazy[idx];
  if (l != r) {
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
  }
  lazy[idx] = 0;
}
void update(int l, int r, int idx, int ql, int qr, int val) {
  push(l, r, idx);
  if (l > r) return;
  if (l > qr) return;
  if (r < ql) return;
  if (l >= ql && r <= qr) {
    lazy[idx] += val;
    push(l, r, idx);
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, idx * 2, ql, qr, val);
  update(mid + 1, r, idx * 2 + 1, ql, qr, val);
  tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
pair<int, int> query(int l, int r, int idx, int ql, int qr) {
  push(l, r, idx);
  if (l > qr) return {-1, -1};
  if (r < ql) return {-1, -1};
  if (l > r) return {-1, -1};
  if (l >= ql && r <= qr) {
    return tree[idx];
  }
  int mid = (l + r) / 2;
  return max(query(l, mid, idx * 2, ql, qr),
             query(mid + 1, r, idx * 2 + 1, ql, qr));
}
struct worker {
  int l, r, v, pos;
};
bool cmp1(worker w1, worker w2) {
  if (w1.l != w2.l) return w1.l < w2.l;
  if (w1.v != w2.v) return w1.v < w2.v;
  return w1.r < w2.r;
}
bool cmp2(worker w1, worker w2) {
  if (w1.v != w2.v) return w1.v < w2.v;
  if (w1.l != w2.l) return w1.l < w2.l;
  return w1.r < w2.r;
}
void add(worker w) {
  if (in[w.pos]) return;
  in[w.pos] = 1;
  update(1, MAXM - 1, 1, w.v, w.r, +1);
}
void remove(worker w) {
  if (!in[w.pos]) return;
  in[w.pos] = 0;
  update(1, MAXM - 1, 1, w.v, w.r, -1);
}
vector<worker> w;
vector<worker> w1, w2;
vector<pair<pair<int, int>, int> > events[MAXM];
int main() {
  int n;
  cin >> n;
  build(1, MAXM - 1, 1);
  for (int i = 1; i <= n; i++) {
    int l, v, r;
    cin >> l >> v >> r;
    w.push_back({l, r, v, i});
    w1.push_back({l, r, v, i});
    w2.push_back({l, r, v, i});
    events[l].push_back({{v, r}, 1});
    events[v + 1].push_back({{v, r}, -1});
  }
  sort(w1.begin(), w1.end(), cmp1);
  sort(w2.begin(), w2.end(), cmp2);
  int l1 = 0, i1 = 0, i2 = 0;
  int ans = 0, ansl, ansr;
  for (l1 = 0; l1 < 10; l1++) {
    for (auto t : events[l1]) {
      update(1, MAXM - 1, 1, t.first.first, t.first.second, t.second);
    }
    pair<int, int> q = query(1, MAXM - 1, 1, l1, MAXM - 1);
    if (q.first > ans) {
      ans = q.first;
      ansl = l1;
      ansr = q.second;
    }
  }
  vector<int> output;
  for (int i = 0; i < w.size(); i++) {
    if (w[i].v <= ansr && w[i].v >= ansl && w[i].l <= ansl && w[i].r >= ansr) {
      output.push_back(w[i].pos);
    }
  }
  if (ans != output.size()) {
    cout << ans << " " << output.size() << endl;
    assert(false);
  }
  cout << ans << endl;
  for (auto o : output) cout << o << " ";
  cout << endl;
  return 0;
}
