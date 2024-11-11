#include <bits/stdc++.h>
using namespace std;
const int maxn = 501010;
vector<int> q;
vector<pair<int, long long> > adj[maxn];
int u[maxn], d[maxn];
long long size[maxn], D[maxn], TreeAns[maxn];
int Cycle[maxn];
long long Dis[maxn], Len = 0LL;
long long SumSize[maxn], Sum[maxn], SumDis[maxn];
long long ans[maxn], Candy;
int n, tot, Cur;
void dfs(int x) {
  u[x] = 1;
  size[x] = 1LL;
  TreeAns[x] = 0LL;
  for (int i = 0; i < adj[x].size(); i++) {
    int j = adj[x][i].first;
    if (!u[j] && d[j] == 1) {
      D[j] = D[x] + adj[x][i].second;
      dfs(j);
      size[x] += size[j];
      TreeAns[x] += adj[x][i].second * size[j] + TreeAns[j];
    }
  }
}
void dp(int x, int Rt) {
  u[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    int j = adj[x][i].first;
    if (!u[j] && d[j] == 1) {
      TreeAns[j] = TreeAns[x];
      TreeAns[j] += (size[Rt] - size[j]) * adj[x][i].second;
      TreeAns[j] -= size[j] * adj[x][i].second;
      ans[j] = TreeAns[j] + (ans[Rt] - TreeAns[Rt]);
      ans[j] += ((long long)n - size[Rt]) * D[j];
      dp(j, Rt);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) adj[i].clear();
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; i++) {
    int x, y;
    long long w;
    scanf("%d%d%I64d", &x, &y, &w);
    adj[x].push_back(make_pair(y, w));
    adj[y].push_back(make_pair(x, w));
    d[x]++;
    d[y]++;
  }
  q.clear();
  for (int i = 1; i <= n; i++)
    if (d[i] == 1) q.push_back(i);
  for (int f = 0; f < q.size(); f++) {
    int x = q[f];
    for (int i = 0; i < adj[x].size(); i++) {
      if (d[adj[x][i].first] == 1) continue;
      d[adj[x][i].first]--;
      if (d[adj[x][i].first] == 1) q.push_back(adj[x][i].first);
    }
  }
  for (int i = 1; i <= n; i++)
    if (d[i] > 1) {
      tot = 1;
      Cycle[tot] = i;
      break;
    }
  for (int i = 0; i < adj[Cycle[1]].size(); i++)
    if (d[adj[Cycle[1]][i].first] > 1) {
      Dis[tot] = adj[Cycle[1]][i].second;
      Cycle[++tot] = adj[Cycle[1]][i].first;
      break;
    }
  for (;;) {
    int cur = Cycle[tot], next;
    for (int i = 0; i < adj[cur].size(); i++) {
      int j = adj[cur][i].first;
      if (d[j] > 1 && j != Cycle[tot - 1]) {
        Dis[tot] = adj[cur][i].second;
        next = j;
        break;
      }
    }
    if (next == Cycle[1]) break;
    Cycle[++tot] = next;
  }
  for (int i = tot + 1; i < tot * 2; i++)
    Cycle[i] = Cycle[i - tot], Dis[i] = Dis[i - tot];
  tot *= 2;
  tot--;
  memset(u, 0, sizeof(u));
  for (int i = 1; i <= tot / 2 + 1; i++) D[Cycle[i]] = 0, dfs(Cycle[i]);
  for (int i = 1; i <= tot / 2 + 1; i++) Len += Dis[i];
  memset(ans, 0, sizeof(ans));
  memset(SumSize, 0, sizeof(SumSize));
  for (int i = tot; i; i--) SumSize[i] = SumSize[i + 1] + size[Cycle[i]];
  memset(SumDis, 0, sizeof(SumDis));
  for (int i = tot - 1; i; i--) SumDis[i] = SumDis[i + 1] + Dis[i];
  memset(Sum, 0, sizeof(Sum));
  for (int i = tot - 1; i; i--) Sum[i] = Sum[i + 1] + Dis[i] * SumSize[i + 1];
  Cur = 1;
  for (int i = 1; i <= tot / 2 + 1; i++) {
    while (Cur < tot && (SumDis[i] - SumDis[Cur + 1]) * 2LL < Len) Cur++;
    ans[Cycle[i]] += Sum[i] - Sum[Cur];
    ans[Cycle[i]] -= (SumDis[i] - SumDis[Cur]) * SumSize[Cur + 1];
  }
  memset(SumSize, 0, sizeof(SumSize));
  for (int i = 1; i <= tot; i++) SumSize[i] = SumSize[i - 1] + size[Cycle[i]];
  memset(SumDis, 0, sizeof(SumDis));
  for (int i = 2; i <= tot; i++) SumDis[i] = SumDis[i - 1] + Dis[i - 1];
  memset(Sum, 0, sizeof(Sum));
  for (int i = 2; i <= tot; i++)
    Sum[i] = Sum[i - 1] + Dis[i - 1] * SumSize[i - 1];
  Cur = tot;
  for (int i = tot; i > tot / 2; i--) {
    while (Cur > 1 && (SumDis[i] - SumDis[Cur - 1]) * 2LL <= Len) Cur--;
    ans[Cycle[i]] += Sum[i] - Sum[Cur];
    ans[Cycle[i]] -= (SumDis[i] - SumDis[Cur]) * SumSize[Cur - 1];
  }
  Candy = 0LL;
  for (int i = 1; i <= tot / 2 + 1; i++) Candy += TreeAns[Cycle[i]];
  for (int i = 1; i <= tot / 2 + 1; i++) ans[Cycle[i]] += Candy;
  memset(u, 0, sizeof(u));
  for (int i = 1; i <= tot / 2 + 1; i++) dp(Cycle[i], Cycle[i]);
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%I64d", ans[i]);
  }
  printf("\n");
  return 0;
}
