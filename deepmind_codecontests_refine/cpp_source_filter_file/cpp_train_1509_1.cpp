#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const long long INF = 1e18;
int n, m, S, T, cs, ct;
long long d[N], vis[N], f[2][N][N], c[N][N], s[N][N], ns[N][N], nt[N][N], a[N],
    num[N];
vector<pair<int, int> > e[N];
long long ds[N], dt[N];
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
inline void dijkstra(int s, long long *d, int &c) {
  static priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                        greater<pair<long long, int> > >
      q;
  for (int i = 1; i <= n; ++i) {
    d[i] = INF;
    vis[i] = 0;
  }
  d[s] = 0;
  q.push(make_pair(0, s));
  while (q.size()) {
    int x = q.top().second;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto o : e[x]) {
      int y = o.first, z = o.second;
      if (d[x] + z < d[y]) {
        d[y] = d[x] + z;
        q.push(make_pair(d[y], y));
      }
    }
  }
  for (int i = 1; i <= n; ++i) num[i] = d[i];
  sort(num + 1, num + 1 + n);
  c = unique(num + 1, num + 1 + n) - num - 1;
  for (int i = 1; i <= n; ++i)
    d[i] = lower_bound(num + 1, num + 1 + n, d[i]) - num;
}
int main() {
  read(n), read(m), read(S), read(T);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1, x, y, z; i <= m; ++i) {
    read(x), read(y), read(z);
    e[x].push_back(make_pair(y, z));
    e[y].push_back(make_pair(x, z));
  }
  dijkstra(S, ds, cs);
  dijkstra(T, dt, ct);
  for (int i = 1; i <= n; ++i) ++c[ds[i]][dt[i]], s[ds[i]][dt[i]] += a[i];
  for (int i = cs; i; --i)
    for (int j = ct; j; --j) {
      s[i][j] += s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1];
      ns[i][j] = (i == cs ? cs : ns[i + 1][j], j == ct ? cs : ns[i][j + 1]);
      nt[i][j] = min(i == cs ? ct : nt[i + 1][j], j == ct ? ct : nt[i][j + 1]);
      if (c[i][j]) ns[i][j] = i, nt[i][j] = j;
      f[0][i][j] = s[i][j] - f[1][ns[i][j] + 1][j];
      f[1][i][j] = s[i][j] - f[0][i][nt[i][j] + 1];
      if (i == 1 && j == 1) continue;
      chkmin(f[0][i][j], f[0][i][j + 1]);
      chkmin(f[1][i][j], f[1][i + 1][j]);
    }
  long long ans = s[1][1] - 2 * f[0][1][1];
  if (ans < 0LL)
    printf("Break a heart\n");
  else if (ans > 0)
    printf("Cry\n");
  else
    printf("Flowers\n");
  return 0;
}
