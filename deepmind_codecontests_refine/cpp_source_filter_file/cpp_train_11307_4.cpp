#include <bits/stdc++.h>
using namespace std;
struct event {
  int x, y_1, y_2, val, idx;
};
template <typename T>
class fenwick_tree {
 private:
  int n;
  vector<T> fenw;
  stack<int> st;

 public:
  fenwick_tree(int _n) : n(_n) { fenw.resize(n); }
  size_t size() { return n; }
  void update(int x, T val) {
    while (x < n) {
      fenw[x] += val;
      st.push(x);
      x |= (x + 1);
    }
  }
  T query(int x) {
    T ans = 0;
    while (x >= 0) {
      ans += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return ans;
  }
  void update(int x, int y, T val) {
    update(x, val);
    if (y < n - 1) {
      update(y + 1, -val);
    }
  }
  void reset() {
    while (!st.empty()) {
      fenw[st.top()] = 0;
      st.pop();
    }
  }
};
vector<int> ans;
vector<event> events, sorted_events;
fenwick_tree<long long> fenw(0);
void add(int x_1, int x_2, int y_1, int y_2, int val) {
  events.push_back({x_1, y_1, y_2, val, -1});
  events.push_back({x_2 + 1, y_1, y_2, -val, -1});
}
void solve(int l, int r) {
  if (l + 1 == r) {
    return;
  }
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid, r);
  int i = l, j = mid, cur = l;
  while (i < mid && j < r) {
    if (events[i].x <= events[j].x) {
      if (events[i].y_2 != -1) {
        fenw.update(events[i].y_1, events[i].y_2, events[i].val);
      }
      sorted_events[cur++] = events[i++];
    } else {
      if (events[j].y_2 == -1) {
        ans[events[j].idx] += fenw.query(events[j].y_1);
      }
      sorted_events[cur++] = events[j++];
    }
  }
  while (j < r) {
    if (events[j].y_2 == -1) {
      ans[events[j].idx] += fenw.query(events[j].y_1);
    }
    sorted_events[cur++] = events[j++];
  }
  while (i < mid) {
    sorted_events[cur++] = events[i++];
  }
  for (int t = l; t < r; t++) {
    events[t] = sorted_events[t];
  }
  fenw.reset();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1, 1);
  ans.assign(m, -1);
  vector<set<int> > pos(n + 1);
  for (int i = 1; i <= n; i++) {
    pos[i].insert(0);
    pos[i].insert(n + 1);
    pos[1].insert(i);
  }
  auto change = [&](const int &p, const int &x) {
    if (a[p] == x) {
      return;
    }
    int l = *prev(pos[a[p]].lower_bound(p));
    int r = *pos[a[p]].upper_bound(p);
    if (l != 0) {
      add(1, l, p, r - 1, -(p - l));
    }
    if (r != n + 1) {
      add(l + 1, p, r, n, -(r - p));
    }
    pos[a[p]].erase(p);
    a[p] = x;
    pos[x].insert(p);
    l = *prev(pos[a[p]].lower_bound(p));
    r = *pos[a[p]].upper_bound(p);
    if (l != 0) {
      add(1, l, p, r - 1, p - l);
    }
    if (r != n + 1) {
      add(l + 1, p, r, n, r - p);
    }
  };
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x != 1) {
      change(i, x);
      a[i] = x;
    }
    pos[x].insert(i);
  }
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      change(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      ans[i] = r - l;
      events.push_back({l, r, -1, -1, i});
    }
  }
  fenw = fenwick_tree<long long>(n + 1);
  sorted_events.resize((int)events.size());
  solve(0, (int)events.size());
  for (auto &x : ans) {
    if (x != -1) {
      cout << x << '\n';
    }
  }
  return 0;
}
