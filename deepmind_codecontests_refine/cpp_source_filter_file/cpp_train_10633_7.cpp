#include <bits/stdc++.h>
using namespace std;
int t, n, m, cnt, tot;
long long s1[260000], s2[260000];
long long a[508][508], b[508][508];
int to[1][2] = {-1, 1};
void solve1(int x, int y) {
  while (x != 0 && y != m + 1) {
    s1[++cnt] = a[x][y];
    x += to[0][0], y += to[0][1];
  }
  return;
}
void solve2(int x, int y) {
  while (x != 0 && y != m + 1) {
    s2[++tot] = b[x][y];
    x += to[0][0], y += to[0][1];
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  long long st1, en1, st2, en2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      if (i == 1 && j == 1)
        st1 = a[i][j];
      else if (i == n && j == m)
        en1 = a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &b[i][j]);
      if (i == 1 && j == 1)
        st2 = b[i][j];
      else if (i == n && j == m)
        en2 = b[i][j];
    }
  }
  bool q = true;
  if (n == 1) {
    for (int i = 1; i <= m; i++) {
      if (a[1][i] != b[1][i]) {
        q = false;
        break;
      }
    }
    if (!q)
      printf("NO\n");
    else
      printf("YES\n");
    return 0;
  }
  if (m == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i][1] != b[i][1]) {
        q = false;
        break;
      }
    }
    if (!q)
      printf("NO\n");
    else
      printf("YES\n");
    return 0;
  }
  q = true;
  for (int i = 1; i <= n; i++) {
    tot = cnt = 0;
    solve1(i, 1);
    solve2(i, 1);
    sort(s1 + 1, s1 + cnt + 1);
    sort(s2, s2 + tot + 1);
    for (int j = 1; j <= cnt; j++) {
      if (s1[j] != s2[j]) {
        q = false;
        break;
      }
    }
    if (!q) break;
  }
  if (!q) {
    printf("NO\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    tot = cnt = 0;
    solve1(i, 1);
    solve2(i, 1);
    sort(s1 + 1, s1 + cnt + 1);
    sort(s2, s2 + tot + 1);
    for (int j = 1; j <= cnt; j++) {
      if (s1[j] != s2[j]) {
        q = false;
        break;
      }
    }
    if (!q) break;
  }
  if (q) {
    if (st1 == st2 && en1 == en2) {
      printf("YES\n");
    } else
      printf("NO\n");
  } else
    printf("NO\n");
}
