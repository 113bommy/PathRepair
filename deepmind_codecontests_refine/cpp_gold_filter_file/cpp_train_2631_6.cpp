#include <bits/stdc++.h>
using namespace std;
const int N = 1511;
const int sN = 3333;
const int M = N * N;
int n, m, tot, idtot, a[N][N], dd[M][2], id[N], dp[N][N];
int f[sN], ch[sN][2], lef[sN], rig[sN], siz[sN], esiz[sN], flag[sN];
vector<int> ve[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void pd(int x) {
  if (siz[x] * (siz[x] - 1) / 2 == esiz[x]) flag[x] = 1;
}
void dfs(int x) {
  if (x <= n)
    lef[x] = rig[x] = id[x] = ++idtot;
  else
    dfs(ch[x][0]), dfs(ch[x][1]), lef[x] = lef[ch[x][0]],
                                  rig[x] = rig[ch[x][1]];
}
int main() {
  scanf("%d", &n), tot = n;
  for (int i = 1; i <= n * 2 - 1; i++) f[i] = i;
  for (int i = 1; i <= n; i++) siz[i] = 1, flag[i] = 1;
  m = n * (n - 1) / 2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      if (i < j) dd[a[i][j]][0] = i, dd[a[i][j]][1] = j;
    }
  for (int i = 1; i <= m; i++) {
    int ta = find(dd[i][0]), tb = find(dd[i][1]);
    if (tb != ta) {
      ++tot, f[ta] = tot, f[tb] = tot;
      siz[tot] = siz[ta] + siz[tb];
      esiz[tot] = esiz[ta] + esiz[tb] + 1;
      pd(tot), ch[tot][0] = ta, ch[tot][1] = tb;
    } else
      esiz[ta]++, pd(ta);
  }
  dfs(tot);
  for (int i = 1; i <= n * 2 - 1; i++)
    if (flag[i]) ve[rig[i]].push_back(lef[i]);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int x : ve[i])
      for (int j = 1; j <= n; j++) (dp[i][j] += dp[x - 1][j - 1]) %= 998244353;
  for (int i = 1; i <= n; i++) printf("%d ", dp[n][i]);
  puts("");
  return 0;
}
