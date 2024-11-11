#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long maxn = 5e5 + 50, N = 2e6 + 10, SQRT = 300, base = 607583,
                mod = 1e9 + 7, INF = 1e18 + 1, lg = 25;
const long double eps = 1e-4;
struct node {
  long long mx, id;
  node() { mx = -INF; }
};
node seg[4 * maxn];
long long n, a[maxn], b[maxn], res[maxn];
vector<long long> topol;
bool mark[maxn];
inline node merge(node a, node b) {
  node res;
  res.mx = max(a.mx, b.mx);
  if (a.mx == res.mx) {
    res.id = a.id;
  }
  if (b.mx == res.mx) {
    res.id = b.id;
  }
  return res;
}
void build(long long v = 1, long long s = 0, long long e = n) {
  if (e - s == 1) {
    seg[v].mx = b[s];
    seg[v].id = s;
    return;
  }
  build(2 * v, s, (s + e) / 2);
  build(2 * v + 1, (s + e) / 2, e);
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
void modify(long long p, long long v = 1, long long s = 0, long long e = n) {
  if (e - s == 1) {
    seg[v].mx = -INF;
    return;
  }
  if (p < (s + e) / 2) {
    modify(p, 2 * v, s, (s + e) / 2);
  } else {
    modify(p, 2 * v + 1, (s + e) / 2, e);
  }
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
node get(long long l, long long r, long long v = 1, long long s = 0,
         long long e = n) {
  if (l >= e || s >= r) {
    return node();
  }
  if (l <= s && e <= r) {
    return seg[v];
  }
  node a = get(l, r, 2 * v, s, (s + e) / 2);
  node b = get(l, r, 2 * v + 1, (s + e) / 2, e);
  return merge(a, b);
}
void dfs(long long v) {
  mark[v] = 1;
  if (!mark[b[v]]) {
    dfs(b[v]);
  }
  node curr = get(0, a[v]);
  while (curr.mx >= b[v]) {
    if (!mark[curr.id]) {
      dfs(curr.id);
    }
    modify(curr.id);
    curr = get(0, a[v]);
  }
  topol.push_back(v);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fill(b, b + maxn, n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == -1) {
      a[i] = n + 1;
    }
    a[i]--;
    b[a[i]] = i;
  }
  build();
  mark[n] = 1;
  for (long long i = 0; i < n; ++i) {
    if (!mark[i]) {
      dfs(i);
    }
  }
  for (long long i = 0; i < n; ++i) {
    res[topol[i]] = i;
  }
  for (long long i = 0; i < n; ++i) {
    cout << res[i] + 1 << ' ';
  }
  cout << '\n';
}
