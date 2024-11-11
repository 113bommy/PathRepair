#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 1e3 + 5, M = 4e5 + 5;
int n, m;
int head[N], Next[M], to[M], num[M], cnt = 1;
int dep[N];
int S, T;
void add(int x, int y, int z) {
  Next[++cnt] = head[x];
  head[x] = cnt;
  to[cnt] = y;
  num[cnt] = z;
  Next[++cnt] = head[y];
  head[y] = cnt;
  to[cnt] = x;
  num[cnt] = 0;
}
bool bfs() {
  memset(dep, 0, sizeof dep);
  dep[S] = 1;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = Next[i]) {
      int u = to[i];
      if (dep[u] || !num[i]) continue;
      dep[u] = dep[x] + 1;
      q.push(u);
    }
  }
  return dep[T] > 1;
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int rest = flow;
  for (int i = head[x]; i; i = Next[i]) {
    int u = to[i];
    if (dep[u] != dep[x] + 1 || !num[i]) continue;
    int temp = dfs(u, min(rest, num[i]));
    num[i] -= temp;
    num[i ^ 1] += temp;
    rest -= temp;
  }
  return flow - rest;
}
int Dinic() {
  int ans = 0;
  while (bfs()) {
    while (int temp = dfs(S, INF)) ans += temp;
  }
  return ans;
}
int a[20000 + 5], pri[20000 + 5], tot;
bool b[20000 + 5];
void shai() {
  int i, j;
  for (i = 2; i <= 2e2; i++) {
    if (!b[i]) pri[++tot] = i;
    for (j = 1; j <= tot && i * pri[j] <= 2e2; j++) {
      b[pri[j] * i] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
bool vis[N];
int tot1;
vector<int> v[N];
void dfs1(int x) {
  vis[x] = 1;
  v[tot1].push_back(x);
  for (int i = head[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == T || u == S) continue;
    if (num[i] ^ (a[x] & 1) == 1 && !vis[u]) {
      dfs1(u);
    }
  }
}
void print() {
  int x, i;
  for (x = 1; x <= n; x++) {
    for (i = head[x]; i; i = Next[i])
      cout << x << " " << to[i] << " " << num[i] << "\n";
    cout << "\n";
  }
}
int main() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  shai();
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      if (!b[a[i] + a[j]]) {
        if (a[i] & 1) {
          add(i, j, 1);
        } else
          add(j, i, 1);
      }
    }
  for (i = 1; i <= n; i++) {
    if (a[i] & 1)
      add(0, i, 2);
    else
      add(i, n + 1, 2);
  }
  S = 0;
  T = n + 1;
  if (Dinic() != n) {
    cout << "Impossible" << endl;
    return 0;
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      tot1++;
      dfs1(i);
    }
  }
  cout << tot1 << endl;
  for (i = 1; i <= tot1; i++) {
    printf("%d ", v[i].size());
    for (j = 0; j < v[i].size(); j++) printf("%d ", v[i][j]);
    printf("\n");
  }
}
