#include <bits/stdc++.h>
using namespace std;
const int MAXB = 17;
const int MAXN = 100100;
const long long INF = 1LL << 40;
struct DisjointSet {
  int p[MAXN];
  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
  int root(int i) { return p[i] = p[i] == i ? i : root(p[i]); }
  bool setp(int i, int j) {
    i = root(i);
    j = root(j);
    if (i != j) {
      p[i] = j;
      return true;
    } else {
      return false;
    }
  }
} ds;
vector<pair<int, long long> > e[MAXN];
vector<pair<long long, pair<int, int> > > ex;
int d[MAXN];
pair<int, long long> p[MAXN][MAXB];
void dfs(int u, int v) {
  for (int i = 1; i < MAXB; ++i) {
    const pair<int, long long>& q = p[p[u][i - 1].first][i - 1];
    p[u][i].first = q.first;
    p[u][i].second = max(p[u][i - 1].second, q.second);
  }
  for (vector<pair<int, long long> >::const_iterator it = e[u].begin();
       it != e[u].end(); ++it) {
    int w = it->first;
    if (w == v) {
      continue;
    }
    d[w] = d[u] + 1;
    p[w][0].first = u;
    p[w][0].second = it->second;
    dfs(w, u);
  }
}
pair<int, long long> up(int u, int n) {
  long long second = 0;
  for (int i = 0; n > 0; ++i) {
    if (n % 2 != 0) {
      second = max(second, p[u][i].second);
      u = p[u][i].first;
    }
    n >>= 1;
  }
  return make_pair(u, second);
}
long long gao(int u, int v) {
  int l = 0, r = min(d[u], d[v]) + 1, m;
  while (l < r) {
    m = (l + r) / 2;
    if (up(u, d[u] - m).first == up(v, d[v] - m).first) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  m = l - 1;
  return max(up(u, d[u] - m).second, up(v, d[v] - m).second);
}
int main() {
  int n, m, a, b, c;
  long long sum, ans;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    ex.push_back(make_pair(INF, make_pair(i - 1, i)));
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    ex.push_back(make_pair(c, make_pair(a - 1, b - 1)));
  }
  sort(ex.begin(), ex.end());
  ds.init(n);
  sum = 0;
  for (vector<pair<long long, pair<int, int> > >::const_iterator it =
           ex.begin();
       it != ex.end(); ++it) {
    if (ds.setp(it->second.first, it->second.second)) {
      sum += it->first;
      e[it->second.first].push_back(make_pair(it->second.second, it->first));
      e[it->second.second].push_back(make_pair(it->second.first, it->first));
    }
  }
  d[0] = 0;
  p[0][0] = make_pair(0, 0);
  dfs(0, -1);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    ans = sum - gao(a - 1, b - 1);
    printf("%I64d\n", ans < INF ? ans : -1LL);
  }
  return 0;
}
