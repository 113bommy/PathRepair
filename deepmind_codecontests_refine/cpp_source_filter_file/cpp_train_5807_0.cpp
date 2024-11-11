#include <bits/stdc++.h>
using namespace std;

#define inf 2000000000  // 1e17
template <class T>
struct Dinic {
  struct edge {
    int to;
    T cap;
    int rev;
  };
  vector<vector<edge>> edges;
  vector<int> id;
  vector<int> d;
  Dinic(int n = 1) {
    edges.clear();
    edges.resize(n);
    id.resize(n);
    d.resize(n);
  }
  bool add(int start, int goal, T capacity) {
    edges[start].push_back((edge){goal, capacity, (int)edges[goal].size()});
    edges[goal].push_back((edge){start, 0, (int)edges[start].size() - 1});
    return 1;
  }
  void bfs(int st) {
    d.assign(d.size(), -1);
    queue<int> qu;
    d[st] = 0;
    qu.push(st);
    while (qu.size()) {
      int now = qu.front();
      qu.pop();
      for (auto e : edges[now])
        if (e.cap > 0 && d[e.to] < 0) {
          d[e.to] = d[now] + 1;
          qu.push(e.to);
        }
    }
  }
  T pathdfs(int now, int goal, T nf) {
    if (now == goal) return nf;
    for (int& i = id[now]; i < (int)edges[now].size(); ++i) {
      edge* e = &edges[now][i];
      if (e->cap > 0 && d[now] < d[e->to]) {
        T res = pathdfs(e->to, goal, min(nf, e->cap));
        if (res > 0) {
          e->cap -= res;
          edges[e->to][e->rev].cap += res;
          return res;
        }
      }
    }
    return 0;
  }
  T solve(int start, int goal) {
    T res = 0, nf = 0;
    while (1) {
      bfs(start);
      if (d[goal] < 0) return res;
      id.assign(id.size(), 0);
      while ((nf = pathdfs(start, goal, inf)) > 0) res += nf;
    }
    return -1;
  }
};

int n, m;
int d[] = {0, 1, 0, -1};
string c1 = ">v<^", c2 = "<^>v";
vector<string> s;
Dinic<int> din;

bool isvalid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.';
}

int main() {
  cin >> n >> m;
  s.resize(n);
  for (auto& p : s) cin >> p;
  if (n == m && n == 1) {
    cout << 0 << endl;
    cout << s << endl;
    return 0;
  }
  din = Dinic<int>(n * m + 2);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (s[i][j] == '.') {
        if ((i ^ j) & 1)
          din.add(i * m + j, n * m + 1, 1);
        else {
          din.add(n * m, i * m + j, 1);
          for (int k = 0; k < 4; ++k) {
            int nx = i + d[k], ny = j + d[k ^ 1];
            if (isvalid(nx, ny)) din.add(i * m + j, nx * m + ny, 1);
          }
        }
      }
  cout << din.solve(n * m, n * m + 1) << endl;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!((i ^ j) & 1)) {
        for (auto e : din.edges[i * m + j])
          if (e.cap == 0) {
            int nx = e.to / m, ny = e.to % m;
            for (int k = 0; k < 4; ++k)
              if (i + d[k] == nx && j + d[1 ^ k] == ny) {
                s[i][j] = c1[k];
                s[nx][ny] = c2[k];
              }
          }
      }
  for (auto p : s) cout << p << endl;
  return 0;
}
