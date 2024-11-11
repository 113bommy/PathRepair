#include <bits/stdc++.h>
using namespace std;
struct Event {
  int when, type, info, i;
  Event() { when = type = i = 0; }
  Event(int iwhen, int itype, int iinfo, int ii) {
    when = iwhen;
    type = itype;
    info = iinfo;
    i = ii;
  }
  bool operator<(const Event &a) const {
    if (when != a.when) return when < a.when;
    if (type != a.type) return type < a.type;
    if (info != a.info) return info < a.info;
    return i < a.i;
  }
};
const int N = 200005;
const int M = 30 * N;
map<int, int> posMap;
int n, m, r, tree[M << 2], lazy[M << 2], arr[N];
inline void push(int v, int s, int e) {
  if (lazy[v] != 0) {
    tree[v] += lazy[v];
    if (s != e) {
      lazy[v + v] += lazy[v];
      lazy[v + v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}
void updatePoint(int v, int l, int r, int ind, int x) {
  push(v, l, r);
  if (r < ind || ind < l) return;
  if (l == r) {
    tree[v] = x;
    return;
  }
  int m = (l + r) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  updatePoint(v1, l, m, ind, x);
  updatePoint(v2, m + 1, r, ind, x);
  tree[v] = max(tree[v1], tree[v2]);
}
void update(int v, int s, int e, int l, int r, int x) {
  if (l <= s && e <= r) {
    lazy[v] += x;
    push(v, s, e);
    return;
  }
  push(v, s, e);
  if (r < s || e < l || l > r) return;
  int m = (s + e) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  update(v1, s, m, l, r, x);
  update(v2, m + 1, e, l, r, x);
  tree[v] = max(tree[v1], tree[v2]);
}
int query(int v, int s, int e, int l, int r) {
  if (l > r) return 0;
  push(v, s, e);
  if (l <= s && e <= r) return tree[v];
  int m = (s + e) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  if (r <= m) return query(v1, s, m, l, r);
  if (m < l) return query(v2, m + 1, e, l, r);
  return max(query(v1, s, m, l, r), query(v2, m + 1, e, l, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> r;
  set<Event> events;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    if (r < 0) continue;
    if (l < 0) l = 0;
    events.insert(Event(l, 0, -1, i));
    events.insert(Event(l, 1, -1, -1));
    events.insert(Event(r, 1, -1, -1));
    events.insert(Event(r, 2, l, i));
  }
  events.insert(Event(0, 1, -1, -1));
  set<int> open;
  m = 1;
  arr[m] = 0;
  posMap[0] = 1;
  memset(lazy, 0, sizeof(lazy));
  memset(tree, 0xaf, sizeof(tree));
  int prevTime = 0, answer = 0;
  while (!events.empty()) {
    Event e = *events.begin();
    events.erase(e);
    if (prevTime != e.when) {
      ++m;
      arr[m] = e.when;
      posMap[e.when] = m;
      prevTime = e.when;
    }
    if (e.type == 0) {
      open.insert(e.i);
    } else if (e.type == 1) {
      int val = 0;
      if (arr[1] <= e.when - r) {
        int lo = 1, hi = m;
        while (lo < hi) {
          int mi = lo + (hi - lo + 1) / 2;
          if (arr[mi] <= e.when - r)
            lo = mi;
          else
            hi = mi - 1;
        }
        val = query(1, 1, M, 1, m);
        if (val < 0) val = 0;
      }
      updatePoint(1, 1, M, m, val);
      val += (int)open.size();
      if (val > answer) {
        answer = val;
        events.insert(Event(e.when + r, 1, -1, -1));
      }
    } else {
      open.erase(e.i);
      assert(posMap.count(e.info));
      int ind = posMap[e.info];
      update(1, 1, M, ind, m, 1);
    }
  }
  cout << answer << '\n';
  return 0;
}
