#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int n, m; cin >> n >> m;) {
    vector<vector<int>> G(n);
    vector<vector<int>> Ginv(n);
    for (int i = 0; i < m; ++i) {
      int fr, to;
      cin >> fr >> to;
      --fr, --to;
      G[fr].push_back(to);
      Ginv[to].push_back(fr);
    }
    int s, t;
    cin >> s >> t;
    --s, --t;
    const int INF = 0x3fffffff;
    vector<int> score(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.emplace(0, t);
    while (!Q.empty()) {
      int cost = Q.top().first;
      int v = Q.top().second;
      Q.pop();
      if (score[v] < INF) continue;
      if (v == t) {
        score[v] = 0;
      } else {
        bool all_less = true;
        for (int u : G[v])
          if (G[v][u] > cost - 1) {
            all_less = false;
            break;
          }
        score[v] = all_less ? cost - 1 : cost;
      }
      for (int u : Ginv[v])
        if (score[u] == INF) Q.emplace(score[v] + 1, u);
    }
    cout << (score[s] == INF ? -1 : score[s]) << endl;
  }
}
