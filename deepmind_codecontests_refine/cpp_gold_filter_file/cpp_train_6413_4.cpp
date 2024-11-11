#include <bits/stdc++.h>
using namespace std;
int n, m, curr;
int A[200007];
int B[200007];
int C[200007];
int r[200007];
vector<int> G[200007];
vector<int> e;
bitset<200007> ins;
int size[200007];
int top[200007];
int p[200007];
int pos[200007];
int sub[2 * (1 << 18)];
int load[2 * (1 << 18)];
int res[200007];
int depth[200007];
bool comp(int a, int b) { return C[a] < C[b]; }
int Find(int a) {
  if (r[a] != a) r[a] = Find(r[a]);
  return r[a];
}
void insert(int a, int b, int c, int v = 1, int l = 0, int r = (1 << 18) - 1) {
  if (a > b || a > r || l > b) return;
  if (a <= l && r <= b) {
    load[v] = min(load[v], c);
    sub[v] = min(sub[v], c);
    return;
  }
  insert(a, b, c, 2 * v, l, (l + r) / 2);
  insert(a, b, c, 2 * v + 1, (l + r) / 2 + 1, r);
  sub[v] = min(load[v], min(sub[2 * v], sub[2 * v + 1]));
}
int query(int a, int b, int path = 0x3f3f3f3f, int v = 1, int l = 0,
          int r = (1 << 18) - 1) {
  if (a > b || a > r || l > b) return 0x3f3f3f3f;
  if (a <= l && r <= b) return min(sub[v], path);
  return min(query(a, b, min(path, load[v]), 2 * v, l, (l + r) / 2),
             query(a, b, min(path, load[v]), 2 * v + 1, (l + r) / 2 + 1, r));
}
void dfs(int v) {
  size[v] = 1;
  for (auto it : G[v]) {
    if (it != p[v]) {
      depth[it] = depth[v] + 1;
      p[it] = v;
      dfs(it);
      size[v] += size[it];
    }
  }
}
void hld(int v, int r) {
  top[v] = r;
  pos[v] = ++curr;
  auto h = make_pair(-1, -1);
  for (auto it : G[v]) {
    if (it != p[v]) h = max(h, make_pair(size[it], it));
  }
  if (h.second != -1) {
    hld(h.second, r);
    for (auto it : G[v]) {
      if (it != p[v] && it != h.second) hld(it, it);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    r[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> A[i] >> B[i] >> C[i];
    e.push_back(i);
  }
  sort((e).begin(), (e).end(), comp);
  for (auto it : e) {
    int a = Find(A[it]);
    int b = Find(B[it]);
    if (a != b) {
      r[a] = b;
      G[A[it]].push_back(B[it]);
      G[B[it]].push_back(A[it]);
      ins[it] = 1;
    }
  }
  dfs(1);
  hld(1, 1);
  memset(sub, 0x3f3f3f3f, sizeof sub);
  memset(load, 0x3f3f3f3f, sizeof load);
  for (int i = 1; i <= m; ++i) {
    if (!ins[i]) {
      int a = A[i];
      int b = B[i];
      while (top[a] != top[b]) {
        if (depth[top[a]] > depth[top[b]]) swap(a, b);
        insert(pos[top[b]], pos[b], C[i]);
        b = p[top[b]];
      }
      if (depth[a] > depth[b]) swap(a, b);
      insert(pos[a] + 1, pos[b], C[i]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (ins[i]) {
      if (depth[A[i]] > depth[B[i]]) swap(A[i], B[i]);
      res[i] = query(pos[B[i]], pos[B[i]]) - 1;
      if (res[i] + 1 == 0x3f3f3f3f) res[i] = -1;
    }
  }
  memset(sub, 0x3f3f3f3f, sizeof sub);
  memset(load, 0x3f3f3f3f, sizeof load);
  for (int i = 1; i <= m; ++i) {
    if (ins[i]) insert(pos[B[i]], pos[B[i]], -C[i]);
  }
  for (int i = 1; i <= m; ++i) {
    if (!ins[i]) {
      res[i] = -0x3f3f3f3f;
      int a = A[i];
      int b = B[i];
      while (top[a] != top[b]) {
        if (depth[top[a]] > depth[top[b]]) swap(a, b);
        res[i] = max(res[i], -query(pos[top[b]], pos[b]) - 1);
        b = p[top[b]];
      }
      if (depth[a] > depth[b]) swap(a, b);
      res[i] = max(res[i], -query(pos[a] + 1, pos[b]) - 1);
      if (res[i] == -0x3f3f3f3f) res[i] = -1;
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << res[i] << " ";
  }
}
