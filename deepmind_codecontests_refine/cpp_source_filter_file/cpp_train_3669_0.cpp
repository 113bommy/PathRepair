#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
void bfs(int v, vector<long long> &b, vector<vector<int>> &a) {
  queue<int> q;
  q.push(v);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i : a[u]) {
      if (b[i] == INF) {
        b[i] = b[u] + 1;
        q.push(i);
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<long long> p(m + 1, 0);
    ;
    for (int i = 0; i < m; i++) cin >> p[i];
    sort(p.begin(), p.end());
    for (int i = 1; i < m + 1; i++) {
      p[i] += p[i - 1];
    }
    vector<vector<int>> d(n + 1, vector<int>(0, 0));
    ;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      d[u].push_back(v);
      d[v].push_back(u);
    }
    vector<long long> da(n + 1, INF), db(n + 1, INF), dc(n + 1, INF);
    da[a] = 0;
    bfs(a, da, d);
    db[b] = 0;
    bfs(b, db, d);
    dc[c] = 0;
    bfs(c, dc, d);
    long long otv = INF;
    for (int i = 1; i < n + 1; i++) {
      if (da[i] + db[i] + dc[i] > m) continue;
      long long per = p[db[i]] + p[da[i] + db[i] + dc[i]];
      otv = min(otv, per);
    }
    cout << otv << endl;
    ;
  }
}
