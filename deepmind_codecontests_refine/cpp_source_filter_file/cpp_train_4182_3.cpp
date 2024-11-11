#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > edgeNos(200001);
vector<vector<pair<long long, int> > > V(200001);
int u[200001], v[200001], edgeXors[200001], edgeWeights[200001],
    parentEdge[200001], edgePathNumber[200001], l[200001], r[200001];
long long distanceS[200001], distanceT[200001], a[200001], b[200001];
const long long inf = 1E18;
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    Q;
void Dijkstra(int n, int s, long long d[]) {
  for (int i = 1; i <= n; ++i) {
    d[i] = inf;
    parentEdge[i] = 0;
  }
  d[s] = 0;
  Q.push(make_pair(0ll, s));
  while (!Q.empty()) {
    long long di;
    int i;
    tie(di, i) = Q.top();
    Q.pop();
    if (di != d[i]) {
      continue;
    }
    for (int edgeNo : edgeNos[i]) {
      int j = edgeXors[edgeNo] ^ i;
      long long dj = di + edgeWeights[edgeNo];
      if (dj < d[j]) {
        parentEdge[j] = edgeNo;
        d[j] = dj;
        Q.push(make_pair(dj, j));
      }
    }
  }
}
void InitialiseLR(int n) {
  for (int i = 1, k = 1;; ++k) {
    l[i] = k, r[i] = k;
    if (i == n) {
      break;
    }
    edgePathNumber[parentEdge[i]] = k;
    i ^= edgeXors[parentEdge[i]];
  }
}
int Fill(int i, int parent[]) {
  if (parent[i]) {
    return parent[i];
  }
  if (parentEdge[i] == 0) {
    return 0;
  }
  return parent[i] = Fill(i ^ edgeXors[parentEdge[i]], parent);
}
void FillL(int n) {
  for (int i = 1; i <= n; ++i) {
    l[i] = Fill(i, l);
  }
}
void FillR(int n) {
  for (int i = 1; i <= n; ++i) {
    r[i] = Fill(i, r);
  }
}
void AddRelax(int i, int j, int edgeNo) {
  if (l[i] >= r[j]) {
    return;
  }
  long long x = distanceS[i] + edgeWeights[edgeNo] + distanceT[j];
  V[l[i]].push_back(make_pair(x, j - 1));
}
void PreProcess(int n, int m) {
  Dijkstra(n, n, distanceT);
  InitialiseLR(n);
  FillR(n);
  Dijkstra(n, 1, distanceS);
  FillL(n);
  for (int edgeNo = 1; edgeNo <= m; ++edgeNo) {
    if (edgePathNumber[edgeNo]) {
      continue;
    }
    int i = u[edgeNo], j = v[edgeNo];
    b[edgeNo] = min(distanceS[i] + distanceT[j], distanceS[j] + distanceT[i]);
    AddRelax(i, j, edgeNo);
    AddRelax(j, i, edgeNo);
  }
  Q.push(make_pair(inf, n + 1));
  for (int i = 1; i <= n; ++i) {
    for (auto p : V[i]) {
      Q.push(p);
    }
    while (Q.top().second < i) {
      Q.pop();
    }
    a[i] = Q.top().first;
  }
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int x = 1; x <= m; ++x) {
    int i, j;
    scanf("%d%d%d", &i, &j, &edgeWeights[x]);
    u[x] = i, v[x] = j;
    edgeXors[x] = i ^ j;
    edgeNos[i].push_back(x);
    edgeNos[j].push_back(x);
  }
  PreProcess(n, m);
  while (q--) {
    int t, x;
    scanf("%d%d", &t, &x);
    long long ans = distanceS[n];
    if (edgePathNumber[t] == 0) {
      ans = min(ans, x + b[t]);
    } else {
      ans += (x - edgeWeights[t]);
      if (x > edgeWeights[t]) {
        ans = min(ans, a[edgePathNumber[t]]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
