#include <bits/stdc++.h>
using namespace std;
int N, Q;
bool Leaf[500005];
vector<pair<int, int> > G[500005];
vector<pair<pair<int, int>, int> > Query[500005];
pair<int, int> L[500005];
long long Res[500005];
long long Dist[500005], Arb[500005 * 4], Lazy[500005 * 4];
void Read() {
  scanf("%d%d", &N, &Q);
  for (int i = 2; i <= N; i++) {
    int p, w;
    scanf("%d%d", &p, &w);
    G[p].push_back(make_pair(i, w));
  }
  for (int i = 1; i <= Q; i++) {
    int v, l, r;
    scanf("%d%d%d", &v, &l, &r);
    Query[v].push_back(make_pair(make_pair(l, r), i));
  }
}
void DFS(int node) {
  if (G[node].size() == 0) {
    L[node] = make_pair(node, node);
    Leaf[node] = true;
    return;
  }
  L[node].first = 1000000000;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, cost = G[node][i].second;
    Dist[neighb] = Dist[node] + cost;
    DFS(neighb);
    L[node].first = min(L[node].first, L[neighb].first);
    L[node].second = max(L[node].second, L[neighb].second);
  }
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
void rangeUpdate(int K, int L, int R, int x, int y, int val) {
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
  rangeUpdate(K * 2, L, (L + R) / 2, x, y, val);
  rangeUpdate(K * 2 + 1, (L + R) / 2 + 1, R, x, y, val);
  Arb[K] = min(Arb[K * 2], Arb[K * 2 + 1]);
}
void buildTree(int K, int L, int R) {
  if (L == R) {
    Arb[K] = Leaf[L] ? Dist[L] : 10000000000000000;
    return;
  }
  buildTree(K * 2, L, (L + R) / 2);
  buildTree(K * 2 + 1, (L + R) / 2 + 1, R);
  Arb[K] = min(Arb[K * 2], Arb[K * 2 + 1]);
}
long long query(int K, int L, int R, int x, int y) {
  propagate(K, L, R);
  if (L > R || L > y || R < x) return 10000000000000000;
  if (L >= x && R <= y) return Arb[K];
  return min(query(K * 2, L, (L + R) / 2, x, y),
             query(K * 2 + 1, (L + R) / 2 + 1, R, x, y));
}
void DFS2(int node) {
  for (int i = 0; i < Query[node].size(); i++) {
    int l = Query[node][i].first.first, r = Query[node][i].first.second,
        pos = Query[node][i].second;
    Res[pos] = query(1, 1, N, l, r);
  }
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, cost = G[node][i].second;
    pair<int, int> range = L[neighb];
    rangeUpdate(1, 1, N, range.first, range.second, -cost);
    if (range.first > 1) rangeUpdate(1, 1, N, 1, range.first - 1, cost);
    if (range.second < N) rangeUpdate(1, 1, N, range.second + 1, N, cost);
    DFS2(neighb);
    rangeUpdate(1, 1, N, range.first, range.second, cost);
    if (range.first > 1) rangeUpdate(1, 1, N, 1, range.first - 1, -cost);
    if (range.second < N) rangeUpdate(1, 1, N, range.second + 1, N, -cost);
  }
}
void Print() {
  for (int i = 1; i <= Q; i++) printf("%I64d\n", Res[i]);
}
int main() {
  Read();
  DFS(1);
  buildTree(1, 1, N);
  DFS2(1);
  Print();
  return 0;
}
