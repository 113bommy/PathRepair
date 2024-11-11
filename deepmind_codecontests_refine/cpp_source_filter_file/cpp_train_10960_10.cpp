#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v;
int c[500007];
int fa[1000007];
int sz[1000007];
int vis[1000007];
stack<pair<int, int>> sa;
struct madoka {
  int u;
  int v;
  int cu;
  int cv;
};
bool cmp(madoka a1, madoka a2) {
  if (a1.cv == a2.cv) {
    return a1.cu < a2.cu;
  }
  return a1.cv < a2.cv;
}
vector<madoka> ho;
int fin(int p) {
  if (p == fa[p])
    return p;
  else {
    return fa[p];
  }
}
void merge(int u, int v) {
  int f1 = fin(u);
  int f2 = fin(v);
  if (sz[f1] > sz[f2]) {
    swap(f1, f2);
  }
  fa[f1] = f2;
  sz[f2] += sz[f1];
  sa.push({f1, f2});
}
void clr() {
  while (!sa.empty()) {
    int f1 = sa.top().first;
    int f2 = sa.top().second;
    sa.pop();
    fa[f1] = f1;
    sz[f2] -= sz[f1];
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= n * 2; i++) {
    fa[i] = i;
    sz[i] = 1;
  }
  long long ans = k;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    if (c[u] == c[v]) {
      int f1 = fin(u);
      int f2 = fin(v);
      if (f1 == f2 && vis[c[u]] == 0) {
        ans--;
        vis[c[u]] = 1;
        continue;
      }
      merge(u, v + n);
      merge(v, u + n);
    } else {
      if (c[u] > c[v]) {
        swap(u, v);
      }
      ho.push_back({u, v, c[u], c[v]});
    }
  }
  ans = ans * (ans - 1) / 2;
  sort(ho.begin(), ho.end(), cmp);
  while (!sa.empty()) {
    sa.pop();
  }
  int r;
  for (int i = 0; i < ho.size(); i = r + 1) {
    clr();
    int c1 = ho[i].cu;
    int c2 = ho[i].cv;
    r = i;
    for (int j = i; j < ho.size(); j++) {
      if (ho[j].cu == c1 && ho[j].cv == c2) {
        r = j;
      } else {
        break;
      }
    }
    if (vis[c1] || vis[c2]) {
      continue;
    }
    int ok = 0, u, v;
    for (int j = i; j <= r; j++) {
      u = ho[j].u;
      v = ho[j].v;
      if (fin(u) == fin(v)) {
        ok = 1;
        break;
      } else {
        merge(u + n, v);
        merge(u, v + n);
      }
    }
    ans -= ok;
  }
  printf("%lld\n", ans);
}
