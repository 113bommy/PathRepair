#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
const int N = 400001;
int a[N];
long long int ST[2000000];
int lazy[2000000];
vector<int> visit;
vector<int> euler;
void dfs(int start) {
  euler.push_back(start);
  visit[start] = 1;
  for (int i = 0; i < graph[start].size(); ++i)
    if (visit[graph[start][i]] == 0) dfs(graph[start][i]);
  euler.push_back(start);
}
void construct(int pos, int begin, int end) {
  if (begin == end) {
    ST[pos] = 1ll << a[euler[begin]];
    return;
  }
  int mid = (begin + end) / 2;
  construct(pos * 2, begin, mid);
  construct(pos * 2 + 1, mid + 1, end);
  ST[pos] = ST[pos * 2] | ST[pos * 2 + 1];
}
void add(int pos, int begin, int end) {
  if (lazy[pos] == 0) return;
  ST[pos] = 1 << lazy[pos];
  if (begin != end) {
    lazy[pos * 2] = lazy[pos];
    lazy[pos * 2 + 1] = lazy[pos];
  }
  lazy[pos] = 0;
}
void update(int pos, int begin, int end, int l, int r, int color) {
  add(pos, begin, end);
  if (begin > r || end < l) return;
  if (begin >= l && end <= r) {
    lazy[pos] = color;
    add(pos, begin, end);
    return;
  }
  int mid = (begin + end) / 2;
  update(pos * 2, begin, mid, l, r, color);
  update(pos * 2 + 1, mid + 1, end, l, r, color);
  ST[pos] = ST[pos * 2] | ST[pos * 2 + 1];
}
long long int find(int pos, int begin, int end, int l, int r) {
  add(pos, begin, end);
  if (begin > r || end < l) return (long long int)0;
  if (begin >= l && end <= r) return ST[pos];
  int mid = (begin + end) / 2;
  return find(pos * 2, begin, mid, l, r) |
         find(pos * 2 + 1, mid + 1, end, l, r);
}
int main() {
  long long int res;
  int n, m, i, x, y, order, l, r;
  scanf("%d %d", &n, &m);
  visit.assign(n + 1, 0);
  graph.assign(n + 1, vector<int>());
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (i = 1; i < 4 * n; ++i) lazy[i] = 0;
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &x, &y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  dfs(1);
  construct(1, 0, euler.size() - 1);
  vector<pair<int, int> > p;
  for (i = 0; i <= n; ++i) p.push_back(make_pair(-1, 0));
  for (i = 0; i < euler.size(); ++i) {
    if (p[euler[i]].first == -1)
      p[euler[i]].first = i;
    else
      p[euler[i]].second = i;
  }
  for (i = 1; i <= m; ++i) {
    scanf("%d %d", &order, &x);
    l = p[x].first;
    r = p[x].second;
    if (order == 1) {
      scanf("%d", &y);
      update(1, 0, euler.size() - 1, l, r, y);
    }
    if (order == 2) {
      res = __builtin_popcountll(find(1, 0, euler.size() - 1, l, r));
      printf("%d\n", res);
    }
  }
}
