#include <bits/stdc++.h>
using namespace std;
const long long N = 777;
long long n, k, m;
map<pair<long long, long long>, long long> mp;
long long cost[N][N], cap[N][N], p[N], d[N], par[N];
bool used[N];
bool use[N];
long long otv[N];
long long s, t;
long long inf = 1e9;
void ford() {
  p[0] = 0;
  for (long long i = 1; i <= m; i++) {
    p[i] = inf;
  }
  for (long long ii = 0; ii < 2 * m; ii++) {
    for (long long i = 0; i <= m; i++) {
      for (long long j = 0; j <= m; j++) {
        if (p[i] < inf && cap[i][j] != 0) {
          p[j] = min(p[j], p[i] + cost[i][j]);
        }
      }
    }
  }
}
bool dijkstra() {
  for (long long i = 0; i <= m; i++) {
    d[i] = inf;
    used[i] = 0;
  }
  d[0] = 0;
  while (true) {
    long long mn = inf;
    long long v = -1;
    for (long long i = 0; i <= m; i++) {
      if (!used[i] && d[i] < mn) {
        mn = d[i];
        v = i;
      }
    }
    if (v == -1) {
      break;
    }
    used[v] = 1;
    for (long long i = 0; i <= m; i++) {
      if (used[i]) {
        continue;
      }
      long long w = cost[v][i] + p[v] - p[i];
      if (cap[v][i] != 0 && d[i] > d[v] + w) {
        d[i] = d[v] + w;
        par[i] = v;
      }
    }
  }
  return d[t] < inf;
}
long long solve() {
  ford();
  long long ans = 0;
  while (dijkstra()) {
    for (long long i = 0; i <= m; i++) {
      p[i] += d[i];
    }
    long long flow = inf;
    long long x = t;
    while (x != s) {
      flow = min(flow, cap[par[x]][x]);
      x = par[x];
    }
    x = t;
    while (x != s) {
      cap[par[x]][x] -= flow;
      cap[x][par[x]] += flow;
      ans = ans + flow * cost[par[x]][x];
      x = par[x];
    }
  }
  return abs(ans);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s1, s2;
  cin >> n >> k >> s1 >> s2;
  m = 2 * k + 1;
  for (long long i = 0; i < n; i++) {
    long long x = s1[i] - ('a') + 1;
    long long y = s2[i] - ('a') + 1;
    if (x < 1 || x > 26) {
      x = s1[i] - ('A') + 1 + 26;
    }
    if (y < 1 || y > 26) {
      y = s1[i] - ('A') + 1 + 26;
    }
    mp[{x, y}]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    long long x = it->first.first;
    long long y = it->first.second;
    long long price = it->second;
    cost[x][y + k] = -price;
    cost[y + k][x] = price;
    cap[x][y + k] = 1;
    cap[y + k][x] = 0;
  }
  s = 0, t = 2 * k + 1;
  for (long long i = 1; i <= k; i++) {
    cap[0][i] = 1;
  }
  for (long long i = k + 1; i <= k + k; i++) {
    cap[i][t] = 1;
  }
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= k; j++) {
      if (mp[{i, j}] == 0) {
        cap[i][k + j] = 1;
      }
    }
  }
  cout << solve() << "\n";
  for (long long i = 1; i <= k; i++) {
    for (long long j = k + 1; j <= k + k; j++) {
      if (cap[i][j] == 0 && cap[j][i] != 0) {
        otv[i] = j - k;
        use[j - k] = 1;
      }
    }
  }
  for (long long i = 1; i <= k; i++) {
    if (otv[i] == 0) {
      for (long long j = 1; j <= k; j++) {
        if (!use[j]) {
          use[j] = 1;
          otv[i] = j;
          break;
        }
      }
    }
  }
  for (long long i = 1; i <= k; i++) {
    char c;
    if (i <= 26) {
      c = otv[i] + ('a') - 1;
    } else {
      c = otv[i] - 26 + ('A') - 1;
    }
    cout << c;
  }
  return 0;
}
