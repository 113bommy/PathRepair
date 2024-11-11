#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const int N = 1e5 + 5;
bool ok = false;
int mid, lx, ly, first, second, n, down, up, level[N];
vector<pair<int, int>> g[N];
int dfs(int v, int size, int &center, int pr = 0) {
  int sum = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    if (to != pr && level[to] == -1) {
      sum += dfs(to, size, center, v);
    }
  }
  if (center == -1 && sum >= size / 2) {
    center = v;
  }
  return sum;
}
void dfscalc(int v, int sum, int len, vector<pair<int, int>> &cur,
             int pr = -1) {
  if (len > cur.size()) {
    cur.push_back(make_pair(sum, v));
  } else {
    if (sum > cur[len - 1].first) {
      cur[len - 1] = make_pair(sum, v);
    }
  }
  if (len < up) {
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first;
      int val = (g[v][i].second >= mid ? 1 : -1);
      if (to != pr && level[to] == -1) {
        dfscalc(to, sum + val, len + 1, cur, v);
      }
    }
  }
}
bool cmp(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
  return (a.size() < b.size());
}
void upd(pair<int, int> tree[], int first, pair<int, int> second) {
  if (second.first > tree[first].first) {
    tree[first] = second;
  }
  while (first > 1) {
    first >>= 1;
    if (tree[first + first].first > tree[first + first + 1].first) {
      tree[first] = tree[first + first];
    } else {
      tree[first] = tree[first + first + 1];
    }
  }
}
pair<int, int> getmax(pair<int, int> tree[], int v, int lv, int rv, int l,
                      int r) {
  if (lv > r || rv < l) {
    return {-inf, -1};
  }
  if (lv >= l && rv <= r) {
    return tree[v];
  }
  int mid = (lv + rv) / 2;
  pair<int, int> q = getmax(tree, v + v, lv, mid, l, r);
  pair<int, int> w = getmax(tree, v + v + 1, mid + 1, rv, l, r);
  if (q.first > w.first) {
    return q;
  } else {
    return w;
  }
}
void calc(int v, int size) {
  vector<vector<pair<int, int>>> a;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    int val = g[v][i].second >= mid ? 1 : -1;
    if (level[to] == -1) {
      vector<pair<int, int>> cur;
      dfscalc(to, val, 1, cur, v);
      a.push_back(cur);
    }
  }
  if (a.size() == 0) {
    return;
  }
  int treesize = size;
  int sz = 1;
  while (sz < treesize) {
    sz <<= 1;
  }
  pair<int, int> tree[2 * sz];
  for (int i = 1; i < 2 * sz; i++) {
    tree[i] = {-inf, -1};
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      int len = j + 1;
      if (a[i][j].first >= 0) {
        if (len >= down && len <= up) {
          ok = true;
          first = v;
          second = a[i][j].second;
          return;
        }
      }
      if (len < up && a.size() > 1) {
        pair<int, int> tmp =
            getmax(tree, 1, 1, sz, max(1, down - len), up - len);
        if (a[i][j].first + tmp.first >= 0) {
          ok = true;
          first = tmp.second;
          second = a[i][j].second;
          return;
        }
      }
    }
    if (a.size() > 1) {
      for (int j = 0; j < a[i].size(); j++) {
        int len = j + 1;
        upd(tree, len + sz - 1, {a[i][j].first, a[i][j].second});
      }
    }
  }
}
void build(int v, int depth = 1) {
  int tmp = 0, center = -1;
  int size = dfs(v, 0, tmp);
  dfs(v, size, center);
  if (size < down) {
    return;
  }
  level[center] = depth;
  calc(center, size / 2 + 1);
  for (int i = 0; i < g[center].size() && !ok; i++) {
    int to = g[center][i].first;
    if (level[to] == -1) {
      build(to, depth + 1);
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> down >> up;
  int mx = 0;
  for (int i = 1; i < n; i++) {
    int q, w, c;
    cin >> q >> w >> c;
    g[q].push_back(make_pair(w, c));
    g[w].push_back(make_pair(q, c));
    mx = max(mx, c);
  }
  int l = 0;
  int r = mx;
  int lx, ly;
  while (l <= r) {
    memset(level, -1, sizeof(level));
    mid = (l + r) / 2;
    ok = false;
    build(1);
    if (ok) {
      l = mid + 1;
      lx = first;
      ly = second;
    } else {
      r = mid - 1;
    }
  }
  cout << lx << " " << ly << "\n";
}
