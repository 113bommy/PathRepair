#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Edge {
  int u, v;
} edge[N << 2];
int n, m, s, t, ds, dt;
int fa[N];
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
int fs[N], ft[N];
vector<int> es, et, now, ans;
int stot = -1;
bool mark[N * 4];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &edge[i].u, &edge[i].v);
  scanf("%d%d%d%d", &s, &t, &ds, &dt);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int u = edge[i].u, v = edge[i].v;
    if (v == s) swap(u, v);
    if (u == t) swap(u, v);
    if (u == s && v == t) {
      stot = i;
      continue;
    }
    if (u == s)
      es.push_back(i), now.push_back(i);
    else if (v == t)
      et.push_back(i), now.push_back(i);
    if (u == s || v == t) continue;
    u = find(u), v = find(v);
    if (u != v) {
      fa[u] = v;
      ans.push_back(i);
    }
  }
  for (int i = 0; i < es.size(); ++i) {
    int id = es[i];
    int u = edge[id].u, v = edge[id].v;
    if (v == s) swap(u, v);
    v = find(v);
    ++fs[v];
  }
  for (int i = 0; i < et.size(); ++i) {
    int id = et[i];
    int u = edge[id].u, v = edge[id].v;
    if (v == t) swap(u, v);
    v = find(v);
    ++ft[v];
  }
  int x = 0, y = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == s || i == t || find(i) != i) continue;
    if (fs[i] != 0 && ft[i] == 0)
      ++x;
    else if (fs[i] == 0 && ft[i] != 0)
      ++y;
  }
  if (x > ds || y > dt) {
    printf("No\n");
    return 0;
  }
  for (int i = 0; i < now.size(); ++i) {
    int id = now[i];
    int u = edge[id].u, v = edge[id].v;
    if (find(u) == find(v)) {
      mark[i] = true;
      continue;
    }
    if (u == s || v == s) {
      if (v == s) swap(u, v);
      v = find(v);
      if (ft[v] == 0) {
        fa[v] = s;
        mark[i] = true;
        ans.push_back(id);
      }
    } else if (u == t || v == t) {
      if (v == t) swap(u, v);
      v = find(v);
      if (fs[v] == 0) {
        fa[v] = t;
        mark[i] = true;
        ans.push_back(id);
      }
    }
  }
  for (int i = 0; i < now.size(); ++i) {
    if (mark[i]) continue;
    int id = now[i];
    int u = edge[id].u, v = edge[id].v;
    if (find(u) == find(v)) {
      mark[i] = true;
      continue;
    }
    if (u == s || v == s) {
      if (v == s) swap(u, v);
      if (x < ds) {
        v = find(v);
        fa[v] = s;
        ans.push_back(id);
        ++x;
      }
    } else if (u == t || v == t) {
      if (v == t) swap(u, v);
      v = find(v);
      if (y < dt) {
        v = find(v);
        fa[v] = t;
        ans.push_back(id);
        ++y;
      }
    }
  }
  if (find(s) != find(t)) {
    if (x + 1 > ds || y + 1 > ds) {
      printf("No\n");
      return 0;
    }
    ans.push_back(stot);
    fa[find(t)] = find(s);
  }
  if (ans.size() != n - 1) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  for (int i = 0; i < ans.size(); ++i) {
    int j = ans[i];
    printf("%d %d\n", edge[j].u, edge[j].v);
  }
  return 0;
}
