#include <bits/stdc++.h>
using namespace std;
const int maxN = 4e5 + 5;
int n, q, cnt;
int c[maxN];
vector<int> head[maxN];
int st[maxN], en[maxN];
long long it[maxN * 4], inc[maxN * 4];
void DFS(int u, int pre) {
  st[u] = ++cnt;
  for (int v : head[u]) {
    if (v == pre) continue;
    DFS(v, u);
  }
  en[u] = cnt;
}
void Add(int i) {
  it[i + i] = it[i + i + 1] = inc[i];
  inc[i + i] = inc[i + i + 1] = inc[i];
  inc[i] = 0;
}
void Update(int i, int l, int r, int u, int v, int value) {
  if (l > v || r < u) return;
  if (l >= u && r <= v) {
    it[i] = (1ll << value);
    inc[i] = (1ll << value);
    return;
  }
  int mid = (l + r) >> 1;
  if (inc[i] > 0) Add(i);
  Update(i + i, l, mid, u, v, value);
  Update(i + i + 1, mid + 1, r, u, v, value);
  it[i] = it[i + i] | it[i + i + 1];
}
long long Get(int i, int l, int r, int u, int v) {
  if (l > v || r < u) return 0;
  if (l >= u && r <= v) return it[i];
  int mid = (l + r) >> 1;
  if (inc[i] > 0) Add(i);
  return Get(i + i, l, mid, u, v) | Get(i + i + 1, mid + 1, r, u, v);
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), --c[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    head[u].push_back(v);
    head[v].push_back(u);
  }
  cnt = 0;
  DFS(1, 0);
  for (int i = 1; i <= n; ++i) Update(1, 1, n, st[i], st[i], c[i]);
  while (q--) {
    int id;
    scanf("%d", &id);
    if (id == 1) {
      int u, v;
      scanf("%d %d", &u, &v);
      Update(1, 1, n, st[u], en[u], v);
    } else {
      int u;
      scanf("%d", &u);
      printf("%d\n", __builtin_popcountll(Get(1, 1, n, st[u], en[u])));
    }
  }
  return 0;
}
