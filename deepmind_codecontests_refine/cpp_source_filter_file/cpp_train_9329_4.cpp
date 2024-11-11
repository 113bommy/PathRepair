#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-9;
const int inf = 1 << 30;
namespace MaxFlowMinCost {
int pos, Index[100010], In, Fin, NN;
int Phi[100010];
struct edges {
  int nod, newn, cap, next;
  int cost;
  edges(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    nod = a, newn = b, cap = c, cost = d, next = e;
  }
} G[1000005];
void initialize(int cnod, int source, int sink) {
  In = source, Fin = sink, NN = cnod;
  memset(Index, -1, sizeof(Index));
  pos = 0;
}
void insertar(int a, int b, int c, int d) {
  G[pos] = edges(a, b, c, d, Index[a]);
  Index[a] = pos++;
  G[pos] = edges(b, a, 0, -d, Index[b]);
  Index[b] = pos++;
}
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    Qp;
int F[100010], parent[100010];
int dist[100010];
pair<int, int> Max_Flow_Min_Cost() {
  int FlowF = 0;
  int CostF = 0;
  int nod, newn, flow;
  int newc, cost;
  memset(Phi, 0, sizeof(Phi));
  for (;;) {
    fill(F, F + 1 + NN, 0);
    fill(dist, dist + 1 + NN, 1e9);
    F[In] = 1e9, dist[In] = 0;
    Qp.push(pair<int, int>(0, In));
    while (!Qp.empty()) {
      nod = Qp.top().second, cost = Qp.top().first;
      Qp.pop();
      flow = F[nod];
      for (int i = Index[nod]; i != -1; i = G[i].next) {
        newn = G[i].newn;
        newc = cost + G[i].cost + Phi[nod] - Phi[newn];
        if (G[i].cap > 0 && dist[newn] > newc) {
          dist[newn] = newc;
          F[newn] = min(flow, G[i].cap);
          parent[newn] = i;
          Qp.push(pair<int, int>(newc, newn));
        }
      }
    }
    if (F[Fin] <= 0) break;
    CostF += ((dist[Fin] + Phi[Fin]) * F[Fin]);
    FlowF += F[Fin];
    for (int i = In; i <= Fin; i++)
      if (F[i]) Phi[i] += dist[i];
    nod = Fin;
    while (nod != In) {
      G[parent[nod]].cap -= F[Fin];
      G[parent[nod] ^ 1].cap += F[Fin];
      nod = G[parent[nod]].nod;
    }
  }
  return pair<int, int>(CostF, FlowF);
}
};  // namespace MaxFlowMinCost
using namespace MaxFlowMinCost;
int lo[55], hi[55], n, q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) lo[i] = 1, hi[i] = n;
  int t, a, b, v;
  for (int i = 1; i <= q; i++) {
    cin >> t >> a >> b >> v;
    if (t == 1)
      for (int j = a; j <= b; j++) lo[j] = max(lo[j], v);
    else
      for (int j = a; j <= b; j++) hi[j] = min(hi[j], v);
  }
  for (int i = 1; i <= n; i++)
    if (lo[i] > hi[i]) {
      cout << -1 << '\n';
      exit(0);
    }
  initialize(2 * n * n, 0, n + 1 + n * n);
  for (int i = 1; i <= n; i++) insertar(0, i, 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = lo[i]; j <= hi[i]; j++) insertar(i, n + j, 1, 0);
  int c = 2 * n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      insertar(n + i, ++c, 1, 2 * j - 1);
      insertar(c, n + n * n + 1, 1, 0);
    }
  pair<int, int> sol = Max_Flow_Min_Cost();
  cout << sol.first << '\n';
  return 0;
}
