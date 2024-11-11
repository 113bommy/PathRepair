#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int len;
deque<int> all_snake;
vector<vector<int>> g;
vector<int> mx1;
vector<int> len3;
int blen3;
vector<int> go1, go2;
vector<int> pred;
void dfs_len(int u, int p, int l) {
  if (u == b) {
    len = l;
  }
  pred[u] = p;
  for (auto i : g[u]) {
    if (i == p) continue;
    all_snake.push_back(i);
    dfs_len(i, u, l + 1);
    if (all_snake.back() != b) all_snake.pop_back();
  }
}
void dfs_cnt(int u) {
  for (auto i : g[u]) {
    if (i == pred[u]) continue;
    dfs_cnt(i);
    if (mx1[i] + 1 > mx1[u]) {
      mx1[u] = mx1[i] + 1;
    }
  }
}
void dfs_cnt_2(int u, int mxl_up) {
  int m1 = -1, m2 = -1;
  int l1 = 0, l2 = 0, l3 = 0;
  for (auto i : g[u]) {
    if (i == pred[u]) continue;
    int c = mx1[i] + 1;
    if (c > l1) {
      l3 = l2;
      l2 = l1;
      m2 = m1;
      m1 = i;
      l1 = c;
    } else if (c > l2) {
      l3 = l2;
      l2 = c;
      m2 = i;
    } else if (c > l3) {
      l3 = c;
    }
  }
  int c = mxl_up;
  if (c > l1) {
    l3 = l2;
    m2 = m1;
    l2 = l1;
    m1 = pred[u];
    l1 = c;
  } else if (c > l2) {
    l3 = l2;
    m2 = pred[u];
    l2 = c;
  } else if (c > l3) {
    l3 = c;
  }
  go1[u] = m1;
  go2[u] = m2;
  if (l3 >= len) {
    blen3 = 1;
    len3[u] = 1;
  }
  for (auto i : g[u]) {
    if (i == pred[u]) continue;
    if (m1 == i) {
      dfs_cnt_2(i, l2 + 1);
    } else {
      dfs_cnt_2(i, l1 + 1);
    }
  }
}
int lastb;
int backb;
bool can;
void move_a() {
  while (1) {
    int a1 = all_snake.front();
    if (g[a1].size() == 1) {
      backb = all_snake.back();
      return;
    }
    all_snake.pop_back();
    if (go1[a1] == all_snake[1]) {
      all_snake.push_front(go2[a1]);
    } else {
      all_snake.push_front(go1[a1]);
    }
  }
}
void move_b() {
  while (1) {
    if (all_snake.front() == backb) {
      can = 1;
      return;
    }
    int b1 = all_snake.back();
    if (g[b1].size() == 1) {
      return;
    }
    all_snake.pop_front();
    if (go1[b1] == all_snake[len - 2]) {
      all_snake.push_back(go2[b1]);
    } else {
      all_snake.push_back(go1[b1]);
    }
  }
}
bool move() {
  lastb = -1;
  backb = -1;
  can = 0;
  while (1) {
    move_a();
    move_b();
    if (can == 1) {
      return 1;
    }
    if (lastb == all_snake.back()) {
      return 0;
    }
    lastb = all_snake.back();
  }
  return 0;
}
void solve() {
  cin >> n >> a >> b;
  a--, b--;
  g.assign(n, vector<int>(0));
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  mx1.assign(n, 0);
  len3.assign(n, 0);
  blen3 = 0;
  go1.assign(n, -1);
  go2.assign(n, -1);
  pred.assign(n, 0);
  all_snake = {a};
  dfs_len(a, a, 0);
  dfs_cnt(a);
  dfs_cnt_2(a, 0);
  if (!move()) {
    cout << "NO\n";
    return;
  }
  if (blen3) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
