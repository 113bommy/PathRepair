#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int u, v, cu, cv;
} Edge;
Edge e[500010];
int sz[1000010], fa[1000010];
int top;
pair<int, int> stk[1000010];
int n, m, k, col[500010], tot;
bool out[500010];
long long cnt, ans;
void init() {
  for (int i = 1; i <= n + n; i++) {
    fa[i] = i;
    sz[i] = 1;
  }
}
int find(int x) {
  if (x == fa[x])
    return x;
  else
    return find(fa[x]);
}
void merge(int u, int v) {
  int fu = find(u), fv = find(v);
  if (sz[fu] > sz[fv]) swap(fu, fv);
  stk[++top] = {fu, fv};
  fa[fu] = fv;
  sz[fv] += sz[fu];
}
int cmp(Edge a, Edge b) {
  if (a.cu == b.cu) return a.cv < b.cv;
  return a.cu < b.cu;
}
void undo() {
  pair<int, int> t = stk[top--];
  fa[t.first] = t.first;
  sz[t.second] -= sz[t.first];
}
int main() {
  cin >> n >> m >> k;
  init();
  for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (col[a] != col[b])
      e[++tot] = {a, b, min(col[a], col[b]), max(col[a], col[b])};
    else {
      int fu = find(a), fv = find(b), fuu = find(a + n), fvv = find(b + n);
      if (fu == fv)
        out[col[a]] = 1;
      else {
        merge(fu, fvv);
        merge(fv, fuu);
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    if (!out[i]) cnt++;
  }
  ans = cnt * (cnt - 1) / 2;
  int last_sz = top;
  sort(e + 1, e + 1 + tot, cmp);
  int flag = 0;
  for (int i = 1; i <= tot; i++) {
    if (e[i].cu != e[i - 1].cu || e[i].cv != e[i - 1].cv) {
      flag = 0;
      while (top != last_sz) undo();
    }
    if (out[e[i].cu] || out[e[i].cv]) continue;
    if (flag) continue;
    int fu = find(e[i].u), fv = find(e[i].v), fuu = find(e[i].u + n),
        fvv = find(e[i].v + n);
    if (fu == fv) {
      ans--;
      flag = 1;
      continue;
    }
    merge(fu, fvv);
    merge(fv, fuu);
  }
  cout << ans << endl;
  return 0;
}
