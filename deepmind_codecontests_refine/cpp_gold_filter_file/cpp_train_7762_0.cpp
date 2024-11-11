#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 10;
vector<int> g[maxn];
int is[maxn];
int grp[maxn];
int cnt[maxn];
int wa[maxn];
void dfs(int x, int c) {
  if (grp[x]) return;
  grp[x] = c;
  cnt[c]++;
  if (is[x]) wa[c] = 1;
  for (int y : g[x]) {
    dfs(y, c);
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  memset(is, 0, sizeof(is));
  memset(wa, 0, sizeof(wa));
  memset(grp, 0, sizeof(grp));
  for (int i = 1; i <= k; i++) {
    int tmp;
    scanf("%d", &tmp);
    is[tmp] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int id = 0;
  for (int i = 1; i <= n; i++) {
    if (!grp[i]) {
      dfs(i, ++id);
    }
  }
  int Max = 0;
  int ans = 0;
  int ino = 0;
  for (int i = 1; i <= id; i++) {
    if (!wa[i]) ino += cnt[i];
  }
  for (int i = 1; i <= id; i++) {
    if (wa[i]) Max = max(Max, cnt[i]);
  }
  ans -= ino * Max;
  for (int i = 1; i <= id; i++) {
    for (int j = i + 1; j <= id; j++) {
      if (!wa[i] && !wa[j]) continue;
      ans += cnt[i] * cnt[j];
    }
  }
  printf("%d\n", max(0, n * (n - 1) / 2 - m - ans));
}
