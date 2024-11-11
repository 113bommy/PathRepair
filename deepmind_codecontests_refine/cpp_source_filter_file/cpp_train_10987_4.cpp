#include <bits/stdc++.h>
using namespace std;
int n, T;
multiset<unsigned long long> se;
multiset<unsigned long long>::iterator it;
unsigned long long val[110];
struct tree {
  int m, top, f1, f2, sum, id;
  int vis[110], size[110], used[110], f[110];
  vector<int> v[110];
  vector<unsigned long long> v1[110];
  unsigned long long st[110];
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
  void init(int x) {
    scanf("%d", &m);
    id = x;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1, x, y; i <= m; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    memset(used, 0, sizeof(used));
    top = 0;
    for (int i = 1; i <= n; i++)
      if (!used[i]) st[++top] = cal(i);
    sort(st + 1, st + 1 + top);
    val[id] = 0;
    for (int i = 2; i <= top; i++) val[id] = val[id] * 11333333 + st[i];
  }
  int check() {
    se.clear();
    for (int i = 1; i <= n; i++) {
      vis[i] = 1;
      top = 0;
      for (int j = 0; j < v[i].size(); j++) st[++top] = cal(v[i][j]);
      vis[i] = 0;
      unsigned long long tmp = 0;
      sort(st + 1, st + 1 + top);
      for (int j = 1; j <= top; j++) tmp = tmp * 11333333 + st[j];
      se.insert(tmp);
    }
    for (int i = 1; i <= n; i++)
      if (i != id) {
        if ((it = se.find(val[i])) == se.end()) return 0;
        se.erase(it);
      }
    return 1;
  }
  void print() {
    puts("YES");
    for (int i = 1; i <= n; i++) {
      for (int j = 0, t; j < v[i].size(); j++)
        if ((t = v[i][j]) < i) printf("%d%d\n", t, i);
    }
  }
} tr[110];
void solve() {
  scanf("%d%*d", &n);
  for (int i = 1; i <= n; i++) tr[i].init(i);
  for (int i = 1; i <= n; i++)
    if (tr[i].top == 2) {
      for (int j = 1; j <= n; j++)
        if (tr[i].v[j].empty()) {
          for (int k = 1; k <= n; k++)
            if (k != j) {
              tr[i].v[k].push_back(j);
              tr[i].v[j].push_back(k);
              if (tr[i].check()) {
                tr[i].print();
                return;
              }
              tr[i].v[k].pop_back();
              tr[i].v[j].pop_back();
            }
        }
      break;
    }
  puts("NO");
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
