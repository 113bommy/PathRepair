#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
struct Query {
  int t, x, y;
  Query(int _t, int _x, int _y = -1) : t(_t), x(_x), y(_y) {}
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Query> vq, q3;
  vector<int> qans, psource(m + 1);
  int cur = 1;
  vector<vector<int>> graph(n + 1);
  vector<bool> isSeed(n + 1, -1);
  vector<set<int>*> pack;
  vector<vector<int>*> ccs;
  for (int i = 0; i <= n; i++) {
    pack.push_back(new set<int>());
    ccs.push_back(new vector<int>(1, i));
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      vq.push_back(Query(t, x, y));
    } else if (t == 2) {
      int x;
      cin >> x;
      vq.push_back(Query(t, x));
    } else {
      int x, y;
      cin >> x >> y;
      q3.push_back(Query(t, x, y));
    }
  }
  vector<vector<pair<int, int>>> qInvAns(n + 1), q2InvAns(m + 1);
  for (int i = 0; i < q3.size(); i++) {
    pair<int, int> p = {q3[i].y, i};
    qInvAns[q3[i].x].push_back(p);
    pair<int, int> p2 = {q3[i].x, i};
    q2InvAns[q3[i].y].push_back(p2);
  }
  qans.resize(q3.size());
  for (int i = 0; i < vq.size(); i++) {
    int t = vq[i].t;
    if (t == 1) {
      int x = vq[i].x, y = vq[i].y;
      graph[y].push_back(x);
      isSeed[x] = 0;
      auto pold = ccs[x];
      auto pnew = ccs[y];
      if (pold->size() > pnew->size()) swap(pold, pnew);
      for (int u : *pold) {
        pnew->push_back(u);
        ccs[u] = pnew;
      }
    } else if (t == 2) {
      int x = vq[i].x;
      psource[cur] = x;
      pack[x]->insert(cur);
      for (auto p : q2InvAns[cur]) {
        qans[p.second] = (ccs[x] == ccs[p.first]);
      }
      cur++;
    }
  }
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (isSeed[i]) {
      stack<int> st;
      st.push(i);
      while (st.size()) {
        int cur = st.top();
        vis[cur] = 1;
        for (int j : graph[cur]) {
          if (!vis[j]) {
            st.push(j);
          }
        }
        if (cur == st.top()) {
          auto pL = pack[cur];
          for (int j : graph[cur]) {
            if (pack[j]->size() > pL->size()) {
              pL = pack[j];
            }
          }
          if (pL != pack[cur]) {
            for (int j : *pack[cur]) {
              pL->insert(j);
            }
          }
          for (int j : graph[cur]) {
            if (pack[j] != pL) {
              for (int k : *pack[j]) {
                pL->insert(k);
              }
            }
          }
          pack[cur] = pL;
          for (auto p : qInvAns[cur]) {
            if (pL->find(p.first) == pL->end()) {
              qans[p.second] = 0;
            }
          }
          st.pop();
        }
      }
    }
  }
  for (int i : qans) {
    cout << (i ? "YES" : "NO") << '\n';
  }
  return 0;
}
