#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pLL = pair<ll, ll>;
const int N = 5e3 + 10, INF = 0x3f3f3f3f;
int n, m, w, q;
vector<vector<int>> G;
vector<vector<pLL>> trade;
struct BFS {
  int dis[N];
  int ord[N];
  void gao(int s) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    queue<int> que;
    que.push(s);
    *ord = 0;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      ord[++*ord] = u;
      for (auto &v : G[u]) {
        if (dis[v] > dis[u] + 1) {
          dis[v] = dis[u] + 1;
          que.push(v);
        }
      }
    }
  }
  int run(ll r, ll a) {
    priority_queue<pLL, vector<pLL>, less<pLL>> pq;
    ll tot = 0, fee = 0;
    for (int i = 1; i <= *ord; ++i) {
      for (auto it : trade[ord[i]]) {
        pLL tmp = pLL(it.second, it.first);
        if (tot < r) {
          if (tmp.second > r - tot) {
            ll need = r - tot;
            tot += need;
            fee += need * tmp.first;
            pq.push(pLL(tmp.first, need));
            tmp.second -= need;
          } else {
            tot += tmp.second;
            fee += tmp.first * tmp.second;
            pq.push(tmp);
            tmp.second = 0;
          }
        }
        if (tot == r && tmp.second > 0) {
          while (!pq.empty() && pq.top().first > tmp.first && tmp.second > 0) {
            pLL top = pq.top();
            pq.pop();
            if (tmp.second > top.second) {
              fee -= top.second * top.first;
              tmp.second -= top.second;
              fee += top.second * tmp.first;
              pq.push(pLL(tmp.first, top.second));
            } else {
              fee -= tmp.second * top.first;
              top.second -= tmp.second;
              pq.push(top);
              pq.push(tmp);
              fee += tmp.second * tmp.first;
              tmp.second = 0;
            }
          }
        }
      }
      if (tot >= r && fee <= a) return dis[ord[i]];
    }
    return -1;
  }
} bfs[N];
int main() {
  scanf("%d%d", &n, &m);
  G.clear();
  G.resize(n + 1);
  trade.clear();
  trade.resize(n + 1);
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  scanf("%d", &w);
  for (int i = 1, c, k, p; i <= w; ++i) {
    scanf("%d%d%d", &c, &k, &p);
    trade[c].push_back(pLL(k, p));
  }
  for (int i = 1; i <= n; ++i) bfs[i].gao(i);
  scanf("%d", &q);
  for (int i = 1, g, r, a; i <= q; ++i) {
    scanf("%d%d%d", &g, &r, &a);
    printf("%d\n", bfs[g].run(r, a));
  }
  return 0;
}
