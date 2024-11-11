#include <bits/stdc++.h>
using namespace std;
template <class _T>
_T MAX(_T a, _T b) {
  return a > b ? a : b;
}
template <class _T>
_T MIN(_T a, _T b) {
  return a < b ? a : b;
}
template <class _T>
_T GCD(_T a, _T b) {
  return b ? gcd(b, a % b) : a;
}
const int N = 3001;
set<long long int> f;
int vis[N][N], ans[N];
vector<int> adj[N];
queue<pair<pair<int, int>, int> > q;
long long mask(int a, int b, int c) { return 1000LL * (a * 1000 + b) + c; }
int main(void) {
  int a, b, c, k, m, n;
  scanf("%d %d %d", &n, &m, &k);
  int depth = -1, prev, x;
  bool over = false;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ++n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) vis[i][j] = -1;
  for (int i = 0; i < k; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    f.insert(mask(a, b, c));
  }
  vis[0][1] = 0;
  q.push(make_pair(make_pair(0, 1), 0));
  while (!q.empty()) {
    int d, next, u, v, z;
    d = q.front().second;
    u = q.front().first.first;
    v = q.front().first.second;
    q.pop();
    z = adj[v].size();
    for (int i = 0; i < z; ++i) {
      next = adj[v][i];
      if (f.find(mask(u, v, next)) == f.end() && vis[v][next] < 0) {
        vis[v][next] = u;
        q.push(make_pair(make_pair(v, next), d + 1));
        over |= next == n - 1;
      }
    }
    if (over) {
      depth = d + 1;
      prev = v;
      x = n - 1;
      break;
    }
  }
  printf("%d\n", depth++);
  for (int i = depth; i--;) {
    ans[i] = x;
    a = prev;
    prev = vis[prev][x];
    x = a;
  }
  for (int i = 0; i < depth; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
