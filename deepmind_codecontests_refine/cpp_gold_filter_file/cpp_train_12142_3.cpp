#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 998244353;
const int alphabet = 21;
const long double PI = atan(1.0) * 4L;
const int MAXINT = 2e5 + 1;
const int INFFLOW = 1e6;
const int INFCOST = 1e6;
struct MCF {
  int n;
  vector<int> prio, pot;
  vector<int> curflow;
  vector<int> prevedge, prevnode;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  struct edge {
    int to, rev;
    int f, cap;
    int cost;
  };
  vector<vector<edge>> g;
  MCF(int n)
      : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
  void add_edge(int s, int t, int cap, int cost) {
    g[s].push_back((edge){t, int((g[t]).size()), 0, cap, cost});
    g[t].push_back((edge){s, int((g[s]).size()) - 1, 0, 0, -cost});
  }
  pair<int, int> get_flow(int s, int t) {
    int flow = 0;
    int flowcost = 0;
    while (1) {
      q.push({0, s});
      fill(prio.begin(), prio.end(), INFCOST);
      prio[s] = 0;
      curflow[s] = INFFLOW;
      while (!q.empty()) {
        auto cur = q.top();
        int d = cur.first;
        int u = cur.second;
        q.pop();
        if (d != prio[u]) continue;
        for (int i = 0; i < int((g[u]).size()); ++i) {
          edge &e = g[u][i];
          int v = e.to;
          if (e.cap <= e.f) continue;
          int nprio = prio[u] + e.cost + pot[u] - pot[v];
          if (prio[v] > nprio) {
            prio[v] = nprio;
            q.push({nprio, v});
            prevnode[v] = u;
            prevedge[v] = i;
            curflow[v] = min(curflow[u], e.cap - e.f);
          }
        }
      }
      if (prio[t] == INFCOST) break;
      for (int i = 0; i < n; i++) pot[i] += prio[i];
      int df = min(curflow[t], INFFLOW - flow);
      flow += df;
      for (int v = t; v != s; v = prevnode[v]) {
        edge &e = g[prevnode[v]][prevedge[v]];
        e.f += df;
        g[v][e.rev].f -= df;
        flowcost += df * e.cost;
      }
    }
    return {flow, flowcost};
  }
};
int main() {
  int n;
  scanf("%d", &n);
  string S;
  cin >> S;
  int b[n];
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int cnt[26] = {};
  for (char c : S) cnt[c - 'a']++;
  int cu = 0, labLet[26], labPos[n / 2], s = cu++, t = cu++;
  for (int i = 0; i < 26; i++) labLet[i] = cu++;
  for (int i = 0; i < n / 2; i++) labPos[i] = cu++;
  MCF red(cu + 1);
  for (int l = 0; l < 26; l++) red.add_edge(s, labLet[l], cnt[l], 0);
  for (int p = 0; p < n / 2; p++) red.add_edge(labPos[p], t, 2, 0);
  for (int l = 0; l < 26; l++) {
    for (int p = 0; p < n / 2; p++) {
      int L = S[p] - 'a', R = S[n - 1 - p] - 'a', cost;
      if (l == L && l == R)
        cost = max(b[p], b[n - 1 - p]);
      else if (l == L)
        cost = b[p];
      else if (l == R)
        cost = b[n - 1 - p];
      else
        cost = 0;
      red.add_edge(labLet[l], labPos[p], 1, -cost);
    }
  }
  printf("%d\n", -red.get_flow(s, t).second);
  return 0;
}
