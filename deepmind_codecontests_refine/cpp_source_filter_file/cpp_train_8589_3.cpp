#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 2e5 + 10;
long long n;
long long x, y;
struct Node {
  int p;
  int pre;
} edg[N * 2];
int last[N], T = 0;
int father[N];
int dp[N][3];
int cnt[N];
long long maxlength = 0;
long long ans;
long long cntp[N];
void addedge(int u, int v) {
  T++;
  edg[T].p = v;
  edg[T].pre = last[u];
  last[u] = T;
}
void init() {
  int u, v;
  cin >> n >> x >> y;
  for (long long i = 1; i <= n; i++) last[i] = -1;
  for (long long i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    addedge(u, v);
    addedge(v, u);
    cntp[u]++;
    cntp[v]++;
  }
  maxlength = 0;
}
void dfs(int u) {
  for (int i = last[u]; i != -1; i = edg[i].pre) {
    int v = edg[i].p;
    if (v == father[u]) continue;
    father[v] = u;
    dfs(v);
    dp[u][0] += max(dp[v][0], max(dp[v][1], dp[v][2]));
    if (max(dp[v][0], dp[v][1]) >= dp[v][2]) cnt[u]++;
  }
  dp[u][1] = dp[u][0];
  if (cnt[u] >= 1) dp[u][1] = dp[u][0] + 1;
  if (cnt[u] >= 2) dp[u][2] = dp[u][0] + 2;
  for (int i = 0; i <= 2; i++)
    maxlength = max(maxlength, 1LL * (dp[u][i]) * 1LL);
}
void work() {
  if (x == y)
    ans = n * x;
  else if (x < y) {
    dfs(1);
    ans = maxlength * x + y * (n - maxlength - 1LL);
  } else {
    ans = -1;
    for (long long i = 1; i <= n; i++)
      if (cntp[i] == n - 1LL) {
        ans = x + y * (n - 2LL);
        break;
      }
    if (ans == -1) ans = y * (n - 1LL);
  }
  printf("%I64d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
