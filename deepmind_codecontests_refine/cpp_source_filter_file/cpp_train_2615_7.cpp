#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
struct Edge {
  int b, c, f, r;
  Edge(int bb, int cc, int rr) : b(bb), c(cc), f(0), r(rr) {}
};
vector<Edge> v[maxn];
int d[maxn], st[maxn];
int dinicn;
void addEdge(int a, int b, int c) {
  int s1 = v[a].size();
  int s2 = v[b].size();
  v[a].push_back(Edge(b, c, s2));
  v[b].push_back(Edge(a, 0, s1));
}
int dfs(int a, int t, int val) {
  if (a == t) return val;
  for (; st[a] < int(v[a].size()); st[a]++) {
    Edge &e = v[a][st[a]];
    if (d[a] < d[e.b] && e.c - e.f > 0) {
      int res = dfs(e.b, t, min(e.c - e.f, val));
      if (res > 0) {
        e.f += res;
        v[e.b][e.r].f -= res;
        return res;
      }
    }
  }
  return 0;
}
long long maxFlow(int s, int t) {
  long long res = 0;
  while (true) {
    for (int i = 1; i <= dinicn; i++) {
      st[i] = 0;
      d[i] = 1e9;
    }
    d[s] = 0;
    queue<int> kolejka;
    kolejka.push(s);
    while (!kolejka.empty()) {
      int a = kolejka.front();
      kolejka.pop();
      for (Edge e : v[a]) {
        if (d[e.b] == 1e9 && e.c - e.f > 0) {
          d[e.b] = d[a] + 1;
          kolejka.push(e.b);
        }
      }
    }
    if (d[t] == 1e9) break;
    int df = 0;
    do {
      df = dfs(s, t, 1e9);
      res = res + (long long)df;
    } while (df > 0);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int s = n + m + 1, t = n + m + 2;
    for (int i = 1; i <= n; i++) {
      v[i].clear();
      d[i] = 0;
    }
    vector<pair<int, int> > e;
    for (int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      e.push_back({a, b});
      addEdge(a, i + n, 1);
      addEdge(b, i + n, 1);
      addEdge(i + n, t, 1);
      d[a]++;
      d[b]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (d[i] > k) {
        addEdge(s, i, 2 * (d[i] - k));
        sum += 2 * (d[i] - k);
      }
    }
    dinicn = n + m + 2;
    int ff = maxFlow(s, t);
    if (ff == sum) {
      vector<int> res(m);
      int count = 1;
      for (int a = 1; a <= n; a++) {
        int r = 0;
        for (Edge &e : v[a]) {
          if (e.f == 1) {
            r ^= 1;
            res[e.b - n - 1] = count;
            if (r == 0) {
              count++;
            }
          }
        }
      }
      for (int i = 0; i < m; i++) {
        if (res[i] == 0) {
          res[i] = count++;
        }
        cout << res[i] << " ";
      }
      cout << "\n";
    } else {
      for (int i = 0; i < m; i++) {
        cout << "0 ";
      }
      cout << "\n";
    }
  }
  return 0;
}
