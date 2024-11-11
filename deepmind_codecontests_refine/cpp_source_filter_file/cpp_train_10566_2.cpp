#include <bits/stdc++.h>
using namespace std;
int n, m;
int head[100016], to[100016 << 1], wto[100016 << 1], nex[100016 << 1], ecn;
void ade(int u, int v, int w) {
  to[++ecn] = v, nex[ecn] = head[u], wto[ecn] = w, head[u] = ecn;
}
int dis[100016], len[100016], pre[100016], done[100016];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    Q;
queue<int> q;
void dijk(int s) {
  memset(dis, 0x3f, sizeof dis);
  memset(len, 0x3f, sizeof len);
  memset(pre, -1, sizeof pre);
  dis[s] = 0, len[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; ~i; i = nex[i]) {
      int v = to[i];
      Q.push(make_pair(0, u));
      if (dis[v] && !wto[i])
        q.push(v), dis[v] = 0, pre[v] = (i ^ 1), len[v] = len[u] + 1;
    }
  }
  int rnk = 0, last = -1;
  while (!Q.empty()) {
    pair<int, int> too = Q.top();
    Q.pop();
    int u = too.second;
    if (done[u]) continue;
    done[u] = true;
    if (last != dis[u]) last = dis[u], ++rnk;
    for (int i = head[u]; ~i; i = nex[i]) {
      int v = to[i];
      if (dis[v] > rnk * 10 + wto[i]) {
        dis[v] = rnk * 10 + wto[i];
        pre[v] = (i ^ 1);
        len[v] = len[u] + 1;
        Q.push(make_pair(dis[v], v));
      } else if (dis[v] == rnk * 10 + wto[i] && len[v] > len[u] + 1) {
        pre[v] = (i ^ 1);
        len[v] = len[u] + 1;
        Q.push(make_pair(dis[v], v));
      }
    }
  }
}
int main() {
  memset(head, -1, sizeof head), ecn = -1;
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    ++u, ++v;
    ade(u, v, w), ade(v, u, w);
  }
  dijk(n);
  int c = 1;
  stack<int> sss;
  while (c != n) sss.push(wto[pre[c]]), c = to[pre[c]];
  while (!sss.empty() && sss.top() == 0) sss.pop();
  if (sss.empty())
    printf("0");
  else
    while (!sss.empty()) printf("%d", sss.top()), sss.pop();
  puts("");
  printf("%d", len[1]);
  c = 1;
  printf("%d ", 0);
  while (c != n) c = to[pre[c]], printf("%d ", c - 1);
}
