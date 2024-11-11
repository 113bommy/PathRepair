#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int inf = 1e9;
int n, m, a[N], v[N], op, ed;
pair<int, int> e[N][N];
int P(int a, int b) { return a * 2 + b; }
queue<int> q;
int pre[N], dis[N];
bool vis[N];
bool spfa() {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= ed; ++i) dis[i] = inf, pre[i] = 0, vis[i] = 0;
  q.push(op);
  vis[op] = 1;
  dis[op] = 0;
  while (!q.empty()) {
    int u = q.front();
    vis[u] = 0;
    q.pop();
    for (int v = 1; v <= ed; ++v)
      if (e[u][v].first) {
        int s = dis[u] + e[u][v].second;
        if (s < dis[v]) {
          dis[v] = s;
          pre[v] = u;
          if (!vis[v]) q.push(v), vis[v] = 1;
        }
      }
  }
  return (dis[ed] < inf);
}
int sum = 0;
void flow() {
  while (spfa()) {
    sum += dis[ed];
    for (int i = ed; i != op; i = pre[i]) {
      e[pre[i]][i].first--;
      e[i][pre[i]].first++;
    }
  }
}
int mk[N], cnt;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 30; ++j)
      if (a[i] >> j & 1) v[i]++;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      int w = (a[i] == a[j]) ? 0 : v[j];
      e[P(j, 1)][P(i, 2)] = make_pair(1, w);
      e[P(i, 2)][P(j, 1)] = make_pair(0, -w);
    }
  for (int i = 1; i <= n; ++i) {
    e[P(i, 1)][P(0, 2)] = make_pair(1, v[i]);
    e[P(0, 2)][P(i, 1)] = make_pair(0, -v[i]);
  }
  op = P(n, 2) + 1, ed = P(n, 2) + 2;
  for (int i = 1; i <= n; ++i) e[op][P(i, 1)] = make_pair(1, 0);
  for (int i = 1; i <= n; ++i) e[P(i, 2)][ed] = make_pair(1, 0);
  e[P(0, 2)][ed] = make_pair(m, 0);
  flow();
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= i - 1; ++j)
      if (e[P(i, 1)][P(j, 2)].first == 0) {
        if (j == 0)
          mk[i] = cnt++;
        else
          mk[i] = mk[j];
        if (j == 0 || a[i] != a[j]) ans.push_back(make_pair(mk[i], a[i]));
        ans.push_back(make_pair(mk[i], 0));
      }
  printf("%d %d\n", ((int)ans.size()), sum);
  for (int i = 0; i <= ((int)ans.size()) - 1; ++i)
    if (ans[i].second)
      printf("%c=%d\n", 'a' + ans[i].first, ans[i].second);
    else
      printf("print(%c)\n", ans[i].first + 'a');
}
