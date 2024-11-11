#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 500000;
int n;
vector<int> adj[MAXN];
int par[MAXN];
int sz[MAXN];
long long mem[MAXN];
void dfsinit(int at) {
  sz[at] = 1;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    par[to] = at;
    dfsinit(to);
    sz[at] += sz[to];
  }
}
pair<long long, long long> q[MAXN];
int qhead, qtail;
pair<int, long long> opt[MAXN];
int nopt;
long long eval(const pair<long long, long long> &z, int x) {
  return z.first * x + z.second;
}
long long overtake(const pair<long long, long long> &a,
                   const pair<long long, long long> &b) {
  assert(a.first > b.first);
  assert(a.second < b.second);
  return (b.second - a.second + a.first - b.first - 1) / (a.first - b.first);
}
pair<long long, long long> dfscalc(int at) {
  pair<long long, long long> ret =
      make_pair((long long)sz[at] * sz[at], (long long)n * n);
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    pair<long long, long long> sub = dfscalc(to);
    ret.first =
        min(ret.first,
            (long long)(sz[at] - sz[to]) * (sz[at] - sz[to]) + sub.first);
    ret.second = min(ret.second, sub.second);
    ret.second =
        min(ret.second, (long long)(n - sz[to]) * (n - sz[to]) + sub.first);
    mem[to] = sub.first;
  }
  nopt = 0;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    opt[nopt++] = make_pair(sz[to], mem[to]);
  }
  for (int i = (0); i < (nopt); ++i) {
    int x = opt[i].first;
    long long y = opt[i].second;
    opt[i].second = y + (long long)x * x - (long long)2 * n * x;
  }
  sort(opt, opt + nopt);
  qhead = qtail = 0;
  for (int i = (0); i < (nopt); ++i) {
    int x = opt[i].first;
    long long y = opt[i].second;
    while (qhead - 2 >= qtail && eval(q[qhead - 2], x) <= eval(q[qhead - 1], x))
      --qhead;
    if (qhead - 1 >= qtail) {
      long long cur = eval(q[qhead - 1], x) + y + (long long)n * n;
      ret.second = min(ret.second, cur);
    }
    pair<long long, long long> z = make_pair(2LL * x, y);
    bool ok = true;
    while (true) {
      if (qhead - 1 >= qtail && z.second >= q[qhead - 1].second) {
        ok = false;
        break;
      }
      if (qhead - 2 >= qtail &&
          overtake(z, q[qhead - 1]) >= overtake(q[qhead - 1], q[qhead - 2])) {
        --qhead;
        continue;
      }
      break;
    }
    if (ok) q[qhead++] = z;
  }
  return ret;
}
long long solve() {
  if (n == 2) return 2;
  int root = -1;
  for (int at = (0); at < (n); ++at)
    if (((int)(adj[at]).size()) >= 2) {
      root = at;
      break;
    }
  assert(root != -1);
  par[root] = -1;
  dfsinit(0);
  long long ret = 0;
  for (int at = (0); at < (n); ++at) {
    ret += (long long)sz[at] * sz[at] - 1;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par[at]) continue;
      ret -= (long long)sz[to] * sz[to];
    }
  }
  ret += (long long)n * n - dfscalc(root).second;
  assert(ret % 2 == 0);
  ret /= 2;
  return ret;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  printf("%lld\n", solve());
}
void stress() {
  n = MAXN;
  for (int i = (0); i < (n - 1); ++i) {
    int a = i, b = i + 1;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  long long have = solve();
  printf("have=%lld\n", have);
}
int main() {
  stress();
  return 0;
}
