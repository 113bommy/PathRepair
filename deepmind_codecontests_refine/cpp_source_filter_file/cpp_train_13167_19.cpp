#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int maxl = 1e9 + 5;
const long long inf = 1e15;
int ui, vi, wi;
int S;
vector<int> isIn;
long long cost;
struct node {
  int v, w, number;
  node(int vv, int ww, int nn) { v = vv, w = ww, number = nn; }
};
vector<node> G[maxn];
long long d1[maxn];
int lastedge[maxn];
bool solved[maxn];
int weight[maxn];
void dijkstra() {
  fill(d1, d1 + maxn, inf);
  fill(lastedge, lastedge + maxn, 0);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  d1[S] = 0;
  q.push(pair<long long, int>(d1[S], S));
  while (!q.empty()) {
    pair<long long, int> cur = q.top();
    q.pop();
    long long d = cur.first;
    int u = cur.second;
    if (solved[u] == true) {
      continue;
    } else {
      if (u != S) {
        cost += weight[lastedge[u]];
        isIn.push_back(lastedge[u]);
      }
      solved[u] = true;
      for (int i = 0; i < G[u].size(); i++) {
        node &e = G[u][i];
        if (solved[e.v] == true) {
          continue;
        }
        long long td = d + e.w;
        if (d1[e.v] > td) {
          swap(td, d1[e.v]);
          lastedge[e.v] = e.number;
          q.push(pair<long long, int>(d1[e.v], e.v));
        } else if (d1[e.v] == td) {
          if (weight[e.number] < weight[lastedge[e.v]]) {
            lastedge[e.v] = e.number;
            q.push(pair<long long, int>(d1[e.v], e.v));
          }
        }
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(G, 0, sizeof(G));
  ;
  weight[0] = maxl;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &ui, &vi, &wi);
    G[ui].push_back(node(vi, wi, i));
    G[vi].push_back(node(ui, wi, i));
    weight[i] = wi;
  }
  scanf("%d", &S);
  dijkstra();
  printf("%d\n", cost);
  for (int i = 0; i < isIn.size(); i++) {
    printf("%d%c", isIn[i], (i == isIn.size() - 1) ? '\n' : ' ');
  }
  return 0;
}
