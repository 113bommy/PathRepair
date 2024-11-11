#include <bits/stdc++.h>
using namespace std;
const int MaxN = 605;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const long long LINF = 1000000000000000005ll;
int n, m, K, mod;
int source[MaxN], sink[MaxN];
long long dp[MaxN][MaxN], mat[MaxN][MaxN];
long long *a[MaxN];
bool isS[MaxN], isT[MaxN];
vector<int> edge[MaxN];
long long calc(int a, int b) {
  long long &rt = dp[a][b];
  if (rt != -1) return rt;
  if (a == b) return 1;
  rt = 0;
  for (vector<int>::iterator it = edge[b].begin(); it != edge[b].end(); ++it) {
    rt += calc(a, *it);
    if (rt >= mod) rt -= mod;
  }
  return rt;
}
long long fpow(long long a, long long t, long long mod) {
  long long rt = 1;
  a %= mod;
  for (; t; t >>= 1, a = a * a % mod)
    if (t & 1) rt = rt * a % mod;
  return rt;
}
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  memset(isT, 1, sizeof(isT));
  memset(isS, 1, sizeof(isS));
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    edge[v].push_back(u);
    isT[u] = 0;
    isS[v] = 0;
  }
  memset(source, -1, sizeof(source));
  memset(sink, -1, sizeof(sink));
  K = 0;
  for (int i = 0; i < n; ++i)
    if (isS[i]) source[i] = K++;
  K = 0;
  for (int i = 0; i < n; ++i)
    if (isT[i]) sink[i] = K++;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; ++i)
    if (source[i] != -1)
      for (int j = 0; j < n; ++j)
        if (sink[j] != -1) mat[source[i]][sink[j]] = calc(i, j);
  for (int i = 0; i < K; ++i) a[i] = mat[i];
  long long ans = 1;
  for (int i = 0; i < K; ++i) {
    int x = -1;
    for (int k = i; k < K; ++k)
      if (a[k][i]) {
        x = k;
        break;
      }
    if (x == -1) {
      ans = 0;
      break;
    }
    if (i != x) {
      ans = mod - ans;
      swap(a[i], a[x]);
    }
    ans = ans * a[i][i] % mod;
    long long inv = fpow(a[i][i], mod - 2, mod);
    for (int j = 0; j < K; ++j) a[i][j] = a[i][j] * inv % mod;
    for (int j = i + 1; j < K; ++j) {
      if (!a[j][i]) continue;
      long long t = a[j][i];
      for (int k = i; k < K; ++k) {
        a[j][k] = a[j][k] - a[i][k] * t;
        a[j][k] %= mod;
        if (a[j][k] < 0) a[j][k] += mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
