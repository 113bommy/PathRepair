#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct edge {
 public:
  int flow, cap, cost;
  int u, v;
  edge(int _u, int _v, int _flow, int _cost, int _cap) {
    u = _u;
    v = _v;
    flow = _flow;
    cost = _cost;
    cap = _cap;
  }
  edge() {}
} E[10000];
vector<int> V[10000];
int say[100], src, dest;
int phi[10000];
int B[10000], par[10000], D[10000];
set<pair<int, int> > S;
set<pair<int, int> >::iterator it;
bool dijkstra() {
  memset(B, 0, sizeof(B));
  for (int i = 1; i <= dest; i++) {
    D[i] = 1000000000;
    S.insert(make_pair(D[i], i));
  }
  D[0] = 0;
  S.insert(make_pair(D[0], 0));
  par[0] = -1;
  while (!S.empty()) {
    it = S.begin();
    pair<int, int> cur = *it;
    S.erase(it);
    int v = cur.second;
    if (D[v] == 1000000000) break;
    B[v] = 1;
    for (int j = 0; j < V[v].size(); j++) {
      int idx = V[v][j];
      if (E[idx].u == v) {
        if (E[idx].flow < E[idx].cap) {
          int nv = E[idx].v;
          if ((!B[nv]) && D[nv] > D[v] + (phi[v] - phi[nv] + E[idx].cost)) {
            S.erase(S.find(make_pair(D[nv], nv)));
            D[nv] = D[v] + (phi[v] - phi[nv] + E[idx].cost);
            S.insert(make_pair(D[nv], nv));
            par[nv] = idx;
          }
        }
      } else {
        if (E[idx].flow > 0) {
          int nv = E[idx].u;
          if ((!B[nv]) && D[nv] > D[v] + (phi[v] - phi[nv] - E[idx].cost)) {
            S.erase(S.find(make_pair(D[nv], nv)));
            D[nv] = D[v] + (phi[v] - phi[nv] - E[idx].cost);
            S.insert(make_pair(D[nv], nv));
            par[nv] = idx;
          }
        }
      }
    }
  }
  for (int i = 0; i <= dest; i++)
    if (B[i]) phi[i] += D[i];
  return B[dest];
}
void augment() {
  int cur = dest, aug = 1000000000;
  while (par[cur] >= 0) {
    int idx = par[cur];
    if (E[idx].v == cur) {
      aug = min(aug, E[idx].cap - E[idx].flow);
      cur = E[idx].u;
    } else {
      aug = min(aug, E[idx].flow);
      cur = E[idx].v;
    }
  }
  cur = dest;
  while (par[cur] >= 0) {
    int idx = par[cur];
    if (E[idx].v == cur) {
      E[idx].flow += aug;
      cur = E[idx].u;
    } else {
      E[idx].flow -= aug;
      cur = E[idx].v;
    }
  }
}
int main() {
  string t, s;
  int n, a;
  cin >> t >> n;
  src = 0;
  dest = n + n * 26 + 27;
  int cv = n + 1, ce = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s >> a;
    memset(say, 0, sizeof(say));
    int len = s.length();
    for (int j = 0; j < len; j++) say[s[j] - 'a']++;
    for (int j = 0; j < 26; j++) {
      E[ce] = edge(i, cv, 0, i, say[j]);
      V[i].push_back(ce);
      V[cv].push_back(ce);
      ce++;
      E[ce] = edge(cv, n + n * 26 + j + 1, 0, 0, 1000000000);
      V[cv].push_back(ce);
      V[n + n * 26 + j + 1].push_back(ce);
      ce++;
      cv++;
    }
    E[ce] = edge(0, i, 0, 0, a);
    V[0].push_back(ce);
    V[i].push_back(ce);
    ce++;
  }
  memset(say, 0, sizeof(say));
  int len = t.length();
  for (int i = 0; i < len; i++) say[t[i] - 'a']++;
  for (int i = 1; i <= 26; i++) {
    E[ce] = edge(n + n * 26 + i, dest, 0, 0, say[i - 1]);
    V[n + n * 26 + i].push_back(ce);
    V[dest].push_back(ce);
    ce++;
  }
  while (dijkstra()) {
    augment();
  }
  int can = 1;
  for (int i = 0; i < V[dest].size(); i++) {
    int idx = V[dest][i];
    if (E[idx].flow != E[idx].cap) can = 0;
  }
  if (!can) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < ce; i++) ans += E[i].cost * E[i].flow;
  cout << ans << endl;
  return 0;
}
