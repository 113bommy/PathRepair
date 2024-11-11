#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int k, cnt, tot;
int a[20][N], b[20], tmp[N * 20];
long long sum[20], SS;
map<long long, int> mp;
int id[N * 20], E[1 << 16];
vector<int> G[N * 20], Q[1 << 16];
int vis[N * 20], look[1 << 16], dp[1 << 16];
int pre[1 << 16], l[20], r[20];
void dfs(int x, int statu) {
  if (vis[x]) {
    int now = 0;
    for (int i = tot; i; i--) {
      now |= b[id[E[i]] - 1];
      if (x == E[i]) break;
    }
    if (!look[now]) {
      look[now] = 1;
      for (int i = tot; i; i--) {
        Q[now].push_back(E[i]);
        if (E[i] == x) break;
      }
    }
    return;
  }
  if (statu & b[id[x] - 1]) return;
  statu |= b[id[x] - 1];
  vis[x] = 1;
  E[++tot] = x;
  for (int i = 0; i < G[x].size(); i++) {
    dfs(G[x][i], statu);
  }
  vis[x] = 0;
  --tot;
}
int main() {
  b[0] = 1;
  for (int i = 1; i <= 16; i++) b[i] = b[i - 1] * 2;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a[i][0]);
    for (int j = 1; j <= a[i][0]; j++) {
      scanf("%d", &a[i][j]);
      sum[i] += a[i][j];
      mp[a[i][j]] = ++cnt;
      id[cnt] = i;
      tmp[cnt] = a[i][j];
    }
    SS += sum[i];
  }
  if (SS % k) {
    puts("No");
    return 0;
  }
  SS /= k;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= a[i][0]; j++) {
      if (mp[SS - (sum[i] - a[i][j])]) {
        G[mp[SS - (sum[i] - a[i][j])]].push_back(mp[mp[a[i][j]]]);
      }
    }
  }
  for (int i = 1; i <= cnt; i++) dfs(i, 0);
  dp[0] = 1;
  for (int i = 0; i < b[k]; i++) {
    if (dp[i]) {
      int M = i ^ (b[k] - 1);
      for (int j = M; j; j = (j - 1) & M) {
        if (look[j]) {
          dp[i | j] = 1;
          pre[i | j] = i;
        }
      }
    }
  }
  if (!dp[b[k] - 1]) {
    puts("No");
    return 0;
  }
  int x = b[k] - 1;
  while (x) {
    int T = x - pre[x];
    for (int i = 0; i < Q[T].size(); i++) {
      l[id[mp[SS - sum[id[Q[T][i]]] + tmp[Q[T][i]]]]] =
          SS - sum[id[Q[T][i]]] + tmp[Q[T][i]];
      r[id[mp[SS - sum[id[Q[T][i]]] + tmp[Q[T][i]]]]] = id[Q[T][i]];
    }
    x = pre[x];
  }
  puts("Yes");
  for (int i = 1; i <= k; i++) {
    printf("%d %d\n", l[i], r[i]);
  }
  return 0;
}
