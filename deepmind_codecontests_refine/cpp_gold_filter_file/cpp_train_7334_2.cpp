#include <bits/stdc++.h>
using namespace std;
int l[1020], r[1020];
int now[1020], wz[1020];
char s[1020][20];
char t[1020];
bool pd[2][1020];
int fa[1020];
int n, m, k;
int getfa(int v) {
  if (fa[v] != v) fa[v] = getfa(fa[v]);
  return fa[v];
}
void solve(int v) {
  for (int i = 1; i <= n; ++i) fa[i] = i;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i <= m; ++i) {
      if (pd[v][i]) continue;
      int x = getfa(wz[i]);
      int y = getfa(l[i]);
      int p = getfa(r[i]);
      if (x == p || x == y) {
        flag = true;
        pd[v][i] = true;
        fa[y] = p;
      }
    }
  }
}
bool cp(int v) {
  int len = strlen(s[v]);
  int len2 = strlen(t);
  if (len != len2) return false;
  for (int i = 1; i <= len; ++i)
    if (s[v][i - 1] != t[i - 1]) return false;
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &l[i], &r[i]);
  scanf("\n");
  for (int i = 1; i <= k; ++i) {
    scanf("%s", s[i]);
    scanf("%d", &now[i]);
    int x, y;
    scanf("%d", &x);
    for (int j = 1; j <= x; ++j) {
      scanf("%d", &y);
      wz[y] = now[i];
    }
    scanf("\n");
  }
  solve(0);
  for (int i = 1; i <= k; ++i) {
    int aug = 0, x, y;
    scanf("%s", t);
    for (int j = 1; j <= k; ++j)
      if (cp(j)) {
        aug = j;
        break;
      }
    scanf("%d", &x);
    if (getfa(x) != getfa(now[aug])) {
      printf("NO\n");
      exit(0);
    }
    aug = x;
    scanf("%d", &x);
    for (int j = 1; j <= x; ++j) {
      scanf("%d", &y);
      if (getfa(aug) != getfa(wz[y])) {
        printf("NO\n");
        exit(0);
      }
      wz[y] = aug;
    }
    scanf("\n");
  }
  solve(1);
  for (int i = 1; i <= m; ++i)
    if (pd[0][i] != pd[1][i]) {
      printf("NO\n");
      exit(0);
    }
  printf("YES\n");
  exit(0);
}
