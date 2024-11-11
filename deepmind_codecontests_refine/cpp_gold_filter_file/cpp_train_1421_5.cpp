#include <bits/stdc++.h>
const int MX = 3e5 + 23;
const long long MOD = 998244353;
int read() {
  char k = getchar();
  int x = 0;
  while (k < '0' || k > '9') k = getchar();
  while (k >= '0' && k <= '9') x = x * 10 + k - '0', k = getchar();
  return x;
}
int n, m, ans, pre[MX];
std::vector<int> e[MX];
std::set<int> S[MX];
int dis[MX];
int bfs() {
  std::queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto d : e[x]) {
      if (!dis[d]) {
        pre[d] = x;
        dis[d] = dis[x] + 1;
        q.push(d);
      }
    }
  }
  return dis[n] ? dis[n] : INT_MAX;
}
void output(int x) {
  if (x == 1) return printf("1 "), void();
  output(pre[x]);
  printf("%d ", x);
}
int cnt, degree[MX];
std::vector<int> q;
void dfs(int x) {
  if (dis[x] || S[1].find(x) == S[1].end()) return;
  dis[x] = cnt, q.push_back(x);
  for (auto i : e[x]) dfs(i);
}
int main() {
  n = read(), m = read();
  for (int i = 1, u, v; i <= m; ++i) {
    u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
    S[u].insert(v), S[v].insert(u);
  }
  ans = bfs();
  if (ans <= 4) {
    printf("%d\n", ans);
    output(n);
    return 0;
  }
  memset(dis, 0, sizeof dis);
  dis[1] = 1;
  for (auto i : e[1]) dis[i] = 1;
  for (auto i : e[1]) {
    for (auto j : e[i]) {
      if (!dis[j]) {
        printf("4\n1 %d %d 1 %d\n", i, j, n);
        return 0;
      }
    }
  }
  memset(dis, 0, sizeof dis);
  dis[1] = INT_MAX;
  for (auto i : e[1]) {
    q.clear();
    ++cnt;
    dfs(i);
    if (q.size() <= 2) continue;
    int x = q[0];
    for (auto k : e[x]) {
      degree[x] += dis[k] == cnt;
    }
    if (degree[x] == (int)q.size() - 1) {
      for (auto j : q) {
        for (auto k : q) {
          if (j == k) continue;
          if (S[k].find(j) == S[k].end()) {
            printf("5\n1 %d %d %d %d %d\n", j, x, k, j, n);
            return 0;
          }
        }
      }
    } else {
      for (auto j : e[x]) {
        if (dis[j] == cnt) {
          degree[j] = INT_MAX;
        }
      }
      for (auto j : q) {
        if (degree[j] == INT_MAX)
          for (auto k : e[j]) {
            if (dis[k] == cnt && !degree[k]) {
              printf("5\n1 %d %d %d %d %d\n", x, j, k, x, n);
              return 0;
            }
          }
      }
    }
  }
  puts("-1");
  return 0;
}
