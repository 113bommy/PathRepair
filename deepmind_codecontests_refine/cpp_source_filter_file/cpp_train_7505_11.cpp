#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > S;
int N, Q;
int cnt, Left[200005], Right[200005], Level[200005];
vector<int> G[200005];
int Father[22][200005];
int Arb[800005], Lazy[800005], Cnt[800005];
int Log[200005];
void precalcLog() {
  for (int i = 2; i <= N; i++) Log[i] = Log[i / 2] + 1;
}
void Read() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
}
void DFS(int node, int father) {
  Father[0][node] = father;
  Level[node] = Level[father] + 1;
  Left[node] = ++cnt;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i];
    if (neighb == father) continue;
    DFS(neighb, node);
  }
  Right[node] = cnt;
}
void precalcFather() {
  for (int i = 1; i <= Log[N]; i++)
    for (int j = 1; j <= N; j++) Father[i][j] = Father[i - 1][Father[i - 1][j]];
}
int F(int node, int dist) {
  while (dist > 0) {
    int k = Log[dist];
    node = Father[k][node];
    dist -= (1 << k);
  }
  return node;
}
void buildTree(int K, int L, int R) {
  if (L == R) {
    Arb[K] = 0;
    Cnt[K] = 1;
    return;
  }
  buildTree(K * 2, L, (L + R) / 2);
  buildTree(K * 2 + 1, (L + R) / 2 + 1, R);
  Cnt[K] = Cnt[K * 2] + Cnt[K * 2 + 1];
}
void propagate(int K, int L, int R) {
  if (L > R) return;
  if (Lazy[K] != 0) {
    Arb[K] += Lazy[K];
    if (L != R) {
      Lazy[K * 2] += Lazy[K];
      Lazy[K * 2 + 1] += Lazy[K];
    }
    Lazy[K] = 0;
  }
}
void update(int K, int L, int R, int x, int y, int val) {
  propagate(K, L, R);
  if (L > R || L > y || R < x) return;
  if (L >= x && R <= y) {
    Arb[K] += val;
    if (L != R) {
      Lazy[K * 2] += val;
      Lazy[K * 2 + 1] += val;
    }
    return;
  }
  update(K * 2, L, (L + R) / 2, x, y, val);
  update(K * 2 + 1, (L + R) / 2 + 1, R, x, y, val);
  if (Arb[K * 2] == Arb[K * 2 + 1]) {
    Cnt[K] = Cnt[K * 2] + Cnt[K * 2 + 1];
  }
  if (Arb[K * 2] < Arb[K * 2 + 1]) Cnt[K] = Cnt[K * 2 + 1];
  if (Arb[K * 2] > Arb[K * 2 + 1]) Cnt[K] = Cnt[K * 2];
  Arb[K] = max(Arb[K * 2], Arb[K * 2 + 1]);
}
void addEdge(int u, int v) {
  if (Level[u] > Level[v]) swap(u, v);
  int anc = F(v, Level[v] - Level[u] - 1);
  if (Left[u] <= Left[v] && Left[v] <= Right[u]) {
    update(1, 1, N, 1, N, 1);
    update(1, 1, N, Left[anc], Right[anc], -1);
    update(1, 1, N, Left[v], Right[v], 1);
  } else {
    update(1, 1, N, Left[u] + 1, Right[u], 1);
    update(1, 1, N, Left[v], Right[v], 1);
  }
}
void deleteEdge(int u, int v) {
  if (Level[u] > Level[v]) swap(u, v);
  int anc = F(v, Level[v] - Level[u] - 1);
  if (Left[u] <= Left[v] && Left[v] <= Right[u]) {
    update(1, 1, N, 1, N, -1);
    update(1, 1, N, Left[anc], Right[anc], 1);
    update(1, 1, N, Left[v], Right[v], -1);
  } else {
    update(1, 1, N, Left[u], Right[u], -1);
    update(1, 1, N, Left[v], Right[v], -1);
  }
}
void Solve() {
  for (int i = 1; i <= Q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    if (S.find(make_pair(u, v)) != S.end()) {
      deleteEdge(u, v);
      S.erase(make_pair(u, v));
    } else {
      addEdge(u, v);
      S.insert(make_pair(u, v));
    }
    printf("%d\n", (Arb[1] == S.size() ? Cnt[1] : 0));
  }
}
int main() {
  Read();
  DFS(1, 0);
  precalcLog();
  precalcFather();
  buildTree(1, 1, N);
  Solve();
  return 0;
}
