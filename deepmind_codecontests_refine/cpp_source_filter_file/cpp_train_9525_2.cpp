#include <bits/stdc++.h>
int n, f[1005][1005], s[1005][1005], used[1005], sz[1005], g[1005], bl[1005],
    cnt = 0;
int issame(int x, int y) {
  for (int i = 1; i <= n; i++)
    if (f[x][i] != s[y][i]) return 0;
  return 1;
}
namespace subtask1 {
void solve() {
  for (int i = 1; i < n; i++) printf("%d %d\n", i, i + 1);
}
}  // namespace subtask1
namespace subtask2 {
void solve() {
  int f1 = 0, g1 = 0, p1 = 0, q1 = 0;
  for (int i = 1; i <= n; i++)
    if (used[i]) {
      p1 = i;
      break;
    }
  for (int i = p1 + 1; i <= n; i++)
    if (used[i]) {
      q1 = i;
      break;
    }
  printf("%d %d\n", p1, q1);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!used[i] && !used[j] && !f[g[i]][j]) f1 = i, g1 = j;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    if (f[g[i]][f1])
      printf("%d %d\n", i, p1);
    else
      printf("%d %d\n", i, q1);
  }
}
}  // namespace subtask2
void getedge(int x, int y) {
  int s1 = 0, s2 = 0, now = 0;
  for (int i = 1; i <= n; i++)
    if (f[x][i] && f[y][i]) {
      if (now == 0)
        s1 = i, now = 1;
      else if (now == 1)
        s2 = i, now = 2;
      else if (now == 2)
        return;
    }
  if (now != 2 || s[s1][s2]) return;
  s[s1][s2] = s[s2][s1] = 1;
  used[s1] = used[s2] = 1;
}
int main() {
  scanf("%d", &n);
  if (n == 2) return puts("1 2"), 0;
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sz[i]);
    if (sz[i] != n) flag = 0;
    for (int j = 1; j <= sz[i]; j++) {
      int x;
      scanf("%d", &x);
      f[i][x] = 1;
    }
  }
  if (flag) return subtask1::solve(), 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) getedge(i, j);
  for (int i = 1; i <= n; i++)
    if (used[i]) ++cnt;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    for (int k = 1; k <= n; k++)
      if (f[k][i] && !bl[k] && (!g[i] || sz[k] < sz[g[i]])) {
        if (g[i]) bl[g[i]] = 0;
        g[i] = k;
        bl[k] = 1;
      }
  }
  if (cnt == 2) return subtask2::solve(), 0;
  for (int i = 1; i <= n; i++)
    if (used[i]) s[i][i] = 1;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    for (int x = 1; x <= n; x++)
      if (!used[x]) f[g[i]][x] = 0;
    for (int k = 1; k <= n; k++)
      if (used[k] && issame(g[i], k)) printf("%d %d\n", i, k);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (s[i][j]) printf("%d %d\n", i, j);
  return 0;
}
