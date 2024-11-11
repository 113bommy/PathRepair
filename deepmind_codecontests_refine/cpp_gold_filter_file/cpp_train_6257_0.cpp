#include <bits/stdc++.h>
using namespace std;
template <typename T>
void resize(int n, vector<T> &u) {
  u.resize(n);
}
template <typename Head, typename... Tail>
void resize(int n, Head &H, Tail &...T) {
  resize(n, H);
  resize(n, T...);
}
template <typename T>
void debug_out(T t) {
  cerr << t;
}
template <typename A, typename B>
void debug_out(pair<A, B> &u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
template <typename T>
void debug_out(vector<T> &t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << ", ";
  }
}
template <typename T>
void debug_out(vector<vector<T>> &t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << endl;
  }
}
int m, n;
vector<vector<int>> grid, res;
vector<pair<int, int>> cur;
inline void adj(int x) {
  auto u = cur[x];
  grid[u.first][u.second] = x;
}
inline pair<bool, bool> block(int x, int direction) {
  int u = cur[x].first, v = cur[x].second;
  assert(!(direction == 0 && u == 0) || (direction == 1 && u == n - 1) ||
         (direction == 2 && v == 0) || (direction == 3 && v == m - 1));
  if (direction < 2) {
    bool ok = direction == 0;
    if (v == 0)
      return make_pair(ok, true);
    else
      return make_pair(ok, false);
  } else {
    bool ok = direction == 3;
    if (u == n - 1)
      return make_pair(true, ok);
    else
      return make_pair(false, ok);
  }
}
inline void rotate(int val, bool up, bool rig, int direction) {
  assert((direction == 0 && up) || (direction == 1 && !up) ||
         (direction == 2 && !rig) || (direction == 3 && rig));
  auto des = cur[val];
  auto opposite = des;
  opposite.first += (up ? -1 : 1);
  opposite.second += (rig ? 1 : -1);
  int x = des.first, y = des.second, u = opposite.first, v = opposite.second;
  if (!(0 <= u && u < n && 0 <= v && v < m)) {
    cerr << "["
         << "grid"
         << "]:" << endl,
        debug_out(grid), cerr << endl;
    ;
    cerr << "["
         << "val"
         << "]:" << endl,
        debug_out(val), cerr << endl;
    ;
    cerr << "["
         << "up"
         << "]:" << endl,
        debug_out(up), cerr << endl;
    ;
    cerr << "["
         << "rig"
         << "]:" << endl,
        debug_out(rig), cerr << endl;
    ;
    cerr << "["
         << "direction"
         << "]:" << endl,
        debug_out(direction), cerr << endl;
    ;
  }
  assert(0 <= u && u < n && 0 <= v && v < m);
  int r = grid[u][y], g = grid[x][v], p = grid[u][v];
  if (direction > 1) {
    res.push_back({val, g, p, r});
    cur[val] = cur[g];
    cur[g] = cur[p];
    cur[p] = cur[r];
    cur[r] = make_pair(x, y);
  } else {
    res.push_back({val, r, p, g});
    cur[val] = cur[r];
    cur[r] = cur[p];
    cur[p] = cur[g];
    cur[g] = make_pair(x, y);
  }
  adj(val), adj(g), adj(p), adj(r);
}
inline void adv(int x, int direction) {
  auto u = block(x, direction);
  rotate(x, u.first, u.second, direction);
}
inline vector<int> block_6(int x, int direction) {
  auto b = block(x, direction);
  int u = cur[x].first, v = cur[x].second;
  int pu = u + (b.first ? -1 : 1), pv = v + (b.second ? 1 : -1);
  vector<int> l = {u, pu}, r = {v, pv};
  vector<pair<int, int>> des;
  if (direction < 2) {
    int core = 2 * pu - u;
    des = {make_pair(core, v), make_pair(core, pv)};
  } else {
    int core = 2 * pv - v;
    des = {make_pair(u, core), make_pair(pu, core)};
  }
  for (auto i : l) {
    for (auto j : r) {
      des.emplace_back(i, j);
    }
  }
  sort(des.begin(), des.end(), [&](pair<int, int> a, pair<int, int> b) {
    auto p = make_pair(abs(a.first - u), abs(a.second - v)),
         q = make_pair(abs(b.first - u), abs(b.second - v));
    if (direction > 1) {
      swap(p.first, p.second);
      swap(q.first, q.second);
    }
    return p < q;
  });
  swap(des[2], des[3]);
  swap(des[3], des[5]);
  vector<int> res;
  for (auto i : des) res.push_back(grid[i.first][i.second]);
  return res;
}
inline void trick(int x, int direction) {
  auto u = cur[x].first, v = cur[x].second;
  assert(!(direction == 0 && u == 0) || (direction == 1 && u == n - 1) ||
         (direction == 2 && v == 0) || (direction == 3 && v == m - 1));
  if (direction == 0) u--;
  if (direction == 1) u++;
  if (direction == 2) v--;
  if (direction == 3) v++;
  int y = grid[u][v];
  if (u == cur[x].first) {
    if (v == 0 || v == m - 1) {
      swap(x, y);
      direction = (direction < 2 ? 1 : 5) - direction;
    }
  } else if (u == 0 || u == n - 1) {
    swap(x, y);
    direction = (direction < 2 ? 1 : 5) - direction;
  }
  auto can = block(x, direction);
  int mem_u = cur[x].first, mem_v = cur[x].second;
  adv(x, direction);
  u = cur[y].first, v = cur[y].second;
  int dir;
  if (u && grid[u - 1][v] == x) dir = 0;
  if (u != n - 1 && grid[u + 1][v] == x) dir = 1;
  if (v && grid[u][v - 1] == x) dir = 2;
  if (v != m - 1 && grid[u][v + 1] == x) dir = 3;
  if (direction < 2)
    can.second = !can.second;
  else
    can.first = !can.first;
  rotate(y, can.first, can.second, dir);
  vector<int> foo = block_6(grid[mem_u][mem_v], direction);
  res.push_back(foo);
  for (int i = 0; i < 6; i++) {
    if (i < 5)
      cur[foo[i]] = cur[foo[i + 1]];
    else
      cur[foo[i]] = make_pair(mem_u, mem_v);
  }
  for (auto i : foo) adj(i);
}
void solve() {
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m; j++) {
      int val = i * m + j;
      while (cur[val].second != j) {
        int u = cur[val].second;
        if (u < j)
          adv(val, 3);
        else
          adv(val, 2);
      }
      if (cur[val].first == i) continue;
      while (cur[val].first > i + 1) {
        adv(val, 0);
      }
      trick(val, 0);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = n - 2; j < n; j++) {
      int val = j * m + i;
      if (cur[val].first != j) {
        if (cur[val].first > j)
          trick(val, 0);
        else
          trick(val, 1);
      }
      if (cur[val].second == i) continue;
      while (cur[val].second > i + 1) {
        adv(val, 2);
      }
      trick(val, 2);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cur.resize(m * n);
  grid.resize(n);
  for (auto &i : grid) i.resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      grid[i][j]--;
      cur[grid[i][j]] = make_pair(i, j);
    }
  }
  solve();
  cout << res.size() << endl;
  for (auto i : res) {
    cout << i.size() << " ";
    for (auto j : i) cout << j + 1 << " ";
    cout << endl;
  }
  return 0;
}
