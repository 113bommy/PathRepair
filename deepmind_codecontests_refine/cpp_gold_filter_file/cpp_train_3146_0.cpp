#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
struct node {
  int a, b, c;
  node() {}
  node(int a, int b, int c) : a(a), b(b), c(c) {}
} sa[N];
int n;
int in[N];
bool vis[N], used[N];
vector<int> V[N], G, A, P[N], E[N];
void init() {
  for (int i = 1; i <= n; i++) {
    in[i] = 0;
    vis[i] = used[i] = false;
    V[i].clear();
    P[i].clear();
    E[i].clear();
  }
  G.clear();
  A.clear();
}
void insert(int a, int b) {
  P[a].push_back(b);
  P[b].push_back(a);
}
void dfs(int u) {
  used[u] = true;
  A.push_back(u);
  for (int v : E[u]) {
    if (used[v]) continue;
    dfs(v);
  }
}
int main() {
  int T, a, b, c;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n - 2; i++) {
      scanf("%d%d%d", &a, &b, &c);
      sa[i] = node(a, b, c);
      in[a]++;
      in[b]++;
      in[c]++;
      V[a].push_back(i);
      V[b].push_back(i);
      V[c].push_back(i);
      insert(a, b);
      insert(b, c);
      insert(c, a);
    }
    for (int i = 1; i <= n; i++) {
      sort(P[i].begin(), P[i].end());
      for (int l = 0, r; l < P[i].size(); l = r + 1) {
        r = l;
        while (r + 1 < P[i].size() && P[i][l] == P[i][r + 1]) r++;
        if (l == r) E[i].push_back(P[i][l]);
      }
    }
    dfs(1);
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
      if (in[i] == 1) Q.push(i);
    }
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (in[u] < 1) continue;
      for (int i = 0; i < V[u].size(); i++) {
        int v = V[u][i];
        if (vis[v]) continue;
        G.push_back(v);
        vis[v] = true;
        in[sa[v].a]--;
        in[sa[v].b]--;
        in[sa[v].c]--;
        if (in[sa[v].a] == 1) Q.push(sa[v].a);
        if (in[sa[v].b] == 1) Q.push(sa[v].b);
        if (in[sa[v].c] == 1) Q.push(sa[v].c);
        break;
      }
    }
    for (int i = 0; i < A.size(); i++) {
      printf("%d%c", A[i], i == A.size() - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < G.size(); i++) {
      printf("%d%c", G[i], i == G.size() - 1 ? '\n' : ' ');
    }
    init();
  }
  return 0;
}
