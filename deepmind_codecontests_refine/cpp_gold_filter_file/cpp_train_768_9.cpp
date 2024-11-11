#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<pair<int, int> > adj[N];
int n, m, a[N], tu[N], td[N], inf = 1e9, ans[N];
pair<int, int> dis[N], tdis[N][2];
bool is[N];
int in() {
  int x;
  scanf("%d", &x);
  return x;
}
void mxadd(pair<int, int> &a, int b, pair<int, int> &t1, pair<int, int> &t2,
           int u) {
  if (a.first == b) t1.first++;
  if (a.second == b) t2.first++;
  if (a.first >= b) {
    if (a.second < b) a.second = b, t2.first = 1, t2.second = u;
  } else
    swap(t1, t2), a.second = a.first, a.first = b, t1.first = 1, t1.second = u;
}
void mxdis(int v, int p = -1) {
  for (auto u : adj[v]) {
    if (u.first == p) continue;
    mxdis(u.first, v);
    mxadd(dis[v], dis[u.first].first + u.second, tdis[v][0], tdis[v][1],
          u.first);
  }
}
void updis(int v, int p = -1) {
  for (auto u : adj[v]) {
    if (u.first == p) continue;
    if (dis[v].first == dis[u.first].first + u.second)
      mxadd(dis[u.first], dis[v].second + u.second, tdis[u.first][0],
            tdis[u.first][1], v);
    else
      mxadd(dis[u.first], dis[v].first + u.second, tdis[u.first][0],
            tdis[u.first][1], v);
    updis(u.first, v);
  }
}
pair<int, int> fans;
void updfs(int v, int p = -1, int w = 0) {
  for (auto u : adj[v]) {
    if (u.first == p) continue;
    updfs(u.first, v, u.second);
    ans[v] += td[u.first];
    if (tdis[v][0].first == 1) {
      if (tdis[v][0].second == p)
        td[v] += td[u.first];
      else {
        if (tdis[v][0].second == u.first) {
          if (tdis[v][1].first > 1) continue;
          if (tdis[v][1].second == p)
            td[v] += td[u.first];
          else
            tu[tdis[v][1].second] += td[u.first];
        } else
          tu[tdis[v][0].second] += td[u.first];
      }
    }
  }
  if (tdis[v][0].first == 2) {
    if (tdis[v][0].second == p)
      td[v] += td[tdis[v][1].second];
    else if (tdis[v][1].second == p)
      td[v] += td[tdis[v][0].second];
    else
      tu[tdis[v][1].second] += td[tdis[v][0].second],
          tu[tdis[v][0].second] += td[tdis[v][1].second];
  }
  if (tdis[v][0].first > 1 || !is[v]) return;
  if (tdis[v][0].second == p)
    td[v]++;
  else
    tu[tdis[v][0].second]++;
}
void dwdfs(int v, int p = -1, int w = 0) {
  if (p != -1) {
    ans[v] += tu[v];
    if (tdis[v][0].first == 1) {
      if (tdis[v][0].second == p) {
        if (tdis[v][1].first == 1) tu[tdis[v][1].second] += tu[v];
      } else
        tu[tdis[v][0].second] += tu[v];
    } else if (tdis[v][0].first == 2) {
      int c = dis[p].first;
      if (dis[v].first + w == c)
        c = dis[p].second + w;
      else
        c += w;
      if (dis[v].first == c) {
        for (auto u : adj[v])
          if (u.first != p && dis[u.first].second + u.second == dis[v].first) {
            tu[u.first] += tu[v];
            break;
          }
      }
    }
  }
  for (auto u : adj[v]) {
    if (u.first == p) continue;
    dwdfs(u.first, v, u.second);
  }
}
int main() {
  fans.first = -1;
  fill(dis, dis + N, make_pair(-inf, -inf));
  n = in(), m = in();
  for (int i = 0; i < m; i++)
    a[i] = in() - 1, is[a[i]] = 1, dis[a[i]].first = 0;
  for (int i = 0; i < n - 1; i++) {
    int u = in() - 1, v = in() - 1, c = in();
    adj[u].push_back(pair<int, int>(v, c));
    adj[v].push_back(pair<int, int>(u, c));
  }
  mxdis(0);
  updis(0);
  updfs(0);
  dwdfs(0);
  for (int i = 0; i < n; i++) {
    if (is[i]) continue;
    if (fans.first < ans[i]) fans.first = ans[i], fans.second = 0;
    if (fans.first == ans[i]) fans.second++;
  }
  cout << fans.first << ' ' << fans.second << endl;
}
