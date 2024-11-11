#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int N = 200005;
int a[100][100], n, m, ans[100][100];
bool vis[N];
bool XL(int x, int y) {
  if (x > y) swap(x, y);
  return ((y - x) % m == 0) || ((x % m != 0) && (x + 1 == y));
}
bool dfs(int r, int c, int u) {
  a[r][c] = u;
  vis[u] = true;
  if (r == n && c == m) {
    ans[r][c] = u;
    return true;
  }
  int tr = r, tc = c + 1;
  if (tc > m) tr = r + 1, tc = 1;
  for (int i = 1; i <= n * m; ++i)
    if (!vis[i]) {
      if (tc != 1 && XL(u, i)) continue;
      if (tr > 1 && XL(a[tr - 1][tc], i)) continue;
      if (dfs(tr, tc, i)) {
        ans[r][c] = u;
        return true;
      }
    }
  a[r][c] = 0;
  vis[u] = false;
  return false;
}
int num[N][6], num2[N][6];
int main() {
  scanf("%d%d", &n, &m);
  if (n < 5 && m < 5) {
    bool flag = false;
    for (int i = 1; i <= n * m; ++i)
      if (dfs(1, 1, i)) {
        puts("YES");
        for (int ci = 1; ci <= n; ++ci)
          for (int cj = 1; cj <= m; ++cj)
            printf("%d%c", a[ci][cj], " \n"[cj == m]);
        flag = true;
        break;
      }
    if (!flag) puts("NO");
  } else if (m >= 5) {
    puts("YES");
    int ans1, tmp, tmp2;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        tmp = (m + 1) / 2, tmp2 = (i - 1) * m;
        if (i & 1) {
          if (j == 1)
            ans1 = (m & 1) ? (i * m - 1) : (i * m);
          else {
            if (j <= tmp + 1)
              ans1 = tmp2 + 2 * (j - 1) - 1;
            else
              ans1 = tmp2 + (j - tmp - 1) * 2;
          }
        } else {
          if (j <= tmp)
            ans1 = tmp2 + 2 * j - 1;
          else
            ans1 = tmp2 + (j - tmp) * 2;
        }
        printf("%d%c", ans1, " \n"[j == m]);
      }
  } else {
    puts("YES");
    int ans1, tmp, tmp2;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) num[i][j] = m * (i - 1) + j;
    for (int j = 1; j <= m; ++j)
      for (int i = 1; i <= n; ++i) {
        tmp = (n + 1) / 2, tmp2 = (j - 1) * n;
        if (j & 1) {
          if (i == 1)
            ans1 = num[(n & 1) ? (n - 1) : n][j];
          else {
            if (i <= tmp + 1)
              ans1 = num[2 * (i - 1) - 1][j];
            else
              ans1 = num[(i - tmp - 1) * 2][j];
          }
        } else {
          if (i <= tmp)
            ans1 = num[2 * i - 1][j];
          else
            ans1 = num[(i - tmp) * 2][j];
        }
        num2[i][j] = ans1;
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) printf("%d%c", num2[i][j], " \n"[j == m]);
  }
  return 0;
}
