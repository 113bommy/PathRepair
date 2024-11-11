#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long M = 250010;
long long n, dp[M][2], X, out[M], vis[M];
vector<pair<long long, long long> > e[M];
pair<long long, long long> p[M];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return out[a.first] > out[b.first];
}
struct heap {
  priority_queue<long long> q1, q2;
  long long sz, sum;
  void add(long long first) { q1.push(first), sz++, sum += first; }
  void del(long long first) { q2.push(first), sz--, sum -= first; }
  void pre() {
    while (q1.size() && q2.size() && q1.top() == q2.top()) q1.pop(), q2.pop();
  }
  long long size() { return sz; }
  long long top() {
    pre();
    return q1.top();
  }
  void pop() { pre(), sz--, sum -= q1.top(), q1.pop(); }
} h[M];
void del(long long u) {
  for (long long i = 0; i < e[u].size(); i++) {
    long long to = e[u][i].first, w = e[u][i].second;
    if (out[to] <= X) break;
    h[to].add(w);
  }
}
void dfs(long long u, long long fa) {
  long long num = out[u] - X, res = 0;
  vis[u] = X;
  vector<long long> v1, v2;
  v1.clear(), v2.clear();
  while (h[u].size() > num) h[u].pop();
  for (long long i = 0; i < e[u].size(); i++) {
    long long to = e[u][i].first, w = e[u][i].second;
    if (out[to] <= X) break;
    if (to == fa) continue;
    dfs(to, u);
    res += dp[to][0];
    long long first = dp[to][1] + w - dp[to][0];
    if (first < 0)
      num--, res += first;
    else
      h[u].add(first), v1.push_back(first);
  }
  while (h[u].size() && h[u].size() > num) v2.push_back(h[u].top()), h[u].pop();
  dp[u][0] = h[u].sum + res;
  while (h[u].size() && h[u].size() > num - 1)
    v2.push_back(h[u].top()), h[u].pop();
  dp[u][1] = h[u].sum + res;
  for (long long i = 0; i < v2.size(); i++) h[u].add(v2[i]);
  for (long long i = 0; i < v1.size(); i++) h[u].del(v1[i]);
}
signed main() {
  n = read();
  long long sum = 0;
  for (long long i = 1; i < n; i++) {
    long long u = read(), v = read(), w = read();
    e[u].push_back(make_pair(v, w)), e[v].push_back(make_pair(u, w));
    out[u]++, out[v]++, sum += w;
  }
  for (long long i = 1; i <= n; i++)
    sort(e[i].begin(), e[i].end(), cmp), p[i] = make_pair(out[i], i);
  sort(p + 1, p + 1 + n);
  printf("%lld", sum);
  for (long long l = 1, i = 1; i < n; i++) {
    long long ans = 0;
    X = i;
    while (l <= n && p[l].first == i) del(p[l].second), l++;
    for (long long i = l; i <= n; i++) {
      long long u = p[i].second;
      if (vis[u] == X) continue;
      dfs(u, 0);
      ans += dp[u][1];
    }
    printf("% lld", ans);
  }
  return 0;
}
