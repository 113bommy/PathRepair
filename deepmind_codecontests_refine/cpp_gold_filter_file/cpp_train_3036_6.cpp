#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 1000000001;
int n, m, pa[101], sz[101];
vector<pii> adj[101];
int dist[1 << 17][71], vis[1 << 17][71];
struct MM {
  map<int, int> vton, ntov;
  void add(int cur) {
    vton[cur] = ((int)(vton).size()) - 1;
    ntov[((int)(ntov).size())] = cur;
  }
  int enc(int cur) { return vton[cur]; }
  int dec(int cur) { return ntov[cur]; }
} mm;
int find(int cur) { return cur == pa[cur] ? cur : pa[cur] = find(pa[cur]); }
void merge(int u, int v) {
  u = find(u);
  v = find(v);
  sz[u] += sz[v];
  pa[v] = u;
}
int get_st(int cur) {
  cur = find(cur);
  if (sz[cur] < 4)
    return 0;
  else
    return 1 << mm.enc(cur);
}
int main() {
  int a, b;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= n; i++) pa[i] = i, sz[i] = 1;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back(pii(w, v));
    adj[v].push_back(pii(w, u));
    if (w == a) merge(u, v);
  }
  for (int i = 1; i <= n; i++)
    if (find(i) == i && sz[i] > 3) {
      mm.add(i);
    }
  for (int i = 0; i < 1 << ((int)(mm.vton).size()); i++)
    for (int j = 1; j <= n; j++) dist[i][j] = INF;
  struct td {
    int d, s, cur;
    td() {}
    td(int d, int s, int cur) : d(d), s(s), cur(cur) {}
    bool operator<(const td &rhs) const { return d > rhs.d; }
  };
  priority_queue<td> que;
  que.push(td(0, get_st(1), 1));
  dist[get_st(1)][1] = 0;
  while (!que.empty()) {
    int s = que.top().s, cur = que.top().cur;
    que.pop();
    if (vis[s][cur]) continue;
    vis[s][cur] = 1;
    for (auto &it : adj[cur]) {
      if (it.first == a) {
        if (!vis[s][it.second] &&
            dist[s][it.second] > dist[s][cur] + it.first) {
          dist[s][it.second] = dist[s][cur] + it.first;
          que.push(td(dist[s][it.second], s, it.second));
        }
      } else if (!(s & get_st(it.second)) && find(cur) != find(it.second)) {
        int ns = s | get_st(it.second);
        if (!vis[ns][it.second] &&
            dist[ns][it.second] > dist[s][cur] + it.first) {
          dist[ns][it.second] = dist[s][cur] + it.first;
          que.push(td(dist[ns][it.second], ns, it.second));
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int mx = INF;
    for (int j = 0; j < 1 << (((int)(mm.vton).size())); j++)
      mx = min(mx, dist[j][i]);
    printf("%d ", mx);
  }
  return 0;
}
