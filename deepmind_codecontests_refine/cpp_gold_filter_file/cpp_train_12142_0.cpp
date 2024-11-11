#include <bits/stdc++.h>
using namespace std;
char s[120];
int ans1, pre[120], ma[120][120], ans2, num[120];
int n, la[120], lb[120], vb[120], va[120], delta;
bool dfs(int u) {
  va[u] = 1;
  for (int i = 1; i <= n; i++) {
    if (ma[u][i] == -1) continue;
    if (vb[i] == 0) {
      if (la[u] + lb[i] - ma[u][i] == 0) {
        vb[i] = 1;
        if (pre[i] == 0 || dfs(pre[i])) {
          pre[i] = u;
          return true;
        }
      } else
        delta = min(delta, la[u] + lb[i] - ma[u][i]);
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i], num[s[i] - 'a']++;
  for (int i = 0; i <= 25; i++) {
    if (num[i] > (n + 1) / 2) {
      cout << "-1";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> ma[i][i];
    if (i > (n + 1) / 2 && s[i] == s[n - i + 1]) ma[i][n - i + 1] = -1;
    if (i <= n / 2 && s[i] == s[n - i + 1])
      ma[i][n - i + 1] = ma[i][i], ma[i][i] = -1;
    for (int j = 1; j <= n; j++) {
      if (s[j] == s[i] && ma[i][n - j + 1] == 0) ma[i][n - j + 1] = -1;
      la[i] = max(ma[i][j], la[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    while (1) {
      memset(va, 0, sizeof(va));
      memset(vb, 0, sizeof(vb));
      delta = 1 << 30;
      if (dfs(i)) break;
      for (int j = 1; j <= n; j++) {
        if (va[j] == 1) la[j] -= delta;
        if (vb[j] == 1) lb[j] += delta;
      }
    }
  }
  for (int i = 1; i <= n; i++) ans1 += ma[pre[i]][i];
  cout << ans1;
  return 0;
}
