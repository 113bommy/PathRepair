#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9 + 7;
const int Maxn = 100020;
int n;
int a[Maxn], b[Maxn], c[Maxn], d[Maxn];
set<pair<int, int> > ss[Maxn << 2];
vector<int> V;
int pre[Maxn];
int getid(int x) { return lower_bound(V.begin(), V.end(), x) - V.begin() + 1; }
void add(int id, int ty, int l, int r, int x) {
  if (ty == 1)
    ss[x].insert(pair<int, int>(d[id], id));
  else
    ss[x].erase(pair<int, int>(d[id], id));
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (c[id] <= mid)
    add(id, ty, l, mid, x << 1);
  else
    add(id, ty, mid + 1, r, x << 1 | 1);
}
int debug;
int find(int Lc, int Rc, int Ld, int l, int r, int x) {
  if (Lc <= l && Rc >= r) {
    auto it = ss[x].lower_bound(pair<int, int>(Ld, -1));
    if (it != ss[x].end()) return it->second;
    return -1;
  }
  int mid = (l + r) >> 1;
  if (Lc <= mid) {
    int t = find(Lc, Rc, Ld, l, mid, x << 1);
    if (t >= 0) return t;
  }
  if (Rc > mid) {
    int t = find(Lc, Rc, Ld, mid + 1, r, x << 1 | 1);
    if (t >= 0) return t;
  }
  return -1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
  for (int i = 1; i <= n; i++) V.push_back(c[i]);
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());
  for (int i = 0; i < n; i++) c[i] = getid(c[i]);
  for (int i = 0; i < n; i++) add(i, 1, 1, V.size(), 1);
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int ta = getid(a[u]);
    int id;
    while ((id = find(ta, V.size(), b[u], 1, V.size(), 1)) >= 0) {
      debug++;
      add(id, -1, 1, V.size(), 1);
      pre[id] = u;
      q.push(id);
    }
  }
  if (pre[0] == 0) {
    puts("-1");
  } else {
    vector<int> rep;
    for (int cur = 0; cur != n; cur = pre[cur]) rep.push_back(pre[cur]);
    printf("%d\n", (int)rep.size());
    for (int i = 0; i < rep.size(); i++)
      printf("%d%c", rep[i], i == rep.size() - 1 ? '\n' : ' ');
  }
}
