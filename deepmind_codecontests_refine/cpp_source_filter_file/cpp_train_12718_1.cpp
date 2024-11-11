#include <bits/stdc++.h>
using namespace std;
long long n;
long long head[1100000], a[1100000];
struct node {
  long long v, nex;
} bian[2100000];
long long cnt;
void add(long long x, long long y) {
  bian[++cnt].v = y;
  bian[cnt].nex = head[x];
  head[x] = cnt;
}
long long tot[1100000], d[1100000], f[1100000], zong;
void dfs(long long x, long long fa) {
  tot[x] = 1;
  for (long long i = head[x]; i; i = bian[i].nex) {
    long long v = bian[i].v;
    if (v == fa) continue;
    dfs(v, x);
    tot[x] += tot[v];
  }
  f[1] += tot[x];
}
long long ans = 0;
void dp(long long x, long long fa) {
  ans = max(ans, f[x]);
  for (long long i = head[x]; i; i = bian[i].nex) {
    long long v = bian[i].v;
    if (v == fa) continue;
    f[v] = f[x] - tot[v] + tot[x] - tot[v];
    dp(v, x);
  }
}
signed main() {
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  dp(1, 0);
  cout << ans << endl;
}
