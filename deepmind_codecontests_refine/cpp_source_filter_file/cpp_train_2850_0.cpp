#include <bits/stdc++.h>
using namespace std;
void flawed(istream& r, ostream& w) {
  int n, m;
  r >> n >> m;
  int direction[m + 1];
  int edges[2 * m + 1][5];
  int in[n + 1];
  int out[n + 1];
  int head[n + 1];
  int e1[n + 1];
  int e2[n + 1];
  for (int i = 1; i <= n; ++i) {
    head[i] = -1;
    in[i] = out[i] = 0;
  }
  int e = 0;
  for (int i = 1; i <= m; ++i) {
    direction[i] = 0;
    int u, v, w;
    r >> u >> v >> w;
    e1[i] = u;
    e2[i] = v;
    edges[e][0] = u;
    edges[e][1] = v;
    edges[e][2] = w;
    edges[e][3] = i;
    edges[e][4] = head[u];
    head[u] = e++;
    edges[e][0] = v;
    edges[e][1] = u;
    edges[e][2] = w;
    edges[e][3] = i;
    edges[e][4] = head[v];
    head[v] = e++;
    out[u] += w;
    out[v] += w;
  }
  for (int i = 1; i <= n; ++i) {
    out[i] = out[i] >> 1;
  }
  list<int> queue;
  queue.push_back(1);
  in[1] = out[1] = 0;
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop_front();
    for (int i = head[u]; ~i; i = edges[i][4]) {
      int v = edges[i][1];
      if (in[v] == out[v] && v != n) continue;
      in[v] += edges[i][2];
      if (in[v] == out[v] && v != n) queue.push_back(v);
      int _id = edges[i][3];
      if (v == e1[_id]) direction[_id] = 1;
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << direction[i] << endl;
  }
}
int main() {
  flawed(cin, cout);
  return 0;
}
