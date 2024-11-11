#include <bits/stdc++.h>
using namespace std;
const int N_STATE = 100001;
vector<int> res;
vector<int> st;
vector<vector<int> > adj(N_STATE);
vector<int> as(N_STATE, 0);
vector<int> curr(N_STATE, 0);
inline int bfs() {
  int size;
  queue<int> q;
  for (int i = 0; i < st.size(); ++i) {
    q.push(st[i]);
  }
  while (q.size()) {
    size = q.size();
    while (size--) {
      int s = q.front();
      q.pop();
      if (curr[s] != as[s]) continue;
      curr[s]++;
      res.push_back(s);
      for (int i = 0; i < adj[s].size(); i++) {
        bool ok = true;
        int ns = adj[s][i];
        curr[ns]++;
        if (curr[ns] == as[ns]) {
          q.push(ns);
        }
      }
    }
  }
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    cin >> as[i];
    if (as[i] == 0) st.push_back(i);
  }
  bfs();
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}
