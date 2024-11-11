#include <bits/stdc++.h>
using namespace std;
int n, m, hx, hs, hm, ht, lx, ls, lm, lt;
char S[1005][1005];
bool vis[1005][1005];
int cs[2][4], W[8], sum;
bool dfs(int x) {
  if (x == 8) {
    for (int i = 1; i < 8; i += 2)
      if (W[i] - W[i - 1] < 2) return 0;
    int flg = 1, cnt = 0;
    for (int i = W[0]; i <= W[1]; i++) {
      if (S[i][W[2]] != '#')
        flg = 0;
      else
        cnt += !vis[i][W[2]];
      vis[i][W[2]] = 1;
      if (S[i][W[3]] != '#')
        flg = 0;
      else
        cnt += !vis[i][W[3]];
      vis[i][W[3]] = 1;
    }
    for (int i = W[2]; i <= W[3]; i++) {
      if (S[W[0]][i] != '#')
        flg = 0;
      else
        cnt += !vis[W[0]][i];
      vis[W[0]][i] = 1;
      if (S[W[1]][i] != '#')
        flg = 0;
      else
        cnt += !vis[W[1]][i];
      vis[W[1]][i] = 1;
    }
    for (int i = W[4]; i <= W[5]; i++) {
      if (S[i][W[6]] != '#')
        flg = 0;
      else
        cnt += !vis[i][W[6]];
      vis[i][W[6]] = 1;
      if (S[i][W[7]] != '#')
        flg = 0;
      else
        cnt += !vis[i][W[7]];
      vis[i][W[7]] = 1;
    }
    for (int i = W[6]; i <= W[7]; i++) {
      if (S[W[4]][i] != '#')
        flg = 0;
      else
        cnt += !vis[W[4]][i];
      vis[W[4]][i] = 1;
      if (S[W[5]][i] != '#')
        flg = 0;
      else
        cnt += !vis[W[5]][i];
      vis[W[5]][i] = 1;
    }
    for (int i = W[0]; i <= W[1]; i++) vis[i][W[2]] = vis[i][W[3]] = 0;
    for (int i = W[2]; i <= W[3]; i++) vis[W[0]][i] = vis[W[1]][i] = 0;
    for (int i = W[4]; i <= W[5]; i++) vis[i][W[6]] = vis[i][W[7]] = 0;
    for (int i = W[6]; i <= W[7]; i++) vis[W[4]][i] = vis[W[5]][i] = 0;
    if (!flg) return 0;
    if (cnt == sum) {
      puts("YES");
      printf("%d %d %d %d\n%d %d %d %d\n", W[0], W[2], W[1], W[3], W[4], W[6],
             W[5], W[7]);
      return 1;
    }
    return 0;
  }
  for (int i = 0; i < 4; i++) {
    if (x == 0 || x == 1 || x == 4 || x == 5)
      W[x] = cs[0][i];
    else
      W[x] = cs[1][i];
    if (dfs(x + 1)) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", S[i] + 1);
  hm = ht = n + 1;
  lm = lt = m + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (S[i][j] == '#') {
        sum++;
        if (S[i - 1][j] == '#' && S[i + 1][j] == '#') {
          if (j > lx)
            ls = lx, lx = j;
          else if (j != lx && j > ls)
            ls = j;
          if (j < lm)
            lt = lm, lm = j;
          else if (j != lm && j < lt)
            lt = j;
        }
        if (S[i][j - 1] == '#' || S[i][j + 1] == '#') {
          if (i > hx)
            hs = hx, hx = i;
          else if (i != hx && i > hs)
            hs = i;
          if (i < hm)
            ht = hm, hm = i;
          else if (i != hm && i < ht)
            ht = i;
        }
      }
  cs[0][0] = hm;
  cs[0][1] = ht;
  cs[0][2] = hs;
  cs[0][3] = hx;
  cs[1][0] = lm;
  cs[1][1] = lt;
  cs[1][2] = ls;
  cs[1][3] = lx;
  if (!dfs(0)) puts("NO");
}
