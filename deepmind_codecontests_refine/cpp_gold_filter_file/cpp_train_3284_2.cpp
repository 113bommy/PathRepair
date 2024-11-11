#include <bits/stdc++.h>
using namespace std;
int n, T, label, pos[2][1100];
struct node {
  unsigned long long v;
  int x, y;
  node() {}
  node(unsigned long long v, int x, int y) : v(v), x(x), y(y) {}
  friend bool operator<(const node &r1, const node &r2) { return r1.v < r2.v; };
};
vector<node> a[2];
struct tree {
  int id, m, f1, f2, sum;
  int used[1100], f[1100], size[1100], vis[1100];
  vector<int> v[1100], sub[1100];
  vector<unsigned long long> v1[1100], v2;
  vector<node> v3;
  unsigned long long val[1100];
  void init() {
    a[id].clear();
    memset(used, 0, sizeof(used));
    memset(vis, 0, sizeof(vis));
    v2.clear();
    for (int i = 1; i <= n; i++) v[i].clear(), sub[i].clear();
  }
  void getsub(int x, int y, int root) {
    sub[root].push_back(x);
    for (int i = 0, t; i < v[x].size(); i++)
      if ((t = v[x][i]) != y) getsub(t, x, root);
  }
  void dfs1(int x, int y) {
    size[x] = 1;
    used[x] = 1;
    for (int i = 0, t; i < v[x].size(); i++)
      if ((t = v[x][i]) != y && !vis[t]) dfs1(t, x), size[x] += size[t];
  }
  void dfs2(int x, int y) {
    f[x] = sum - size[x];
    for (int i = 0, t; i < v[x].size(); i++)
      if ((t = v[x][i]) != y && !vis[t]) dfs2(t, x), f[x] = max(f[x], size[t]);
    if (f[x] < f[f1])
      f1 = x;
    else if (f[x] < f[f2])
      f2 = x;
  }
  unsigned long long dfs3(int x, int y) {
    v1[x].clear();
    for (int i = 0, t; i < v[x].size(); i++)
      if ((t = v[x][i]) != y && !vis[t]) v1[x].push_back(dfs3(t, x));
    sort(v1[x].begin(), v1[x].end());
    unsigned long long ret = 1;
    for (int i = 0; i < v1[x].size(); i++) ret = ret * 11333333 + v1[x][i];
    return ret;
  }
  unsigned long long cal(int x) {
    f1 = f2 = 0;
    f[0] = 1 << 30;
    dfs1(x, 0);
    sum = size[x];
    dfs2(x, 0);
    if (f[f1] != f[f2]) return dfs3(f1, 0);
    unsigned long long t1 = dfs3(f1, f2);
    unsigned long long t2 = dfs3(f2, f1);
    if (t1 > t2) swap(t1, t2);
    return t1 * 11333333 + t2;
  }
  void solve(int x) {
    id = x;
    init();
    scanf("%d", &m);
    for (int i = 1, x, y; i <= m; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
      if (!used[i]) {
        getsub(i, 0, i);
        val[i] = cal(i);
        v2.push_back(val[i]);
      }
    sort(v2.begin(), v2.end());
    for (int i = 1; i <= n; i++)
      if (sub[i].size()) {
        unsigned long long t1 = 0, t2 = 0, t3 = 0;
        for (int j = 0, flag = 0; j < v2.size(); j++) {
          if (v2[j] == val[i] && !flag) {
            flag = 1;
            continue;
          }
          t1 = t1 * 23333333 + v2[j];
        }
        for (int j = 0, t; j < sub[i].size(); j++) {
          vis[t = sub[i][j]] = 1;
          v3.clear();
          v3.push_back(node(1, 0, 0));
          for (int k = 0; k < v[t].size(); k++)
            v3.push_back(node(cal(v[t][k]), v[t][k], 0));
          sort(v3.begin(), v3.end());
          for (int k = 1; k < v3.size(); k++) {
            t2 = 0;
            for (int w = 0; w < v3.size(); w++)
              if (w != k) t2 = t2 * 23333333 + v3[w].v;
            if (id == 0)
              t3 = v3[k].v * 5462617 * 5462617 + t2 * 5462617 + t1;
            else
              t3 = v3[k].v * 5462617 * 5462617 + t1 * 5462617 + t2;
            a[id].push_back(node(t3, v3[k].x, t));
          }
          t2 = 0;
          for (int w = 0; w < v3.size(); w++) t2 = t2 * 23333333 + v3[w].v;
          if (id == 0)
            t3 = t2 * 5462617 + t1;
          else
            t3 = t1 * 5462617 + t2;
          a[id].push_back(node(t3, 0, t));
          vis[t] = 0;
        }
      }
    sort(a[id].begin(), a[id].end());
  }
  void print() {
    puts("YES");
    for (int i = 1; i <= n; i++)
      for (int j = 0, t; j < v[i].size(); j++)
        if ((t = v[i][j]) < i) printf("%d %d\n", i, t);
  }
} tr[2], ans;
int relabel(int x, int y, int type) {
  int ret = pos[type][x] = ++label;
  for (int i = 0, t; i < tr[type].v[x].size(); i++)
    if ((t = tr[type].v[x][i]) != y) {
      int t1 = relabel(t, x, type);
      ans.v[ret].push_back(t1);
      ans.v[t1].push_back(ret);
    }
  return ret;
}
void solve() {
  scanf("%d%*d", &n);
  for (int i = 0; i <= 1; i++) tr[i].solve(i);
  for (int i = 0, now = 0; i < a[0].size(); i++) {
    while (now < a[1].size() && a[1][now].v < a[0][i].v) now++;
    if (now < a[1].size() && a[1][now].v == a[0][i].v) {
      relabel(a[0][i].y, 0, 0);
      int t = label;
      relabel(a[1][now].y, a[1][now].x, 1);
      ans.vis[pos[0][a[0][i].y]] = 1;
      int t1 = pos[1][a[1][now].y];
      unsigned long long v1 = tr[1].cal(a[1][now].y);
      for (int j = 1; j <= t; j++) {
        ans.v[j].push_back(t1);
        ans.v[t1].push_back(j);
        if (ans.cal(t1) == v1) {
          ans.print();
          return;
        }
        ans.v[j].pop_back();
        ans.v[t1].pop_back();
      }
    }
  }
  puts("NO");
}
int main() {
  scanf("%d", &T);
  while (T--) {
    label = 0;
    memset(pos, 0, sizeof(pos));
    a[0].clear();
    a[1].clear();
    ans.init();
    solve();
  }
  return 0;
}
