#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, h, t;
int deg[maxn];
struct Edge {
  int u, v;
} edge[maxn];
int flag[maxn];
vector<int> e[maxn];
int judge(int d1, int d2) {
  if (deg[d1] < h + 1 || deg[d2] < t + 1) return 0;
  if (deg[d1] >= h + t + 1 && deg[d2] >= t + 1) return 1;
  if (deg[d1] >= h + 1 && deg[d2] >= h + t + 1) return 2;
  return 3;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &h, &t);
  int a, b, u, v;
  int tot = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    deg[u]++;
    deg[v]++;
    edge[tot].u = u;
    edge[tot++].v = v;
    edge[tot].u = v;
    edge[tot++].v = u;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int ans1 = -1, ans2 = -1;
  vector<int> a1, a2;
  for (int i = 0; i < tot; i++) {
    int u = edge[i].u;
    int v = edge[i].v;
    int f = judge(u, v);
    if (!f) continue;
    if (f == 1) {
      ans1 = u;
      ans2 = v;
      int c = 0;
      for (vector<int>::iterator it = e[v].begin(); it != e[v].end(); it++) {
        if (*it == u) continue;
        a2.push_back(*it);
        flag[*it] = 1;
        if (++c == t) break;
      }
      c = 0;
      for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
        if (flag[*it] || *it == v) continue;
        a1.push_back(*it);
        if (++c == h) break;
      }
      break;
    }
    if (f == 2) {
      ans1 = u;
      ans2 = v;
      int c = 0;
      for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
        if (*it == v) continue;
        a1.push_back(*it);
        flag[*it] = 1;
        if (++c == h) break;
      }
      c = 0;
      for (vector<int>::iterator it = e[v].begin(); it != e[v].end(); it++) {
        if (flag[*it] || *it == u) continue;
        a2.push_back(*it);
        if (++c == t) break;
      }
      break;
    }
    int com = 0, onlyh = 0, onlyt = 0;
    vector<int> co;
    for (int k = 0; k < e[u].size(); k++) {
      if (e[u][k] == v) continue;
      flag[e[u][k]]++;
      onlyh++;
    }
    for (int k = 0; k < e[v].size(); k++) {
      if (e[v][k] == u) continue;
      if (flag[e[v][k]]) {
        com++, co.push_back(e[v][k]), flag[e[v][k]]++;
        continue;
      }
      onlyt++;
    }
    onlyh -= com;
    int need1 = 0, need2 = 0;
    if (onlyh < h) need1 = h - onlyh;
    if (onlyt < t) need2 = t - onlyt;
    if (need1 + need2 <= com) {
      ans1 = u;
      ans2 = v;
      int c = 0;
      for (int k = 0; k < e[u].size(); k++) {
        if (e[u][k] == v) continue;
        if (flag[e[u][k]] == 2) continue;
        a1.push_back(e[u][k]);
        if (++c == h) break;
      }
      vector<int>::iterator it = co.begin();
      bool mark = false;
      if (need1)
        for (; it != co.end(); it++) {
          mark = true;
          a1.push_back(*it);
          if (++c == h) break;
        }
      c = 0;
      for (int k = 0; k < e[v].size(); k++) {
        if (e[v][k] == u) continue;
        if (flag[e[v][k]] == 2) continue;
        a2.push_back(e[v][k]);
        if (++c == t) break;
      }
      if (mark) it++;
      if (need2)
        for (; it != co.end(); it++) {
          a2.push_back(*it);
          if (++c == t) break;
        }
      break;
    } else {
      for (int k = 0; k < e[u].size(); k++) flag[e[u][k]] = 0;
      for (int k = 0; k < e[v].size(); k++) flag[e[v][k]] = 0;
    }
  }
  if (ans1 == -1) {
    puts("NO");
  } else {
    printf("YES\n%d %d\n", ans1, ans2);
    for (vector<int>::iterator it = a1.begin(); it != a1.end(); it++) {
      printf("%d ", *it);
    }
    puts("");
    for (vector<int>::iterator it = a2.begin(); it != a2.end(); it++) {
      printf("%d ", *it);
    }
  }
  return 0;
}
