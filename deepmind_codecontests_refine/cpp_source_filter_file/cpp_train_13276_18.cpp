#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> graph[100005];
long long parent[100005];
void cle() { memset(parent, -1, sizeof parent); }
void in_edge() {
  long long u, v;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}
long long bfs(long long source) {
  parent[source] = source;
  deque<long long> q;
  q.push_back(source);
  bool flag = 0;
  while (!q.empty()) {
    long long s = q.front();
    q.pop_back();
    for (long long i = 0; i < graph[s].size(); i++) {
      long long adj = graph[s][i];
      if (parent[adj] == -1) {
        parent[adj] = s;
        q.push_back(adj);
      } else if (parent[adj] != -1) {
        if (parent[s] != adj) {
          flag = 1;
        }
      }
    }
  }
  if (flag == 1) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  scanf("%lld", &n);
  scanf("%lld", &m);
  cle();
  in_edge();
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      sum += bfs(i);
    }
  }
  cout << sum << endl;
  return 0;
}
