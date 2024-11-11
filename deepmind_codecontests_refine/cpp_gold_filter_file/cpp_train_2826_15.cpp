#include <bits/stdc++.h>
using namespace std;
struct dish {
  int p, s, b;
};
struct person {
  int inc, pref, idx;
};
struct event {
  int x, y_1, y_2, mul, idx;
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
  T query(int x, int y) {
    int ans = query(y);
    if (x > 0) {
      ans -= query(x - 1);
    }
    return ans;
  }
  void reset() {
    while (!st.empty()) {
      fenw[st.top()] = 0;
      st.pop();
    }
  }
};
vector<event> events, sorted_events;
vector<int> ans;
fenwick_tree<int> fenw(0);
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
      if (events[i].y_2 == -1) {
        fenw.update(events[i].y_1, events[i].idx);
      }
      sorted_events[cur++] = events[i++];
    } else {
      if (events[j].y_2 != -1) {
        ans[events[j].idx] +=
            fenw.query(events[j].y_1, events[j].y_2) * events[j].mul;
      }
      sorted_events[cur++] = events[j++];
    }
  }
  while (j < r) {
    if (events[j].y_2 != -1) {
      ans[events[j].idx] +=
          fenw.query(events[j].y_1, events[j].y_2) * events[j].mul;
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
  vector<dish> dishes(n);
  for (int i = 0; i < n; i++) {
    cin >> dishes[i].p;
  }
  for (int i = 0; i < n; i++) {
    cin >> dishes[i].s;
  }
  for (int i = 0; i < n; i++) {
    cin >> dishes[i].b;
  }
  vector<person> people(m);
  for (int i = 0; i < m; i++) {
    cin >> people[i].inc;
  }
  for (int i = 0; i < m; i++) {
    cin >> people[i].pref;
  }
  set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(dishes[i].p + dishes[i].b);
    st.insert(dishes[i].p - dishes[i].b);
  }
  for (int j = 0; j < m; j++) {
    st.insert(people[j].inc + people[j].pref);
    st.insert(people[j].inc - people[j].pref);
    people[j].idx = j;
  }
  map<int, int> mp;
  int cur = 0;
  for (auto &x : st) {
    mp[x] = cur++;
  }
  fenw = fenwick_tree<int>(cur);
  sort(dishes.rbegin(), dishes.rend(),
       [](const dish &a, const dish &b) { return a.s < b.s; });
  sort(people.rbegin(), people.rend(),
       [](const person &a, const person &b) { return a.inc < b.inc; });
  int i = 0;
  for (int j = 0; j < m; j++) {
    while (i < n && dishes[i].s >= people[j].inc) {
      events.push_back({mp[dishes[i].p + dishes[i].b],
                        mp[dishes[i].p - dishes[i].b], -1, 0, +1});
      i++;
    }
    events.push_back({mp[people[j].inc + people[j].pref], 0,
                      mp[people[j].inc - people[j].pref], +1, people[j].idx});
  }
  sorted_events.resize((int)events.size());
  ans.resize(m);
  solve(0, (int)events.size());
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}
