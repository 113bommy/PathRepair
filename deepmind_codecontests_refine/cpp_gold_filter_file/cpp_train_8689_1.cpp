#include <bits/stdc++.h>
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
using namespace ::std;
const long long maxz = 22;
const long long maxn = maxz * maxz * 4 + 5;
const long long inf = 1e9 * maxn;
const long long maxm = maxn * maxn / 4;
long long s[maxm];
long long t[maxm];
long long flow[maxm];
vector<long long> out[maxm];
long long tab[maxn];
long long poi[maxn];
long long dfs(long long v, long long tt, long long fl) {
  if (v == tt || fl == 0) {
    return fl;
  }
  long long ans = 0;
  for (; poi[v] < out[v].size();) {
    long long e = out[v][poi[v]];
    if (tab[t[e]] == tab[v] + 1 && flow[e] != 0) {
      long long mir = min(flow[e], fl);
      long long res = dfs(t[e], tt, mir);
      flow[e] -= res;
      flow[e ^ 1] += res;
      ans += res;
      fl -= res;
      if (mir != res) {
        poi[v]++;
      }
    } else {
      poi[v]++;
    }
    if (fl == 0) {
      break;
    }
  }
  return ans;
}
bool bfs(long long ss, long long tt) {
  queue<long long> qu;
  fill(tab, tab + maxn, -1);
  fill(poi, poi + maxn, 0);
  qu.push(ss);
  tab[ss] = 0;
  while (qu.size()) {
    long long v = qu.front();
    qu.pop();
    for (auto e : out[v]) {
      if (tab[t[e]] == -1 && flow[e] != 0) {
        tab[t[e]] = tab[v] + 1;
        qu.push(t[e]);
      }
    }
  }
  return (tab[tt] != -1);
}
long long max_flow(long long ss, long long tt) {
  long long ans = 0;
  while (bfs(ss, tt)) {
    ans += dfs(ss, tt, inf);
  }
  return ans;
}
long long cn = 0;
void add_yal(long long a, long long b, long long w) {
  t[cn] = b;
  s[cn] = a;
  flow[cn] = w;
  out[a].push_back(cn);
  cn++;
  t[cn] = a;
  s[cn] = b;
  flow[cn] = 0;
  out[b].push_back(cn);
  cn++;
}
char c[maxn][maxn];
long long x[maxn];
long long y[maxn];
long long speed[maxn];
long long fas[maxz][maxz][maxz][maxz];
inline bool is_zarb_kam_tar_az(long long a, long long b, long long c) {
  if (a > c) return 0;
  return (a * b <= c);
}
bool good(long long X, long long n, long long m, long long r) {
  long long mas2 = n * m * 2;
  long long ss = mas2 + 2 * r + 1;
  long long tt = mas2 + 2 * r + 2;
  for (long long i = 0; i < r; i++) {
    add_yal(ss, mas2 + i, 1);
    for (long long a = 0; a < n; a++) {
      for (long long b = 0; b < m; b++) {
        if (is_zarb_kam_tar_az(fas[x[i]][y[i]][a][b], speed[i], X)) {
          add_yal(mas2 + i, (a * m + b) * 2, 1);
        }
      }
    }
  }
  for (long long i = 0; i < mas2; i += 2) {
    add_yal(i, i + 1, 1);
  }
  for (long long i = r; i < 2 * r; i++) {
    add_yal(mas2 + i, tt, 1);
    for (long long a = 0; a < n; a++) {
      for (long long b = 0; b < m; b++) {
        if (is_zarb_kam_tar_az(fas[x[i]][y[i]][a][b], speed[i], X)) {
          add_yal((a * m + b) * 2 + 1, mas2 + i, 1);
        }
      }
    }
  }
  long long res = max_flow(ss, tt);
  bool ans = (res == r);
  cn = 0;
  for (long long i = 0; i < mas2 + 2 * r + 3; i++) {
    out[i].clear();
  }
  return ans;
}
long long n, m;
queue<pair<long long, long long> > qu;
long long AA, BB;
void add(long long a, long long b, long long w) {
  if (a < 0 || a >= n || b < 0 || b >= m || c[a][b] == '#' ||
      fas[AA][BB][a][b] != inf) {
    return;
  }
  fas[AA][BB][a][b] = w;
  qu.push(make_pair(a, b));
}
void bfs_tor(long long a, long long b) {
  AA = a;
  BB = b;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      fas[a][b][i][j] = inf;
    }
  }
  if (c[a][b] == '#') return;
  qu.push(make_pair(a, b));
  fas[a][b][a][b] = 0;
  while (qu.size()) {
    pair<long long, long long> e = qu.front();
    qu.pop();
    long long w = fas[a][b][e.first][e.second] + 1;
    add(e.first, e.second + 1, w);
    add(e.first, e.second - 1, w);
    add(e.first + 1, e.second, w);
    add(e.first - 1, e.second, w);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long r, C;
  cin >> n >> m >> r >> C;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  if (r + 1 != C && C + 1 != r) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < r + C + 1; i++) {
    cin >> x[i] >> y[i] >> speed[i];
    x[i]--;
    y[i]--;
  }
  if (r + 1 == C) {
    r++;
  } else {
    swap(x[0], x[r + C + 1]);
    swap(y[0], y[r + C + 1]);
    swap(speed[0], speed[r + C + 1]);
    for (long long i = 0; i < r + C + 1; i++) {
      x[i] = x[i + 1];
      y[i] = y[i + 1];
      speed[i] = speed[i + 1];
    }
    C++;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      bfs_tor(i, j);
    }
  }
  if (r != C) {
    exit(1);
  }
  if (!good(inf - 1, n, m, r)) {
    cout << -1;
    return 0;
  }
  long long be = -1;
  long long en = inf;
  while (en - be > 1) {
    long long mid = (en + be) / 2;
    if (good(mid, n, m, r)) {
      en = mid;
    } else {
      be = mid;
    }
  }
  cout << en;
}
