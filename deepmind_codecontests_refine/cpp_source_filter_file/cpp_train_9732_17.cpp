#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int SP[MAXN], n, m, prevs[MAXN];
vector<pair<int, pair<int, int> > > adj[MAXN];
struct node {
  int id, cost, working, prevs;
  node(int ii, int cc, bool Working, int previous = -1) {
    id = ii, cost = cc, working = Working, prevs = previous;
  }
  bool operator<(const node& nn) const {
    if (cost > nn.cost)
      return 1;
    else if (nn.cost > cost)
      return 0;
    else
      return working < nn.working;
  }
};
void dijkstra(int src) {
  priority_queue<node> q;
  q.push(node(src, 0, 0));
  memset(SP, -1, sizeof SP);
  while (!q.empty()) {
    node cur = q.top();
    q.pop();
    if (SP[cur.id] != -1) continue;
    SP[cur.id] = cur.cost;
    prevs[cur.id] = cur.prevs;
    for (auto nxt : adj[cur.id])
      if (SP[nxt.first] == -1)
        q.push(node(nxt.first, cur.cost + nxt.second.first,
                    nxt.second.second + cur.working, cur.id));
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  cin >> n >> m;
  map<pair<int, int>, int> roads;
  for (int i = 0, fr, to, working; i < m; i++) {
    cin >> fr >> to >> working;
    adj[fr].push_back({to, {1, working}});
    adj[to].push_back({fr, {1, working}});
    roads[{fr, to}] = working;
    roads[{to, fr}] = working;
  }
  dijkstra(1);
  vector<int> path = {n};
  int cur = n;
  while (prevs[cur] != -1) {
    cur = prevs[cur];
    path.push_back(cur);
  }
  vector<string> ans;
  for (int i = path.size() - 1; i > 0; i--) {
    if (!roads[{path[i], path[i - 1]}])
      ans.push_back(to_string(path[i]) + ' ' + to_string(path[i - 1]) + " 1\n");
    roads[{path[i], path[i - 1]}] = 2;
    roads[{path[i - 1], path[i]}] = 2;
  }
  for (auto i : roads) {
    if (i.second != 2 && roads[{i.first.first, i.first.second}])
      ans.push_back(to_string(i.first.first) + ' ' + to_string(i.first.second) +
                    " 0\n");
    roads[{i.first.first, i.first.second}] = 2;
    roads[{i.first.second, i.first.first}] = 2;
  }
  cout << ans.size() << endl;
  for (auto i : ans) cout << i;
  return 0;
}
