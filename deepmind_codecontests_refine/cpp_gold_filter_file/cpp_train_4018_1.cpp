#include <bits/stdc++.h>
using namespace std;
int n, k, mx;
int a[4000400], q[4000400], dis[2005];
bool vis[2005];
int head[2005], edgenum;
struct Edge {
  int to, nxt;
} edge[4000400];
inline void add(int u, int v) {
  edge[++edgenum].to = v;
  edge[edgenum].nxt = head[u];
  head[u] = edgenum;
}
inline void read(int &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = 10 * x + c - '0';
    c = getchar();
  }
  x *= f;
}
bitset<2004> dp[2];
inline int solve() {
  int t = 1;
  dp[0][1000] = 1;
  for (int i = 1; i <= 1000; i++) {
    dp[t].reset();
    for (int j = 1; j <= k; j++)
      if (a[j] > 0)
        dp[t] |= dp[t ^ 1] << a[j];
      else
        dp[t] |= dp[t ^ 1] >> (-a[j]);
    if (dp[t][1000] == 1) return i;
    t ^= 1;
  }
  return -1;
}
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= k; i++) read(a[i]);
  for (int i = 1; i <= k; i++) vis[a[i]] = 1;
  int l = 0;
  for (int i = 0; i <= 1000; i++)
    if (vis[i]) a[++l] = i;
  for (int i = 1; i <= l; i++) a[i] -= n;
  k = l;
  printf("%d", solve());
  return 0;
}
