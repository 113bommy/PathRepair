#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
vector<pair<int, pair<int, int> > > A[N];
long long d[N];
int E[N];
vector<int> G;
long long maxd;
long long dij(int u) {
  priority_queue<pair<pair<long long, long long>, pair<int, int> >,
                 vector<pair<pair<long long, long long>, pair<int, int> > >,
                 greater<pair<pair<long long, long long>, pair<int, int> > > >
      PQ;
  PQ.push(make_pair(make_pair(0, 0), make_pair(u, 0)));
  long long sum = 0;
  while (!PQ.empty()) {
    pair<pair<long long, long long>, pair<int, int> > po = PQ.top();
    PQ.pop();
    long long dist = po.first.first;
    int v = po.second.first;
    int ed = po.second.second;
    long long sh = po.first.second;
    if (d[v] > dist) {
      d[v] = dist;
      sum += -sh;
      G.push_back(ed);
      for (int i = 0; i < A[v].size(); i++) {
        if (dist + A[v][i].second.first < d[A[v][i].first]) {
          PQ.push(make_pair(
              make_pair(dist + A[v][i].second.first, -A[v][i].second.first),
              make_pair(A[v][i].first, A[v][i].second.second)));
        }
      }
    }
  }
  return sum;
}
const long long INF = 1e18;
inline int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int ret = 0;
  while (c >= '0' && c <= '9') {
    ret = (ret << 3) + (ret << 1) + c - 48;
    c = getchar();
  }
  return ret;
}
int main() {
  int n, m;
  n = inp();
  m = inp();
  for (int i = 0; i < m; i++) {
    int u, v, w;
    u = inp();
    v = inp();
    w = inp();
    u--;
    v--;
    A[u].push_back(make_pair(v, make_pair(w, i + 1)));
    A[v].push_back(make_pair(u, make_pair(w, i + 1)));
    E[i + 1] = w;
  }
  int u = inp() - 1;
  for (int i = 0; i < n; i++) d[i] = INF;
  maxd = -1;
  long long ans = dij(u);
  int y = (int)G.size();
  printf("%I64d\n", ans);
  for (int i = 1; i < y; i++) {
    printf("%d ", G[i]);
  }
  printf("\n");
}
