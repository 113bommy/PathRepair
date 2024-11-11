#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const long long inf = 1e18;
const int N = 2005;
long long f[N][N], g[N][N], s[N][N], c[N][N];
long long w[N], x[N], y[N], X[N], Y[N];
int n, m, S, T, cx, cy;
vector<pair<int, int> > e[N];
void dij(int s, long long d[]) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      Q;
  fill(d + 1, d + n + 1, inf);
  Q.push(make_pair(d[s] = 0, s));
  while (!Q.empty()) {
    int u = Q.top().second;
    long long dis = Q.top().first;
    Q.pop();
    if (d[u] != dis) continue;
    for (auto v : e[u])
      if (d[u] + v.second < d[v.first])
        Q.push(make_pair(d[v.first] = d[u] + v.second, v.first));
  }
}
void init() {
  dij(S, x), dij(T, y);
  X[++cx] = inf, Y[++cy] = inf;
  for (int i = (1); i <= (n); i++) X[++cx] = x[i], Y[++cy] = y[i];
  sort(X + 1, X + cx + 1);
  cx = unique(X + 1, X + cx + 1) - X;
  sort(Y + 1, Y + cy + 1);
  cy = unique(Y + 1, Y + cy + 1) - Y;
  for (int i = (1); i <= (n); i++) {
    x[i] = lower_bound(X + 1, X + cx + 1, x[i]) - X;
    y[i] = lower_bound(Y + 1, Y + cy + 1, y[i]) - Y;
    s[x[i]][y[i]] += w[i];
    c[x[i]][y[i]] += 1;
  }
  for (int i = (cx); i >= (1); i--)
    for (int j = (cy); j >= (1); j--) {
      s[i][j] += s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1];
      c[i][j] += c[i + 1][j] + c[i][j + 1] - c[i + 1][j + 1];
    }
}
long long solve() {
  for (int i = (cx); i >= (1); i--)
    for (int j = (cy); j >= (1); j--) {
      if (c[i][j] == c[i + 1][j]) {
        f[i][j] = f[i + 1][j];
      } else {
        f[i][j] = max(f[i + 1][j] + s[i][j] - s[i + 1][j],
                      s[i][j] - s[i + 1][j] - g[i + 1][j]);
      }
      if (c[i][j] == c[i][j + 1]) {
        g[i][j] = g[i][j + 1];
      } else {
        g[i][j] = max(g[i][j + 1] + s[i][j] - s[i][j + 1],
                      s[i][j] - s[i][j + 1] - f[i][j + 1]);
      }
    }
  return f[1][1];
}
int main() {
  read(n), read(m);
  read(S), read(T);
  for (int i = (1); i <= (n); i++) read(w[i]);
  for (int i = (1); i <= (m); i++) {
    int a, b, c;
    read(a), read(b), read(c);
    e[a].push_back(make_pair(b, c));
    e[b].push_back(make_pair(a, c));
  }
  init();
  long long res = solve();
  if (res > 0)
    puts("Break a heart");
  else if (res < 0)
    puts("Cry");
  else
    puts("Flowers");
  return 0;
}
