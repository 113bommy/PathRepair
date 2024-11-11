#include <bits/stdc++.h>
using namespace std;
vector<long long int> Tree[200005];
long long int SP[200005][30], L[200005], P[200005], vis[200005], tme = 1;
long long int N;
long long int in[200005], timereverse[200005], Smx[200005 * 4], Smn[200005 * 4],
    que;
void makeLCA(long long int source) {
  queue<long long int> q;
  L[source] = 0;
  q.push(source);
  vis[source] = 1;
  while (!q.empty()) {
    long long int u = q.front();
    q.pop();
    for (int i = 0; i < Tree[u].size(); i++) {
      long long int v = Tree[u][i];
      if (!vis[v]) {
        L[v] = L[u] + 1;
        vis[v] = 1;
        P[v] = u;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= N; i++) SP[i][0] = P[i];
  for (int j = 1; j < 29; j++) {
    for (int i = 1; i <= N; i++) {
      SP[i][j] = SP[SP[i][j - 1]][j - 1];
    }
  }
  return;
}
long long int LCA(long long int a, long long int b) {
  if (L[a] > L[b]) swap(a, b);
  for (int i = 28; i >= 0; i--) {
    if (L[b] - (1 << i) >= L[a]) {
      b = SP[b][i];
    }
  }
  if (b == a) return a;
  for (int i = 28; i >= 0; i--) {
    if (SP[a][i] != SP[b][i]) {
      a = SP[a][i];
      b = SP[b][i];
    }
  }
  return P[a];
}
void dfs(long long int u) {
  vis[u] = 1;
  in[u] = tme;
  timereverse[tme] = u;
  tme++;
  for (int i = 0; i < Tree[u].size(); i++) {
    long long int v = Tree[u][i];
    if (vis[v] == 0) {
      dfs(v);
    }
  }
  return;
}
void build(long long int node, long long int b, long long int e) {
  if (b == e) {
    Smx[node] = in[b];
    Smn[node] = in[b];
    return;
  }
  long long int mid = (b + e) / 2;
  build(node * 2, b, mid);
  build(node * 2 + 1, mid + 1, e);
  Smx[node] = max(Smx[node * 2], Smx[node * 2 + 1]);
  Smn[node] = min(Smn[node * 2], Smn[node * 2 + 1]);
  return;
}
pair<long long int, long long int> querySeg(long long int node, long long int b,
                                            long long int e, long long int x,
                                            long long int y) {
  if (b > y || e < x) return {-1, 200005};
  if (b >= x && e <= y) return {Smx[node], Smn[node]};
  long long int mid = (b + e) / 2;
  pair<long long int, long long int> p1, p2;
  p1 = querySeg(node * 2, b, mid, x, y);
  p2 = querySeg(node * 2 + 1, mid + 1, e, x, y);
  return {max(p1.first, p2.first), min(p1.second, p2.second)};
}
long long int solve(long long int l, long long int r, long long int u) {
  if (u == l) {
    pair<long long int, long long int> p = querySeg(1, 1, N, l + 1, r);
    return L[LCA(timereverse[p.first], timereverse[p.second])];
  } else if (u == r) {
    pair<long long int, long long int> p = querySeg(1, 1, N, l, r - 1);
    return L[LCA(timereverse[p.first], timereverse[p.second])];
  } else {
    pair<long long int, long long int> p1, p2;
    p1 = querySeg(1, 1, N, l, u - 1);
    p2 = querySeg(1, 1, N, u + 1, r);
    long long int a = LCA(timereverse[p1.first], timereverse[p1.second]);
    long long int b = LCA(timereverse[p2.first], timereverse[p2.second]);
    return L[LCA(a, b)];
  }
}
int main() {
  cin >> N >> que;
  for (int i = 2; i <= N; i++) {
    long long int a = i, b;
    cin >> b;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
  }
  makeLCA(1);
  memset(vis, 0, sizeof vis);
  dfs(1);
  build(1, 1, N);
  while (que--) {
    long long int l, r;
    long long int ans, lv = -1;
    pair<long long int, long long int> p1;
    scanf("%I64d %I64d", &l, &r);
    p1 = querySeg(1, 1, N, l, r);
    long long int a = timereverse[p1.first], b = timereverse[p1.second];
    ans = l, lv = L[LCA(a, b)];
    long long int lv1 = solve(l, r, a), lv2 = solve(l, r, b);
    if (lv1 > lv) {
      lv = lv1;
      ans = a;
    }
    if (lv2 > lv) {
      lv = lv2;
      ans = b;
    }
    printf("%I64d %I64d\n", ans, lv);
  }
  return 0;
}
