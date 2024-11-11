#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<int> e[n + 1], l;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
      l.push_back(-1);
    }
    l.push_back(-1);
    l.push_back(-1);
    l.push_back(-1);
    for (int p = 0; p < 2; p++) {
      queue<int> q, q2;
      if (p == 0) {
        q.push(a);
        q2.push(0);
      } else {
        int mxi = 1;
        int mx = l[1];
        l[1] = -1;
        for (int j = 2; j <= n; j++) {
          if (mx < l[j]) {
            mx = l[j];
            mxi = j;
          }
          l[j] = -1;
        }
        q.push(mxi);
        q2.push(0);
      }
      while (!q.empty()) {
        int qn = q.front();
        q.pop();
        int nn = q2.front();
        q2.pop();
        l[qn] = nn;
        for (int j = 0; j < (int)e[qn].size(); j++) {
          if (l[e[qn][j]] == -1) {
            q.push(e[qn][j]);
            q2.push(nn + 1);
          }
        }
      }
      if (p == 0 && l[b] <= da) {
        cout << "Alice" << endl;
        da = -10;
        break;
      }
    }
    int mxi = 1;
    int mx = l[1];
    for (int j = 2; j <= n; j++) {
      if (mx < l[j]) {
        mx = l[j];
        mxi = j;
      }
    }
    if (da == -10) continue;
    if (mx + 2 <= da * 2 || db <= da * 2)
      cout << "Alice" << endl;
    else
      cout << "Bob" << endl;
  }
}
