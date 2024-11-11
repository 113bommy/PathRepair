#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 7, MAXM = 1e6 + 7;
struct Edge {
  long long end, upEd, f, c;
} Ed[MAXM];
long long head[MAXN], a[51], b[51], c[51], l[51], r[51], ind[51][207];
long long N, M, S, T, cntEd = 1;
queue<long long> q;
inline void addEd(long long a, long long b, long long c, long long d = 0) {
  Ed[++cntEd].end = b;
  Ed[cntEd].upEd = head[a];
  Ed[cntEd].f = c;
  Ed[cntEd].c = d;
  head[a] = cntEd;
}
inline void addE(long long a, long long b, long long c, long long d = 0,
                 bool f = 0) {
  addEd(a, b, c, d);
  addEd(b, a, c * f, -d);
}
long long cur[MAXN], dep[MAXN];
inline bool bfs() {
  while (!q.empty()) q.pop();
  q.push(S);
  memset(dep, 0, sizeof(dep));
  dep[S] = 1;
  while (!q.empty()) {
    long long t = q.front();
    q.pop();
    for (long long i = head[t]; i; i = Ed[i].upEd)
      if (Ed[i].f && !dep[Ed[i].end]) {
        dep[Ed[i].end] = dep[t] + 1;
        if (Ed[i].end == T) {
          memcpy(cur, head, sizeof(head));
          return 1;
        }
        q.push(Ed[i].end);
      }
  }
  return 0;
}
inline long long dfs(long long x, long long mF) {
  if (x == T) return mF;
  long long sum = 0;
  for (long long &i = cur[x]; i; i = Ed[i].upEd)
    if (Ed[i].f && dep[Ed[i].end] == dep[x] + 1) {
      long long t = dfs(Ed[i].end, min(mF - sum, Ed[i].f));
      if (t) {
        Ed[i].f -= t;
        Ed[i ^ 1].f += t;
        sum += t;
        if (sum == mF) break;
      }
    }
  return sum;
}
long long Dinic() {
  long long ans = 0;
  while (bfs()) ans += dfs(S, 1e13);
  return ans;
}
inline long long calc(long long tp, long long x) {
  return a[tp] * x * x + b[tp] * x + c[tp];
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> N >> M;
  for (long long i = 1; i <= N; ++i) cin >> a[i] >> b[i] >> c[i];
  T = 1e5;
  long long cnt = 0;
  for (long long i = 1; i <= N; ++i) {
    cin >> l[i] >> r[i];
    for (long long j = 0; j <= 200; ++j) ind[i][j] = ++cnt;
    addE(S, ind[i][0], l[i] == -100 ? 1e10 - calc(i, -100) : 1e13);
    addE(ind[i][200], T, 1e13);
    for (long long j = 1; j <= 200; ++j)
      addE(ind[i][j - 1], ind[i][j],
           j - 100 >= l[i] && j - 100 <= r[i] ? 1e10 - calc(i, j - 100) : 1e13);
  }
  while (M--) {
    long long a, b, c;
    cin >> a >> b >> c;
    for (long long i = max(0ll, c); i <= min(200ll, 200 + c); ++i)
      addE(ind[a][i], ind[b][i - c], 1e13);
    if (c <= 0) {
      addE(S, ind[b][-c], 1e13);
      addE(ind[a][200 + c], T, 1e13);
    }
  }
  cout << (long long)(N * 1e10 - Dinic());
  return 0;
}
