#include <bits/stdc++.h>
using namespace std;
const int N = 3005, M = 12, Q = 4e5 + 15;
bool cango[N][N];
vector<int> adj[N];
void bfs(int st) {
  cango[st][st] = 1;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int fr = q.front();
    q.pop();
    cango[st][fr] = 1;
    for (int i = 0; i < adj[fr].size(); ++i) {
      int nnode = adj[fr][i];
      if (cango[st][nnode]) continue;
      q.push(nnode);
    }
  }
}
int ret[Q], Next_node[N][M];
void cal(int t, int n) {
  memset(Next_node, -1, sizeof(Next_node));
  for (int i = 1; i <= n; ++i) {
    if (cango[i][t] && i != t) {
      for (int j = 0; j < (int)adj[i].size(); ++j) {
        if (cango[adj[i][j]][t]) {
          Next_node[i][0] = adj[i][j];
          break;
        }
      }
    }
  }
  for (int d = 1; d < M; ++d) {
    for (int i = 1; i <= n; ++i) {
      if (Next_node[i][d - 1] != -1) {
        int u = Next_node[i][d - 1];
        Next_node[i][d] = Next_node[u][d - 1];
      }
    }
  }
}
int query(int s, int t, int k, int n) {
  if (!cango[s][t]) return -1;
  int cur = s, ret = 0;
  for (int i = M - 1; i >= 0; --i) {
    if (Next_node[cur][i] != -1 && Next_node[cur][i] != t) {
      ret += (1 << i);
      cur = Next_node[cur][i];
      if (cur == -1) {
        exit(0);
      }
    }
  }
  cur = Next_node[cur][0];
  ++ret;
  if (cur != t || ret >= n || k - 1 > ret) return -1;
  cur = s;
  --k;
  for (int i = 0; i < M; ++i) {
    if (k & (1 << i)) {
      cur = Next_node[cur][i];
    }
  }
  return cur;
}
int s[Q], t[Q], k[Q];
int main() {
  int n, m, a, b, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) sort(adj[i].begin(), adj[i].end()), bfs(i);
  vector<pair<int, int> > in;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d", &s[i], &t[i], &k[i]);
    in.push_back(make_pair(t[i], i));
  }
  sort(in.begin(), in.end());
  for (int i = 0; i < in.size();) {
    int j = i;
    int tt = in[i].first;
    cal(tt, n);
    for (j = i; j < in.size(); ++j) {
      if (in[j].first != tt) break;
      int id = in[j].second;
      ret[id] = query(s[id], t[id], k[id], n);
    }
    i = j;
  }
  for (int i = 0; i < q; ++i) printf("%d\n", ret[i]);
  return 0;
}
