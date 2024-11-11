#include <bits/stdc++.h>
using namespace std;
vector<long long> v[100001], adj[100001];
long long P[100001][32];
vector<long long> best[100001][32];
long long L[100001];
long long n, m, q;
vector<long long> combine(const vector<long long>& a,
                          const vector<long long>& b) {
  vector<long long> out;
  merge((a).begin(), (a).end(), (b).begin(), (b).end(), back_inserter(out));
  auto it = unique((out).begin(), (out).end());
  out.resize(distance(out.begin(), it));
  out.resize(min(10LL, (long long)out.size()));
  return move(out);
}
void dfs(long long u, long long p, long long level) {
  P[u][0] = p;
  L[u] = level;
  for (long long v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, level + 1);
  }
}
long long computeLog(long long x) {
  if (x == 0) return -1;
  long long i;
  for (i = 1; (1 << i) <= x; i++)
    ;
  return i;
}
long long LCA(long long p, long long q) {
  if (L[p] < L[q]) swap(p, q);
  long long logP = computeLog(L[p]);
  for (long long i = logP; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q]) p = P[p][i];
  }
  if (p == q) return p;
  logP = computeLog(L[p]);
  for (long long i = logP; i >= 0; i--) {
    if (P[p][i] != -1 && P[p][i] != P[q][i]) {
      p = P[p][i];
      q = P[q][i];
    }
  }
  return P[p][0];
}
vector<long long> query(long long a, long long b) {
  if (a == b) return {};
  long long logB = computeLog(L[b]);
  vector<long long> out;
  for (long long i = logB; i >= 0; i--) {
    if (L[b] - (1 << i) >= L[a]) {
      out = combine(out, best[b][i]);
      b = P[b][i];
    }
  }
  return move(out);
}
int main() {
  memset(P, -1, sizeof(P));
  n = ({
    long long x;
    scanf("%lld", &x);
    x;
  }),
  m = ({
    long long x;
    scanf("%lld", &x);
    x;
  }),
  q = ({
    long long x;
    scanf("%lld", &x);
    x;
  });
  for (long long i = 0; i < n - 1; i++) {
    long long a = ({
      long long x;
      scanf("%lld", &x);
      x;
    }),
              b = ({
                long long x;
                scanf("%lld", &x);
                x;
              });
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (long long i = 0; i < m; i++) {
    long long x = ({
      long long x;
      scanf("%lld", &x);
      x;
    });
    best[x][0].push_back(i + 1);
  }
  for (long long i = 1; i <= n; i++) {
    sort((best[i][0]).begin(), (best[i][0]).end());
    auto it = unique((best[i][0]).begin(), (best[i][0]).end());
    best[i][0].resize(distance(best[i][0].begin(), it));
    best[i][0].resize(min(10LL, (long long)best[i][0].size()));
  }
  dfs(1, -1, 0);
  for (long long j = 1; (1 << j) < n; j++) {
    for (long long i = 1; i <= n; i++) {
      if (P[i][j - 1] != -1) {
        P[i][j] = P[P[i][j - 1]][j - 1];
        best[i][j] = combine(best[i][j - 1], best[P[i][j - 1]][j - 1]);
      }
    }
  }
  while (q--) {
    long long a = ({
      long long x;
      scanf("%lld", &x);
      x;
    }),
              b = ({
                long long x;
                scanf("%lld", &x);
                x;
              }),
              k = ({
                long long x;
                scanf("%lld", &x);
                x;
              });
    long long ab = LCA(a, b);
    vector<long long> ans = combine(query(ab, a), query(ab, b));
    ans = combine(ans, best[ab][0]);
    printf("%lld ", min(k, (long long)ans.size()));
    for (long long i = 0; i < k; i++) {
      if (ans.size() == i) break;
      printf("%lld ", ans[i]);
    }
    puts("");
  }
}
