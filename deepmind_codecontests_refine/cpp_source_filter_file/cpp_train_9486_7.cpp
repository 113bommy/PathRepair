#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
struct Edge {
  long long to, w, id;
  Edge(long long to_ = 0, long long w_ = 0, long long id_ = 0)
      : to(to_), w(w_), id(id_) {}
};
long long n, m, k, dis[MAXN], from[MAXN], fromid[MAXN];
vector<Edge> edg[MAXN];
priority_queue<pair<long long, long long> > pq;
inline void dijkstra(int s) {
  memset(dis, -1, sizeof(dis));
  pq.push(pair<long long, long long>(dis[s] = 0, s));
  while (pq.size()) {
    pair<long long, long long> now = pq.top();
    pq.pop();
    long long nowdis = -now.first, nowpos = now.second;
    if (nowdis > dis[nowpos]) continue;
    for (auto vec : edg[nowpos])
      if (dis[vec.to] == -1 || dis[vec.to] > nowdis + vec.w) {
        dis[vec.to] = nowdis + vec.w;
        from[vec.to] = nowpos;
        fromid[vec.to] = vec.id;
        pq.push(pair<long long, long long>(-dis[vec.to], vec.to));
      }
  }
}
inline void addEdge(int u, int v, int w, int id) {
  edg[u].push_back(Edge(v, w, id));
  edg[v].push_back(Edge(u, w, id));
}
inline void pre() {
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= n; ++i) cin >> u >> v >> w, addEdge(u, v, w, i);
  dijkstra(1);
}
vector<int> ans;
vector<pair<long long, long long> > nedg[MAXN];
inline void bfs() {
  for (int i = 2; i <= n; ++i)
    nedg[from[i]].push_back(pair<long long, long long>(i, fromid[i]));
  queue<int> q;
  q.push(1);
  while (q.size() && ans.size() < k) {
    int pos = q.front();
    q.pop();
    for (auto vec : nedg[pos])
      if (ans.size() < k) {
        ans.push_back(vec.second);
        q.push(vec.first);
      }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  bfs();
  cout << ans.size() << "\n";
  for (auto v : ans) cout << v << " ";
  cout.flush();
  return 0;
}
