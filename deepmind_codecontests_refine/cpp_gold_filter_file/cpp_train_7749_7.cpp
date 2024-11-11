#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > Edges(406);
int FChild[406], Sibling[406], Parent[406] = {0, -1};
int cost[406][406];
void bfs(int N) {
  bool vis[406] = {false};
  queue<int> Q;
  int now, nxt, fc, sib, i;
  while (!Q.empty()) Q.pop();
  Q.push(1);
  vis[1] = true;
  memset(FChild, -1, sizeof(FChild));
  memset(Sibling, -1, sizeof(Sibling));
  while (!Q.empty()) {
    now = Q.front();
    Q.pop();
    fc = sib = -1;
    for (i = 0; i < Edges[now].size(); ++i) {
      nxt = Edges[now][i];
      if (vis[nxt]) continue;
      vis[nxt] = true;
      if (fc == -1) FChild[now] = nxt;
      if (sib != -1) Sibling[sib] = nxt;
      fc = sib = nxt;
      Parent[nxt] = now;
      Q.push(nxt);
    }
  }
}
int dp[406][406], FCK[406][406];
int rec(int n, int k) {
  if (n == -1) return k ? 100000006 : 0;
  int &ret = dp[n][k];
  if (ret != -1) return ret;
  if (k == 0) {
    FCK[n][k] = 0;
    return ret = 1 + rec(Sibling[n], 0);
  }
  ret = 1 + rec(Sibling[n], k);
  FCK[n][k] = 0;
  int kk, temp;
  for (kk = 1; kk <= k; ++kk) {
    temp = rec(FChild[n], kk - 1) + rec(Sibling[n], k - kk);
    if (temp < ret) {
      ret = temp;
      FCK[n][k] = kk;
    }
  }
  return ret;
}
int rec0(int n, int k) { return (n != 1) + rec(FChild[n], k - 1); }
int ansidx;
vector<int> anslist;
int calc(int N, int K) {
  int ret = 100000006, i, temp;
  memset(dp, -1, sizeof(dp));
  for (i = 1; i <= N; ++i) {
    temp = rec0(i, K);
    if (temp < ret) {
      ret = temp;
      ansidx = i;
    }
  }
  return ret;
}
void preplist(int n, int k) {
  if (n == -1) return;
  int kk = FCK[n][k];
  int p = Parent[n];
  if (k == 0) {
    anslist.push_back(cost[p][n]);
    preplist(Sibling[n], 0);
    return;
  }
  if (kk == 0)
    anslist.push_back(cost[p][n]);
  else
    preplist(FChild[n], kk - 1);
  preplist(Sibling[n], k - kk);
}
void printpath(int N, int K) {
  int idx = ansidx, p, i;
  if (rec0(idx, K) == 0) return;
  anslist.clear();
  if (idx != 1) {
    p = Parent[ansidx];
    anslist.push_back(cost[p][idx]);
  }
  int n = FChild[idx];
  preplist(n, K - 1);
  if (anslist.size()) printf("%d", anslist[0]);
  for (i = 1; i < anslist.size(); ++i) printf(" %d", anslist[i]);
}
int main() {
  int N, K, i, x, y;
  while (scanf("%d %d", &N, &K) != EOF) {
    for (i = 1; i <= N; ++i) Edges[i].clear();
    for (i = 1; i < N; ++i) {
      scanf("%d %d", &x, &y);
      Edges[x].push_back(y);
      Edges[y].push_back(x);
      cost[x][y] = cost[y][x] = i;
    }
    bfs(N);
    printf("%d\n", calc(N, K));
    printpath(N, K);
    puts("");
  }
  return 0;
}
