#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  register long long ret = 0;
  while (!(ch >= '0' && ch <= '9')) ch = getchar();
  while (ch >= '0' && ch <= '9')
    ret = (ret << 3) + (ret << 1) + (ch ^ 48), ch = getchar();
  return ret;
}
const long long maxm = 400010;
const long long maxn = 400010;
struct edge {
  long long u, v;
  long long next;
} E[maxm], E1[maxm];
long long p[maxn], eid = 0;
long long p1[maxn], eid1 = 0;
void init() {
  memset(p, -1, sizeof(p));
  memset(p1, -1, sizeof(p1));
  eid = 0;
  eid1 = 0;
}
void insert(long long u, long long v) {
  E[eid].u = u;
  E[eid].v = v;
  E[eid].next = p[u];
  p[u] = eid++;
}
void insertNew(long long u, long long v) {
  E1[eid1].u = u;
  E1[eid1].v = v;
  E1[eid1].next = p1[u];
  p1[u] = eid1++;
}
long long times = 0;
long long dfn[maxn], low[maxn];
long long bcc_cnt = 0;
set<long long> bcc[maxn];
long long bccno[maxn];
stack<edge> S;
long long brgCnt = 0;
long long n, m;
long long pw[maxn];
long long Start;
long long npw[maxn];
bool vis[maxn];
void dfs(long long u, long long fa) {
  dfn[u] = low[u] = ++times;
  long long child = 0;
  for (long long i = p[u]; i != -1; i = E[i].next) {
    long long v = E[i].v;
    if (dfn[v] == 0) {
      S.push(E[i]);
      ++child;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        brgCnt++;
        ++bcc_cnt;
        while (true) {
          edge x = S.top();
          S.pop();
          if (x.u == u && x.v == v) {
            break;
          }
          bcc[bcc_cnt].insert(x.u);
          if (bccno[x.u] == 0) {
            npw[bcc_cnt] += pw[x.u];
          }
          bccno[x.u] = bcc_cnt;
          bcc[bcc_cnt].insert(x.v);
          if (bccno[x.v] == 0) {
            npw[bcc_cnt] += pw[x.v];
          }
          bccno[x.v] = bcc_cnt;
        }
      }
    } else if (dfn[v] < dfn[u] && v != fa) {
      S.push(E[i]);
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (fa < 0 && !S.empty()) {
    ++bcc_cnt;
    while (!S.empty()) {
      edge x = S.top();
      S.pop();
      bcc[bcc_cnt].insert(x.u);
      if (bccno[x.u] == 0) {
        npw[bcc_cnt] += pw[x.u];
      }
      bccno[x.u] = bcc_cnt;
      bcc[bcc_cnt].insert(x.v);
      if (bccno[x.v] == 0) {
        npw[bcc_cnt] += pw[x.v];
      }
      bccno[x.v] = bcc_cnt;
    }
  }
}
long long dp[400010][2];
long long hasR[400010];
void dsp(long long u, long long f) {
  bool noson = true;
  hasR[u] = (!vis[u]);
  long long sum = 0;
  for (register long long i = p1[u]; ~i; i = E1[i].next) {
    long long v = E1[i].v;
    if (v != f) {
      dsp(v, u);
      hasR[u] |= hasR[v];
      sum += dp[v][1];
      noson = false;
    }
  }
  if (noson) {
    if (vis[u] == false) {
      dp[u][0] = npw[u];
      dp[u][1] = npw[u];
      hasR[u] = true;
    } else {
      dp[u][0] = npw[u];
      dp[u][1] = 0;
      hasR[u] = false;
    }
    return;
  }
  dp[u][1] = sum;
  if (hasR[u]) dp[u][1] += npw[u];
  for (register long long i = p1[u]; ~i; i = E1[i].next) {
    long long v = E1[i].v;
    if (v != f) {
      dp[u][0] = max(sum - dp[v][1] + dp[v][0] + npw[u], dp[u][0]);
      dp[u][0] = max(dp[u][0], dp[v][0] + npw[u]);
    }
  }
}
signed main() {
  init();
  n = read(), m = read();
  for (register long long i = 1; i <= n; i++) pw[i] = read();
  if (n == 2) {
    printf("%lld\n", pw[1] + pw[2]);
    return 0;
  }
  for (register long long i = 1; i <= m; i++) {
    long long u = read(), v = read();
    insert(u, v);
    insert(v, u);
  }
  Start = read();
  times = bcc_cnt = 0;
  dfs(1, -1);
  long long tmp = bcc_cnt;
  memset(vis, 0, sizeof vis);
  for (register long long i = 1; i <= n; i++) {
    if (bccno[i] == 0) {
      bccno[i] = ++tmp;
      npw[tmp] = pw[i];
      vis[bccno[i]] = true;
    }
  }
  for (register long long u = 1; u <= n; u++) {
    for (register long long i = p[u]; ~i; i = E[i].next) {
      long long v = E[i].v;
      if (bccno[u] != bccno[v]) {
        insertNew(bccno[u], bccno[v]);
      }
    }
  }
  dsp(bccno[Start], -1);
  printf("%lld\n", max(dp[bccno[Start]][0], dp[bccno[Start]][1]));
  return 0;
}
