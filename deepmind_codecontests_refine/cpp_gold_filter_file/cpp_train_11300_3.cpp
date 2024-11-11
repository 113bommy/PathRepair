#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e5 + 2;
const long long int mod = 1e3 + 2;
map<long long int, vector<long long int> > graph;
set<long long int> vis;
pair<long long int, long long int> bfs(long long int x, long long int n) {
  long long int d[n + 2];
  memset(d, 0, sizeof(d));
  queue<long long int> st;
  st.push(x);
  while (!st.empty()) {
    long long int to = st.front();
    st.pop();
    for (long long int i = 0; i < graph[to].size(); ++i) {
      long long int ver = graph[to][i];
      if (d[ver] == 0) {
        st.push(ver);
        d[ver] = d[to] + 1;
      }
    }
  }
  long long int maxDist = 0, ver = 0;
  for (long long int i = 0; i <= n; i++)
    if (d[i] > maxDist) {
      maxDist = d[i];
      ver = i;
    }
  return {ver, maxDist};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, x, y;
  vector<pair<long long int, long long int> > edge;
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    cin >> x >> y;
    edge.push_back({x, y});
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  if (n == 2 || m == 1) {
    cout << 1 << endl;
    return 0;
  }
  pair<long long int, long long int> dis1 = bfs(x, n);
  pair<long long int, long long int> dis2 = bfs(dis1.first, n);
  cout << dis2.second << endl;
  return 0;
}
