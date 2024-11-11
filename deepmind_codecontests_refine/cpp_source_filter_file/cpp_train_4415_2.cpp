#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int m, n;
int mn[100005], mx[100005];
bool vis[100005], inq[100005];
vector<int> u[100005], v[100005];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
struct data {
  int id, w, r, sum;
  vector<int> v;
} p[100005];
void dijkstra() {
  memset(mn, 127, sizeof(mn));
  while (!q.empty()) {
    int d = min(1000000000, q.top().first), x = q.top().second;
    q.pop();
    if (d < mn[x]) {
      for (int i = 0; i < v[x].size(); i++) {
        int t = v[x][i];
        if (mn[x] > 1000000000)
          p[t].r--, p[t].sum += d;
        else
          p[t].sum += d - mn[x];
        if (!p[t].r) q.push(make_pair(p[t].sum, p[t].id));
        p[t].sum = min(p[t].sum, 1000000000);
      }
      mn[x] = d;
    }
  }
  for (int i = 1; i <= n; i++)
    if (mn[i] > 1000000000) mn[i] = mx[i] = -1;
}
void dp(int x) {
  if (vis[x] || inq[x]) return;
  vis[x] = inq[x] = 1;
  for (int i = 0; i < u[x].size(); i++) {
    int t = u[x][i], sum = p[t].w;
    for (int j = 0; j < p[t].v.size(); j++)
      if (mx[p[t].v[j]] == -1) {
        sum = -1;
        break;
      }
    if (sum == -1) continue;
    for (int j = 0; j < p[t].v.size(); j++) {
      int v = p[t].v[j];
      dp(v);
      if (inq[v] || mx[v] == 1000000000) {
        sum = 1000000000;
        break;
      }
      sum += mx[v];
    }
    mx[x] = max(mx[x], sum);
  }
  inq[x] = 0;
}
int main() {
  m = read();
  n = read();
  for (int i = 1; i <= m; i++) {
    p[i].id = read();
    u[p[i].id].push_back(i);
    int x = read(), y;
    for (int j = 1; j <= x; j++) {
      y = read();
      if (y == -1)
        p[i].w++;
      else {
        p[i].r++;
        p[i].v.push_back(y);
        v[y].push_back(i);
      }
    }
    if (p[i].w == x) q.push(make_pair(p[i].w, p[i].id));
    p[i].sum = p[i].w;
  }
  dijkstra();
  for (int i = 1; i <= n; i++)
    if (mx[i] != -1 && !vis[i]) dp(i);
  for (int i = 1; i <= n; i++)
    if (mx[i] == 1000000000) mx[i] = -2;
  for (int i = 1; i <= n; i++)
    printf("%I64d %I64d\n", min(mn[i], 314000000), min(mx[i], 314000000));
  return 0;
}
