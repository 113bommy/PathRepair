#include <bits/stdc++.h>
using namespace std;
struct tree {
  int n;
  long long mn_const;
  long long n1_const;
  long long n2_const;
  long long sx;
  long long total;
  vector<int> g[100500];
  int sum[100500];
  long long s[100500];
  int parent[100500];
  vector<pair<int, pair<int, int> > > e;
  multimap<long long, int> pc[100500];
  map<pair<int, int>, long long> ans;
  void consts(long long a, long long b, long long c) {
    mn_const = a;
    n1_const = b;
    n2_const = c;
  }
  void init();
  void calc_sum(int x, int from);
  int get_sum(int x, int y);
  void make_edge_list();
  void make_steps();
  long long get_min(int x, int from);
  void calc_s(int x, int from);
  long long get_vertex_price(int x);
} t[3];
long long INF;
void tree::init() {
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%i %i", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  calc_sum(1, -1);
  parent[1] = 0;
  make_edge_list();
  make_steps();
  calc_s(1, -1);
  sx = 0;
  for (int i = 1; i <= n; ++i) {
    total += s[i];
    sx = max(sx, s[i]);
  }
  total /= 2;
}
void tree::calc_sum(int x, int from) {
  parent[x] = from;
  sum[x] = 1;
  for (int i = 0; i < g[x].size(); ++i)
    if (g[x][i] != from) {
      calc_sum(g[x][i], x);
      sum[x] += sum[g[x][i]];
      s[x] += s[g[x][i]] + sum[g[x][i]];
    }
}
void tree::calc_s(int x, int from) {
  for (int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if (y == from) continue;
    s[y] = s[x] - get_sum(x, y) + get_sum(y, x);
    calc_s(y, x);
  }
}
int tree::get_sum(int x, int y) {
  if (parent[y] == x) return sum[y];
  return n - sum[x];
}
void tree::make_edge_list() {
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < g[i].size(); ++j) {
      int y = g[i][j];
      int z = get_sum(i, y);
      e.push_back(make_pair(z, make_pair(i, y)));
    }
  sort(e.begin(), e.end());
}
void tree::make_steps() {
  for (int i = 0; i < e.size(); ++i) {
    int x = e[i].second.first;
    int y = e[i].second.second;
    long long value;
    value = mn_const + (get_sum(y, x) - get_sum(x, y)) * n2_const;
    value += get_min(y, x);
    pc[x].insert(make_pair(-value, y));
    ans[make_pair(x, y)] = value;
  }
}
long long tree::get_min(int x, int from) {
  if (pc[x].size() == 0) return 0;
  long long res = 0;
  pair<long long, int> q = *pc[x].begin();
  if (q.second == from) {
    pc[x].erase(pc[x].begin());
    if (pc[x].size() > 0) {
      pair<long long, int> w = *pc[x].begin();
      res = min(w.first, res);
    }
    pc[x].insert(q);
  } else {
    res = min(q.first, res);
  }
  return -res;
}
long long tree::get_vertex_price(int x) {
  if (n == 1) return 0;
  long long res = s[x] * n1_const + s[x] * n2_const;
  pair<long long, int> q = *pc[x].begin();
  res += -q.first;
  return res;
}
long long tryit(tree &t1, tree &t2, tree &t3) {
  long long ans = t1.total + t2.total + t3.total;
  ans += t1.n * (t2.n + t3.n) + t2.n * (t1.n + t3.n);
  ans += t1.sx * (t2.n + t3.n) + t2.sx * (t1.n + t3.n);
  long long tmp = INF;
  for (int i = 1; i <= t3.n; ++i) {
    long long tmp2 = t3.get_vertex_price(i);
    tmp = max(tmp, tmp2);
  }
  ans += tmp;
  return ans;
}
int main() {
  long long ans = 0;
  INF = 1000000000;
  INF = -INF * INF;
  scanf("%i %i %i", &t[0].n, &t[1].n, &t[2].n);
  t[0].consts((long long)t[1].n * (long long)t[2].n, t[1].n, t[2].n);
  t[1].consts((long long)t[0].n * (long long)t[2].n, t[0].n, t[2].n);
  t[2].consts((long long)t[0].n * (long long)t[1].n, t[0].n, t[1].n);
  for (int i = 0; i < 3; ++i) t[i].init();
  ans = max(ans, tryit(t[0], t[1], t[2]));
  ans = max(ans, tryit(t[0], t[2], t[1]));
  ans = max(ans, tryit(t[1], t[2], t[0]));
  cout << ans << endl;
}
