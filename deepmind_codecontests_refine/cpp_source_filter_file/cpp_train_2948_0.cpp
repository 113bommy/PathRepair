#include <bits/stdc++.h>
using namespace std;
const int maxn = 400000;
struct Queue {
  vector<int> st1, st2;
  vector<int> mx1, mx2;
  Queue() { clear(); }
  void clear() {
    st1.clear();
    st2.clear();
    mx1.clear();
    mx2.clear();
  }
  void add(int x) {
    int mx = x;
    if (!st2.empty()) mx = max(mx, mx2.back());
    st2.push_back(x);
    mx2.push_back(mx);
  }
  void add1(int x) {
    int mx = x;
    if (!st1.empty()) mx = max(mx, mx1.back());
    st1.push_back(x);
    mx1.push_back(mx);
  }
  void pop() {
    if (st1.empty()) {
      while (!st2.empty()) {
        add1(st2.back());
        st2.pop_back();
        mx2.pop_back();
      }
    }
    if (!st1.empty()) {
      st1.pop_back();
      mx1.pop_back();
    }
  }
  int Max() {
    int mx = -(1 << 30);
    if (!st1.empty()) mx = max(mx1.back(), mx);
    if (!st2.empty()) mx = max(mx2.back(), mx);
    return mx;
  }
} Q;
vector<vector<pair<int, int> > > gi, g;
vector<pair<int, int> > order;
int L, R, n, T[maxn], Ta[maxn], ans, size[maxn], weight, pos2, pos, cnt[maxn];
void CalcSize(int v, int parent) {
  size[v] = 1;
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it) {
    int to = it->first;
    if (to == parent) continue;
    CalcSize(to, v);
    size[v] += size[to];
  }
}
int get(int v, int parent) {
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it) {
    int to = it->first;
    if (to == parent) continue;
    if (size[to] > (n >> 1)) return get(to, v);
  }
  return v;
}
void upd_ans(int tmp, int v) {
  if (ans < tmp) {
    ans = tmp;
    pos = v;
  }
}
void Calc(int v, int parent, int dep, int sum) {
  upd_ans(Ta[dep] + sum, v);
  if (ans >= 0) return;
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it) {
    int to = it->first;
    if (to == parent) continue;
    Calc(to, v, dep + 1, sum + it->second);
  }
}
void upd(int v, int parent, int dep, int sum) {
  T[dep] = max(T[dep], sum);
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it) {
    int to = it->first;
    if (to == parent) continue;
    upd(to, v, dep + 1, sum + it->second);
  }
}
void Solve(int v) {
  CalcSize(v, -1);
  n = size[v];
  if (n < L) return;
  for (int i = 1; i <= n; ++i) T[i] = -(1 << 30), Ta[i] = -(1 << 30);
  T[0] = Ta[0] = 0;
  v = get(v, -1);
  for (int i = 0; i <= n; ++i) cnt[i] = 0;
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it)
    cnt[size[it->first]]++;
  for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
  order.resize(g[v].size());
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it)
    order[--cnt[size[it->first]]] = *it;
  for (typeof(order.begin()) it = order.begin(); it != order.end(); ++it) {
    int to = it->first;
    int l = max(L - 1, 0), r = min(R - 1, size[to]);
    Q.clear();
    for (int i = r; i >= l; --i) Q.add(T[i]);
    Ta[1] = max(Ta[1], Q.Max());
    for (int dep = 2; dep <= size[to]; ++dep) {
      if (r >= 0 && R - dep < r) {
        Q.pop();
        --r;
      }
      if (L - dep >= 0)
        Q.add(T[L - dep]);
      else
        break;
      Ta[dep] = max(Ta[dep], Q.Max());
    }
    Calc(to, v, 1, it->second);
    if (ans >= 0) return;
    upd(to, v, 1, it->second);
  }
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it) {
    int to = it->first;
    int w = it->second;
    int pos = -1;
    for (int i = 0; i < g[to].size(); ++i)
      if (g[to][i].first == v) pos = i;
    swap(g[to][pos], g[to][(int)g[to].size() - 1]);
    g[to].pop_back();
    Solve(to);
    g[to].push_back(make_pair(v, w));
    swap(g[to][pos], g[to][(int)g[to].size() - 1]);
  }
}
bool Ok(int x) {
  g = gi;
  n = gi.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < g[i].size(); ++j)
      if (g[i][j].second < x)
        g[i][j].second = -1;
      else
        g[i][j].second = 1;
  }
  ans = -(1 << 30);
  Solve(0);
  return (ans >= 0);
}
bool Dfs(int v, int parent, int len, int sum) {
  if (L <= len && len <= R && sum >= 0) {
    pos2 = v;
    return true;
  }
  for (typeof(gi[v].begin()) it = gi[v].begin(); it != gi[v].end(); ++it) {
    int to = it->first;
    if (to == parent) continue;
    if (it->second < weight)
      Dfs(to, v, len + 1, sum - 1);
    else if (Dfs(to, v, len + 1, sum + 1))
      return true;
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &L, &R);
  gi.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, cost;
    scanf("%d%d%d", &u, &v, &cost);
    u--;
    v--;
    gi[u].push_back(make_pair(v, cost));
    gi[v].push_back(make_pair(u, cost));
  }
  int l = 0, r = (1 << 30) + 1000;
  while (r - 1 > l) {
    int mid = (l + r) >> 1;
    if (Ok(mid))
      l = mid;
    else
      r = mid;
  }
  Ok(l);
  weight = l;
  Dfs(pos, -1, 0, 0);
  cout << pos + 1 << " " << pos2 + 1 << endl;
  return 0;
}
