#include <bits/stdc++.h>
using namespace std;
struct ITree {
  int size;
  vector<int> data;
  ITree() { size = 0; }
  void start(int n) {
    int k = 1;
    while (k < n) k *= 2;
    data.resize(k + n + 1);
    size = k;
  }
  int get(int x, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return 0;
    if (tl >= l && tr <= r) return data[x];
    int tm = (tl + tr) / 2;
    return get(2 * x, tl, tm, l, r) + get(2 * x + 1, tm + 1, tr, l, r);
  }
  void up(int x, int tl, int tr, int xp, int zxp) {
    int tm = (tl + tr) / 2;
    if (x == xp) {
      data[x] = zxp;
      return;
    }
    if (xp > tm) up(2 * x + 1, tm + 1, tr, xp, zxp);
    if (xp <= tm) up(2 * x, tl, tm, xp, zxp);
    data[x] = data[2 * x] + data[2 * x + 1];
  }
};
pair<int, int> q[1000001];
vector<vector<int> > t;
pair<int, int> v[1000001];
int mx = 0, mi = 0;
int u[1000001], ir[1000001];
void dfs(int x, int r, int e) {
  u[x] = 1;
  if (x == mi)
    v[x] = make_pair(-1, 0);
  else
    v[x] = make_pair(r, e);
  for (int i = 0; i < (t[x].size()); i++) {
    if (!u[t[x][i]]) {
      if (x == mi)
        dfs(t[x][i], i, e + 1);
      else
        dfs(t[x][i], r, e + 1);
    }
  }
}
ITree p[100111];
int main() {
  int n;
  cin >> n;
  t.resize(n);
  for (int i = 0; i < (n - 1); i++) {
    cin >> q[i].first >> q[i].second;
    --q[i].first;
    --q[i].second;
    t[q[i].first].push_back(q[i].second);
    t[q[i].second].push_back(q[i].first);
  }
  for (int i = 0; i < (n - 1); i++)
    if (t[i].size() > mx) {
      mx = t[i].size();
      mi = i;
    }
  dfs(mi, 0, 0);
  int mr = 0;
  for (int i = 0; i < (n); i++)
    if (v[i].first != -1) {
      ir[v[i].first] = max(ir[v[i].first], v[i].second);
      mr = max(mr, v[i].first);
    }
  for (int i = 0; i < (mr + 1); i++) p[i].start(ir[i]);
  int m;
  cin >> m;
  for (int i = 0; i < (m); i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int id;
      cin >> id;
      --id;
      if (v[q[id].first].second > v[q[id].second].second) {
        int sz = p[v[q[id].first].first].size;
        p[v[q[id].first].first].up(1, sz, 2 * sz - 1,
                                   v[q[id].first].second + sz - 1, 0);
      } else {
        int sz = p[v[q[id].second].first].size;
        p[v[q[id].second].first].up(1, sz, 2 * sz - 1,
                                    v[q[id].second].second + sz - 1, 0);
      }
    }
    if (type == 2) {
      int id;
      cin >> id;
      --id;
      if (v[q[id].first].second > v[q[id].second].second) {
        int sz = p[v[q[id].first].first].size;
        p[v[q[id].first].first].up(1, sz, 2 * sz - 1,
                                   v[q[id].first].second + sz - 1, 1);
      } else {
        int sz = p[v[q[id].second].first].size;
        p[v[q[id].second].first].up(1, sz, 2 * sz - 1,
                                    v[q[id].second].second + sz - 1, 1);
      }
    }
    if (type == 3) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      if (x == y) {
        cout << "0\n";
        continue;
      }
      if (v[x].first == -1) {
        int sz = p[v[y].first].size;
        if (p[v[y].first].get(1, sz, 2 * sz - 1, sz, v[y].second + sz - 1) == 0)
          cout << v[y].second << '\n';
        else
          cout << "-1\n";
        continue;
      }
      if (v[y].first == -1) {
        int sz = p[v[x].first].size;
        if (p[v[x].first].get(1, sz, 2 * sz - 1, sz, v[x].second + sz - 1) == 0)
          cout << v[x].second << '\n';
        else
          cout << "-1\n";
        continue;
      }
      if (v[x].first == v[y].first) {
        int sz = p[v[x].first].size;
        if (p[v[x].first].get(1, sz, 2 * sz - 1,
                              min(v[x].second, v[y].second) + sz,
                              max(v[x].second, v[y].second) + sz - 1) == 0)
          cout << max(v[x].second, v[y].second) - min(v[x].second, v[y].second)
               << '\n';
        else
          cout << "-1\n";
        continue;
      } else {
        int sz = p[v[x].first].size;
        if (p[v[x].first].get(1, sz, 2 * sz - 1, sz, v[x].second + sz - 1) ==
            0) {
          sz = p[v[y].first].size;
          if (p[v[y].first].get(1, sz, 2 * sz - 1, sz, v[y].second + sz - 1) ==
              0)
            cout << v[y].second + v[x].second << '\n';
          else
            cout << "-1\n";
        } else
          cout << "-1\n";
      }
    }
  }
  return 0;
}
