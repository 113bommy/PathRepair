#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
vector<int> G[N];
int n;
int belo[N];
int cnt[N][4], cnt2[N][4];
void dfs(int u, int fa) {
  for (int i = 0; i < 4; i++) cnt[u][i] = 0;
  int sum = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    sum++;
    dfs(v, u);
    cnt[u][belo[v]]++;
  }
  if (!sum || (sum == 1 && cnt[u][0]))
    belo[u] = 0;
  else if (sum == 2 && cnt[u][0] == 2)
    belo[u] = 1;
  else if (cnt[u][3] == 0 && cnt[u][2] <= 1)
    belo[u] = 2;
  else
    belo[u] = 3;
}
int get(int sum, int cc[4]) {
  if (!sum || (sum == 1 && cc[0])) return 0;
  if (sum == 2 && cc[0] == 2) return 1;
  if (cc[3] == 0 && cc[2] <= 1) return 2;
  return 3;
}
bool dfs2(int u, int fa, int is) {
  for (int i = 0; i < 4; i++) cnt2[u][i] = cnt[u][i];
  int sum = 0;
  if (fa != -1) cnt2[u][is]++, sum++;
  for (int i = 0; i < G[u].size(); i++)
    if (G[u][i] != fa) sum++;
  belo[u] = get(sum, cnt2[u]);
  if (belo[u] < 3 || (cnt2[u][3] == 0 && cnt2[u][2] <= 2)) return true;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    int tmp = belo[v];
    cnt2[u][tmp]--;
    int cur = get(sum - 1, cnt2[u]);
    if (dfs2(v, u, cur)) return true;
    cnt2[u][tmp]++;
  }
  return false;
}
bool solve() {
  dfs(0, -1);
  if (belo[0] < 3 || (cnt[0][3] == 0 && cnt[0][2] <= 2)) return true;
  if (dfs2(0, -1, 0)) return true;
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  puts(solve() ? "Yes" : "No");
  return 0;
}
