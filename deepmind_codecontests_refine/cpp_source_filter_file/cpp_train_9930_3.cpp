#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > G;
void stop() {
  printf("unknown topology\n");
  exit(0);
}
void star() {
  int ind = -1, mxd = 0;
  for (int i = 0; i < n; i++) {
    if (ind == -1 || mxd < G[i].size()) {
      ind = i;
      mxd = G[i].size();
    }
  }
  int cnt = 0;
  for (int i = 0; i < G[ind].size(); i++) {
    cnt++;
    int to = G[ind][i];
    if (G[to].size() != 1) {
      stop();
    }
  }
  if (cnt != n - 1) stop();
  printf("star topology\n");
}
void bus() {
  int ind = -1, mxd = 0;
  for (int i = 0; i < n; i++) {
    if (G[i].size() == 1) {
      ind = i;
      break;
    }
  }
  int cnt = 0;
  int cur = G[ind][0];
  int last = ind;
  for (int i = 1; i <= n - 1; i++) {
    if ((G[cur].size() != 2 && i != n - 1) ||
        (i == n - 1 && G[cur].size() != 1))
      stop();
    int to = G[cur][0];
    if (to == last) to = G[cur][1];
    last = cur;
    cur = to;
  }
  printf("bus topology\n");
}
bool used[100100];
int dfs(int v) {
  used[v] = 1;
  int res = 1;
  for (int i = 0; i < (int)G[v].size(); i++)
    if (!used[G[v][i]]) res += dfs(G[v][i]);
  return res;
}
void ring() {
  for (int i = 0; i < n; i++)
    if (G[i].size() != 2) stop();
  int res = dfs(0);
  if (res != n) stop();
  printf("ring topopogy\n");
}
int main() {
  scanf("%d %d", &n, &m);
  G.resize(n);
  for (int i = 0; i < m; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    G[from].push_back(to);
    G[to].push_back(from);
  }
  int mxd = 0, mnd = n;
  for (int i = 0; i < n; i++) {
    mxd = max(mxd, (int)G[i].size());
    mnd = min(mnd, (int)G[i].size());
  }
  if (mxd == n - 1 && mnd == 1 && m == n - 1)
    star();
  else if (mxd == 2 && mnd == 1 && m == n - 1)
    bus();
  else if (mxd == 2 && mnd == 2 && m == n)
    ring();
  else
    printf("unknown topology\n");
  return 0;
}
