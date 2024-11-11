#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxm = 4e5 + 10;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const double eps = 1e-5;
struct edge {
  long long to, dis, next;
} e[maxn << 1];
long long head[maxn], dis[maxn], cnt;
bool vis[maxn];
int pre[maxn];
int n, m, s;
map<pair<long long, long long>, long long> mp;
map<long long, long long> m1;
inline void add_edge(long long u, long long v, long long d) {
  cnt++;
  e[cnt].dis = d;
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
struct node {
  long long dis, pos;
  bool operator<(const node &x) const { return x.dis < dis; }
};
priority_queue<node> q;
inline void Dijkstra() {
  q.push(node{0, s});
  fill(dis + 1, dis + 1 + n, inf);
  dis[s] = 0;
  while (!q.empty()) {
    node temp = q.top();
    q.pop();
    int x = temp.pos, d = temp.dis;
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next) {
      long long y = e[i].to;
      if (dis[y] >= dis[x] + e[i].dis) {
        dis[y] = dis[x] + e[i].dis;
        pre[y] = x;
        q.push(node{-dis[y], y});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    long long u, v, d;
    cin >> u >> v >> d;
    add_edge(u, v, d);
    add_edge(v, u, d);
    mp[make_pair(u, v)] = i;
    mp[make_pair(v, u)] = i;
    m1[i] = d;
  }
  cin >> s;
  Dijkstra();
  long long ans = 0;
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    ans += m1[mp[make_pair(pre[i], i)]];
    if (i != s) res.push_back(mp[make_pair(pre[i], i)]);
  }
  cout << ans << endl;
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  return ~~(0 - 0);
}
