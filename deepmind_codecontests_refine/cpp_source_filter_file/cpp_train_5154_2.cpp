#include <bits/stdc++.h>
using namespace std;
const int MX = 100005, lg = 17;
int n, m, Q, L[MX], sp[lg + 1][MX];
vector<int> G[MX], V[lg + 1][MX];
void bfs() {
  queue<int> q;
  q.push(1), L[1] = 1, sp[0][1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : G[u])
      if (!sp[0][v]) {
        q.push(v), L[v] = L[u] + 1, sp[0][v] = u;
      }
  }
  sp[0][1] = 0;
}
void marge(vector<int>& v1, vector<int>& v2, vector<int>& v) {
  v = v1;
  v.insert(v.end(), v2.begin(), v2.end());
  sort(v.begin(), v.end());
  while (v.size() >= 10) {
    v.pop_back();
  }
}
void build_sptbl() {
  for (int i = 1; i <= lg; i++)
    for (int j = 1; j <= n; j++) {
      marge(V[i - 1][j], V[i - 1][sp[i - 1][j]], V[i][j]);
      sp[i][j] = sp[i - 1][sp[i - 1][j]];
    }
}
vector<int> query(int u, int v) {
  vector<int> ret;
  if (L[u] < L[v]) swap(u, v);
  for (int i = lg; i >= 0; i--) {
    if (L[sp[i][u]] >= L[v]) {
      marge(ret, V[i][u], ret);
      u = sp[i][u];
    }
  }
  for (int i = lg; i >= 0; i--) {
    if (sp[i][u] != sp[i][v]) {
      marge(ret, V[i][u], ret);
      marge(ret, V[i][v], ret);
      u = sp[i][u], v = sp[i][v];
    }
  }
  if (u != v) {
    marge(ret, V[0][u], ret);
    marge(ret, V[0][v], ret);
    u = sp[0][u], v = sp[0][v];
  }
  marge(ret, V[0][u], ret);
  return ret;
}
int main() {
  scanf("%d %d %d", &n, &m, &Q);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1, a; i <= m; i++) {
    scanf("%d", &a);
    V[0][a].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    vector<int> dmy;
    marge(V[0][i], dmy, V[0][i]);
  }
  bfs();
  build_sptbl();
  while (Q--) {
    int u, v, a;
    scanf("%d %d %d", &u, &v, &a);
    vector<int> ans = query(u, v);
    int sz = min(a, (int)ans.size());
    printf("%d", sz);
    for (int i = 0; i < sz; i++) {
      printf(" %d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
