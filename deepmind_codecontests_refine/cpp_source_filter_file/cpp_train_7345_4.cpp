#include <bits/stdc++.h>
using namespace std;
struct O {
  long long c, k, p;
};
struct O1 {
  long long t, p, k;
  bool operator<(const O1& o) const { return t < o.t; }
};
const int MXN = 5001;
int N, M, W, Q;
vector<int> edges[MXN] = {};
vector<O> stores;
int dist[MXN] = {};
void bfs(int s) {
  for (int x = 0; x < N + 1; x++) dist[x] = 1e9;
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : edges[u])
      if (dist[v] == (int)1e9) dist[v] = dist[u] + 1, q.push(v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int x = 0; x < M; x++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  cin >> W;
  stores.resize(W);
  for (int x = 0; x < W; x++) cin >> stores[x].c >> stores[x].k >> stores[x].p;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    long long g, r, a;
    cin >> g >> r >> a;
    bfs(g);
    vector<O1> A(W);
    for (int x = 0; x < W; x++) {
      A[x].t = dist[stores[x].c];
      A[x].p = stores[x].p;
      A[x].k = stores[x].k;
    }
    sort((A).begin(), (A).end());
    int low = 0, high = N, mid, ans = N + 1;
    while (low <= high) {
      mid = (low + high) / 2;
      long long tmpA = a, tmpR = 0;
      for (int x = 0; x < W; x++)
        if (A[x].t <= mid) {
          long long buy = min(A[x].k, tmpA / A[x].p);
          tmpA -= buy * A[x].p;
          tmpR += buy;
        }
      if (tmpR >= r) {
        ans = min(mid, ans);
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << (ans == N + 1 ? -1 : ans) << "\n";
  }
}
