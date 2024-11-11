#include <bits/stdc++.h>
using namespace std;
int dp[35][105][((105) * (105 + 1)) / 2];
int dir[35][105][((105) * (105 + 1)) / 2];
int n, ara[35];
int solve(int now, int k, int sum) {
  if ((k * (k - 1)) / 2 > sum) return 105;
  if (now == n) {
    if (sum == (k * (k - 1)) / 2) return 0;
    return 105;
  }
  int &ret = dp[now][k][sum];
  if (ret != -1) return ret;
  ret = 105;
  for (int i = 1; k + i < 105; i++) {
    if (i >= ret) break;
    int tmp = i + solve(now + 1, k + i, sum + i * ara[now]);
    if (tmp < ret) {
      ret = tmp;
      dir[now][k][sum] = i;
    }
  }
  return ret;
}
int deg[105];
void go(int now, int k, int sum) {
  if (now == n) return;
  for (int i = 0; i < dir[now][k][sum]; i++) deg[k + i] = ara[now];
  go(now + 1, k + dir[now][k][sum], sum + ara[now] * dir[now][k][sum]);
}
const int MAX_E = 60003;
const int MAX_V = 5003;
int ver[MAX_E], cap[MAX_E], nx[MAX_E], last[MAX_V], ds[MAX_V], st[MAX_V],
    now[MAX_V], edge_count, S, T;
inline void reset() {
  memset(nx, -1, sizeof(nx));
  memset(last, -1, sizeof(last));
  edge_count = 0;
}
inline void addedge(const int v, const int w, const int capacity,
                    const int reverse_capacity) {
  ver[edge_count] = w;
  cap[edge_count] = capacity;
  nx[edge_count] = last[v];
  last[v] = edge_count++;
  ver[edge_count] = v;
  cap[edge_count] = reverse_capacity;
  nx[edge_count] = last[w];
  last[w] = edge_count++;
}
inline bool bfs() {
  memset(ds, -1, sizeof(ds));
  int a, b;
  a = b = 0;
  st[0] = T;
  ds[T] = 0;
  while (a <= b) {
    int v = st[a++];
    for (int w = last[v]; w >= 0; w = nx[w]) {
      if (cap[w ^ 1] > 0 && ds[ver[w]] == -1) {
        st[++b] = ver[w];
        ds[ver[w]] = ds[v] + 1;
      }
    }
  }
  return ds[S] >= 0;
}
int dfs(int v, int cur) {
  if (v == T) return cur;
  for (int &w = now[v]; w >= 0; w = nx[w]) {
    if (cap[w] > 0 && ds[ver[w]] == ds[v] - 1) {
      int d = dfs(ver[w], min(cur, cap[w]));
      if (d) {
        cap[w] -= d;
        cap[w ^ 1] += d;
        return d;
      }
    }
  }
  return 0;
}
inline long long flow() {
  long long res = 0;
  while (bfs()) {
    for (int i = 0; i < MAX_V; i++) now[i] = last[i];
    while (1) {
      int tf = dfs(S, 2000000000);
      res += tf;
      if (!tf) break;
    }
  }
  return res;
}
int mat[105][105];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &ara[i]);
  sort(ara, ara + n);
  memset(dp, -1, sizeof(dp));
  int nd = solve(0, 0, 0);
  if (nd == 105) {
    printf("=(\n");
    return 0;
  }
  go(0, 0, 0);
  reset();
  int cnt = 1, bam = (nd * (nd - 1)) / 2;
  S = 0;
  T = bam + 1 + nd;
  for (i = 0; i < nd; i++) {
    for (j = i + 1; j < nd; j++) {
      addedge(S, cnt, 1, 0);
      addedge(cnt, i + bam + 1, 1, 0);
      addedge(cnt, j + bam + 1, 1, 0);
      cnt++;
    }
  }
  for (i = 0; i < nd; i++) addedge(bam + i + 1, T, deg[i], 0);
  flow();
  cnt = 0;
  for (i = 0; i < nd; i++) {
    for (j = i + 1; j < nd; j++) {
      cnt += 2;
      if (!cap[cnt])
        mat[j][i] = 1;
      else
        mat[i][j] = 1;
      cnt += 4;
    }
  }
  printf("%d\n", nd);
  for (i = 0; i < nd; i++) {
    for (j = 0; j < nd; j++) printf("%d", mat[i][j]);
    printf("\n");
  }
  return 0;
}
