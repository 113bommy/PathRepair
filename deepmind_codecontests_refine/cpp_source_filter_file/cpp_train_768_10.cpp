#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > E[100010];
int n, m, a[100010], A, vis[100010], x, y, z, root, dis[100010], D[100010], tot,
    pre[100010], L[100010], Bl[100010];
int ans[100010], S[100010];
pair<int, int> Fr[100010];
bool exist[100010], is[100010];
int F[100010];
queue<int> h;
map<int, int> Le, Ri;
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
void dfs(int u) {
  vis[u] = A;
  int s = 0;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    s++;
    if (vis[v] == A) continue;
    dfs(v);
    if (!exist[v]) s--;
  }
  exist[u] = (s > 1) || is[u];
}
int Far(int u) {
  vis[u] = ++A;
  dis[u] = pre[u] = 0;
  h.push(u);
  pair<int, int> Max = make_pair(0, u);
  while (h.size()) {
    int u = h.front();
    h.pop();
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i].first, l = E[u][i].second;
      if (vis[v] != A && exist[v]) {
        vis[v] = A;
        dis[v] = dis[u] + l;
        pre[v] = u;
        Max = max(Max, make_pair(dis[v], v));
        h.push(v);
      }
    }
  }
  return Max.second;
}
void Find(int u) {
  u = Far(u);
  int far = Far(u);
  for (; far; far = pre[far]) D[++tot] = far, L[tot] = dis[far];
}
void Dfs(int u, int st) {
  vis[u] = A;
  Bl[u] = st;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    if (vis[v] != A && exist[v]) dis[v] = dis[u] + E[u][i].second, Dfs(v, st);
  }
}
void Add(int l, int r) {
  ans[l]++;
  ans[r]++;
  if (Bl[l] > Bl[r]) swap(l, r);
  S[Bl[l]]++;
  S[Bl[r] + 1]--;
}
void DFS(int u) {
  vis[u] = A;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    if (vis[v] != A) DFS(v), ans[u] += ans[v];
  }
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(a[i]);
    is[a[i]] = 1;
  }
  for (int i = 1; i < n; i++) {
    read(x);
    read(y);
    read(z);
    E[x].push_back(make_pair(y, z));
    E[y].push_back(make_pair(x, z));
  }
  A++;
  dfs(1);
  root = a[1];
  Find(root);
  A++;
  for (int i = 1; i <= tot; i++) vis[D[i]] = A;
  for (int i = 1; i <= tot; i++) dis[D[i]] = 0, Dfs(D[i], i);
  for (int i = 1; i <= tot; i++) F[i] = max(L[i], L[1] - L[i]);
  for (int i = 1; i <= m; i++) {
    int x = Bl[a[i]], u = a[i], t;
    Fr[x] = max(Fr[x], make_pair(dis[u], u));
    if (L[x] >= L[1] - L[x]) {
      t = max(Le[L[x] + dis[u]], x);
      Le[L[x] + dis[u]] = t;
    }
    if (L[x] <= L[1] - L[x]) {
      t = Ri[-L[x] + dis[u]];
      Ri[-L[x] + dis[u]] = (t == 0) ? x : min(t, x);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x = Bl[a[i]], u = a[i], t;
    if (L[x] > L[1] - L[x]) {
      t = Ri[F[x] - L[x]];
      Add(u, Fr[t].second);
    } else if (L[x] < L[1] - L[x]) {
      t = Le[F[x] + L[x]];
      Add(u, Fr[t].second);
    } else
      Add(u, D[x]);
  }
  A++;
  for (int i = 1; i <= tot; i++) vis[D[i]] = A;
  for (int i = 1; i <= tot; i++) DFS(D[i]);
  for (int i = 1; i <= tot; i++) S[i] = S[i - 1] + S[i];
  for (int i = 1; i <= tot; i++) ans[D[i]] = S[i];
  int Max = 0, Sum = 0;
  for (int i = 1; i <= n; i++)
    if (!is[i]) {
      if (Max < ans[i])
        Max = ans[i], Sum = 1;
      else if (Max == ans[i])
        Sum++;
    }
  printf("%d %d\n", Max, Sum);
  return 0;
}
