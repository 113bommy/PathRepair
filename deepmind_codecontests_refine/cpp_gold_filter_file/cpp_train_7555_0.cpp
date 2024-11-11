#include <bits/stdc++.h>
using namespace std;
int n;
int q;
int s;
struct st {
  int a;
  int b;
  long long int cost;
};
vector<st> v[100002 * 4][2];
int node[100002];
inline void init(int b, int l, int r) {
  v[b][1].push_back({b, 0, 0});
  if (l + 1 == r) {
    node[l] = b;
    return;
  }
  init(b * 2 + 1, l, (l + r) >> 1);
  init(b * 2 + 2, (l + r) >> 1, r);
  v[b][1].push_back({b * 2 + 1, 1, 0});
  v[b][1].push_back({b * 2 + 2, 1, 0});
  v[b * 2 + 1][0].push_back({b, 0, 0});
  v[b * 2 + 2][0].push_back({b, 0, 0});
  v[b * 2 + 1][0].push_back({b, 0, 0});
  v[b * 2 + 2][0].push_back({b, 0, 0});
}
inline void add1(int b, int l, int r, int ll, int rr, int x, long long int c) {
  if (r <= ll || rr <= l) return;
  if (ll <= l && r <= rr) {
    v[x][0].push_back({b, 1, c});
    return;
  }
  add1(b * 2 + 1, l, (l + r) >> 1, ll, rr, x, c);
  add1(b * 2 + 2, (l + r) >> 1, r, ll, rr, x, c);
}
inline void add2(int b, int l, int r, int ll, int rr, int x, long long int c) {
  if (r <= ll || rr <= l) return;
  if (ll <= l && r <= rr) {
    v[b][0].push_back({x, 1, c});
    return;
  }
  add2(b * 2 + 1, l, (l + r) >> 1, ll, rr, x, c);
  add2(b * 2 + 2, (l + r) >> 1, r, ll, rr, x, c);
}
long long int dist[100002 * 4][2];
int main() {
  cin >> n >> q >> s;
  s--;
  init(0, 0, n);
  while (q--) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int v, u, w;
      scanf("%d%d%d", &v, &u, &w);
      v--;
      u--;
      add1(0, 0, n, u, u + 1, node[v], w);
      continue;
    }
    if (ty == 2) {
      int v, l, r, w;
      scanf("%d%d%d%d", &v, &l, &r, &w);
      l--;
      r--;
      v--;
      add1(0, 0, n, l, r + 1, node[v], w);
    }
    if (ty == 3) {
      int v, l, r, w;
      scanf("%d%d%d%d", &v, &l, &r, &w);
      l--;
      r--;
      v--;
      add2(0, 0, n, l, r + 1, node[v], w);
    }
  }
  for (int i = 0; i < 100002 * 4; i++) {
    dist[i][0] = dist[i][1] = LLONG_MAX;
  }
  queue<pair<int, int> > q;
  q.push(make_pair(node[s], 1));
  dist[node[s]][1] = 0;
  while (!q.empty()) {
    int a = q.front().first;
    int b = q.front().second;
    q.pop();
    vector<st> &vv = v[a][b];
    for (int i = 0; i < vv.size(); i++) {
      int x = vv[i].a;
      int yy = vv[i].b;
      long long int nex = dist[a][b] + vv[i].cost;
      if (dist[x][yy] > nex) {
        dist[x][yy] = nex;
        q.push(make_pair(x, yy));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      printf(" ");
    }
    if (dist[node[i]][0] == LLONG_MAX) {
      printf("-1");
    } else {
      printf("%lld", dist[node[i]][0]);
    }
  }
  puts("");
  return 0;
}
