#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') w = -w;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * w;
}
template <class T>
inline T read(T& x) {
  return x = read<T>();
}
const int N = 2e3 + 10;
const long long inf = 1e18;
int n, m, a[N];
vector<pair<int, int> > to[N];
long long ds[N], dt[N];
void spfa(int s, long long dis[], int& cnt) {
  static bool vis[N];
  fill(dis + 1, dis + n + 1, inf), fill(vis + 1, vis + n + 1, 0);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  q.push({dis[s] = 0, s});
  while (q.size()) {
    int x = q.top().second;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (const pair<int, int>& e : to[x])
      if (dis[e.first] > dis[x] + e.second)
        q.push({dis[e.first] = dis[x] + e.second, e.first});
  }
  vector<int> val(dis + 1, dis + n + 1);
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  cnt = val.size();
  for (int i = 1; i <= n; ++i)
    dis[i] = lower_bound(val.begin(), val.end(), dis[i]) - val.begin() + 1;
}
int c[N][N], ns[N][N], nt[N][N];
long long s[N][N], f[2][N][N];
int main() {
  read(n), read(m);
  int S = read<int>(), T = read<int>();
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= m; ++i) {
    int x = read<int>(), y = read<int>(), w = read<int>();
    to[x].push_back({y, w}), to[y].push_back({x, w});
  }
  int cs;
  spfa(S, ds, cs);
  int ct;
  spfa(T, dt, ct);
  for (int i = 1; i <= n; ++i) ++c[ds[i]][dt[i]], s[ds[i]][dt[i]] += a[i];
  for (int i = cs; i >= 1; --i)
    for (int j = ct; j >= 1; --j) {
      s[i][j] += s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1];
      ns[i][j] = min(i == cs ? cs : ns[i + 1][j], j == ct ? cs : ns[i][j + 1]);
      nt[i][j] = min(i == cs ? ct : nt[i + 1][j], j == ct ? ct : nt[i][j + 1]);
      if (c[i][j]) ns[i][j] = i, nt[i][j] = j;
      f[0][i][j] = s[i][j] - f[1][ns[i][j] + 1][j];
      f[1][i][j] = s[i][j] - f[0][i][nt[i][j] + 1];
      if (i == 1 and j == 1) continue;
      f[0][i][j] = min(f[0][i][j], f[0][i][j + 1]);
      f[1][i][j] = min(f[1][i][j], f[1][i + 1][j]);
    }
  long long ans = s[1][1] - 2 * f[0][1][1];
  if (ans < 0)
    puts("Break a heart");
  else if (ans > 0)
    puts("Cry");
  else
    puts("Flowers");
  return 0;
}
