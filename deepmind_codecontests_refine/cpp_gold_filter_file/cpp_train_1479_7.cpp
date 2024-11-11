#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
int n;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int vis[100005];
vector<int> G[100001];
long long cost[100005][3];
int fin(int v) {
  for (int i = 0; i < G[v].size(); i++) {
    if (!vis[G[v][i]]) return G[v][i];
  }
  return -1;
}
int main() {
  int seq[][3] = {{1, 2, 3}, {3, 2, 1}, {1, 3, 2},
                  {2, 3, 1}, {2, 1, 3}, {3, 1, 2}};
  int i, j, fl = 0, test;
  scanf("%d", &n);
  for (j = 0; j < 3; j++)
    for (i = 1; i <= n; i++) {
      scanf("%lld", &cost[i][j]);
    }
  for (i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
    if (G[x].size() > 2 || G[y].size() > 2) {
      fl = 1;
    }
  }
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    if (G[i].size() == 1) {
      j = i;
      cnt++;
    }
  }
  if (cnt != 2) {
    fl = 1;
  }
  if (fl)
    printf("-1\n");
  else {
    long long mini = INT_MAX * 10000000ll;
    int ans = 0;
    int anss[100005] = {0};
    for (i = 0; i < 6; i++) {
      memset(vis, 0, sizeof(vis));
      long long sm = 0;
      int curr = j;
      for (cnt = 0; cnt < n; cnt++) {
        sm = sm + cost[curr][seq[i][cnt % 3] - 1];
        vis[curr] = 1;
        anss[curr] = cnt;
        curr = fin(curr);
      }
      if (mini > sm) {
        mini = sm;
        ans = i;
      }
    }
    printf("%lld\n", mini);
    for (int i = 1; i <= n; i++) {
      printf("%d ", seq[ans][anss[i] % 3]);
    }
    printf("\n");
  }
  return 0;
}
