#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 5e5 + 5;
inline int read() {
  int sum = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum * f;
}
int n, m, t, pre[N], f[N], tim[N];
struct edge {
  int u, v, w;
};
vector<edge> e;
struct query {
  int u, v, w, id;
};
vector<query> q;
int find(int x) {
  if (x == pre[x]) return x;
  return pre[x] = find(pre[x]);
}
int find2(int x, int now) {
  if (tim[x] ^ now) {
    tim[x] = now;
    f[x] = pre[x];
  }
  if (x == f[x]) return x;
  return f[x] = find2(f[x], now);
}
bool ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e.push_back({u, v, w});
  }
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int num, x;
    cin >> num;
    for (int j = 1; j <= num; j++) {
      cin >> x;
      q.push_back({e[x - 1].u, e[x - 1].v, e[x - 1].w, i});
    }
  }
  sort(e.begin(), e.end(), [](edge x, edge y) -> bool { return x.w < y.w; });
  sort(q.begin(), q.end(), [](query x, query y) -> bool {
    return x.w == y.w ? x.id < y.id : x.w < y.w;
  });
  int pos1 = 0, pos2 = 0, now = 0;
  for (int i = 1; i <= n; i++) f[i] = pre[i] = i;
  for (int i = 0; i < (int)q.size(); i = pos2) {
    while (pos1 < m && e[pos1].w < q[i].w) {
      int x = e[pos1].u, y = e[pos1].v;
      int fx = find(x), fy = find(y);
      if (fx ^ fy) pre[fy] = fx;
      pos1++;
    }
    while (pos2 < (int)q.size() && q[pos2].w == q[i].w) {
      if (pos2 == i || q[pos2].id != q[pos2 - 1].id) now++;
      int x = q[pos2].u, y = q[pos2].v;
      int fx = find2(x, now), fy = find2(y, now);
      if (fx ^ fy)
        f[fy] = fx;
      else
        ans[q[pos2].id] = 1;
      pos2++;
    }
  }
  for (int i = 1; i <= t; i++) {
    if (ans[i])
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
