#include <bits/stdc++.h>
using namespace std;
const int maxn = 600010;
const int INF = 1 << 30;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, k;
vector<int> g[maxn], w[maxn];
map<pair<int, int>, int> mapp;
queue<int> que;
int d[maxn];
int r[maxn], c[maxn];
bool inq[maxn];
void link(int u, int v, int c) {
  if (u == -1 || v == -1) return;
  g[u].push_back(v);
  w[u].push_back(c);
}
int getid(bool col, int x) {
  if (col) {
    if (x <= m && x >= 1)
      return k + 10 + x;
    else
      return -1;
  } else {
    if (x <= n && x >= 1)
      return k + 10 + m + x;
    else
      return -1;
  }
}
int spfa(int s, int t) {
  for (int i = 0; i < maxn; i++) d[i] = INF;
  memset(inq, false, sizeof(inq));
  d[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    inq[u] = false;
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i];
      if (d[v] > d[u] + w[u][i]) {
        d[v] = d[u] + w[u][i];
        if (!inq[v]) {
          que.push(v);
          inq[v] = true;
        }
      }
    }
  }
  return d[t] != INF ? d[t] : -1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &r[i], &c[i]);
    mapp[make_pair(r[i], c[i])] = i;
    link(getid(0, r[i]), i, 0);
    link(getid(0, r[i] - 1), i, 0);
    link(getid(0, r[i] + 1), i, 0);
    link(i, getid(0, r[i]), 1);
    link(i, getid(0, r[i] - 1), 1);
    link(i, getid(0, r[i] + 1), 1);
    link(getid(1, c[i]), i, 0);
    link(getid(1, c[i] - 1), i, 0);
    link(getid(1, c[i] + 1), i, 0);
    link(i, getid(1, c[i]), 1);
    link(i, getid(1, c[i] - 1), 1);
    link(i, getid(1, c[i] + 1), 1);
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < 4; j++) {
      if (mapp[make_pair(r[i] + dx[j], c[i] + dy[j])] != 0)
        link(i, mapp[make_pair(r[i] + dx[j], c[i] + dy[j])], 0);
    }
  }
  if (mapp[make_pair(n, m)] == 0) {
    mapp[make_pair(n, m)] = k + 2;
    link(getid(0, n), k + 2, 0);
    link(getid(1, m), k + 2, 0);
  }
  int ans = spfa(mapp[make_pair(1, 1)], mapp[make_pair(n, m)]);
  printf("%d\n", ans);
  return 0;
}
