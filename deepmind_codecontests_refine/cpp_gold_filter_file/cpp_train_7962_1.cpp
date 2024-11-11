#include <bits/stdc++.h>
using namespace std;
int n, m, bel[200], l;
bool E[205 * 2][205 * 2];
char a[5], b[5], ans[205], S[205];
bool search(int d, bool change) {
  if (d == n + 1) {
    printf("%s", ans + 1);
    return 1;
  }
  bool judge[2] = {0};
  for (int i = change == 1 ? 'a' : S[d]; i <= l + 'a' - 1; i++) {
    bool p = bel[i - 'a'], ok = 1;
    if (judge[p]) continue;
    for (int k = 1; k <= d - 1 && ok; k++) {
      bool p2 = bel[ans[k] - 'a'];
      if (E[p2 * n + k][(!p) * n + d] || E[p * n + d][(!p2) * n + k]) ok = 0;
    }
    if (!ok) {
      judge[p] = 1;
      change = 1;
      continue;
    }
    ans[d] = i;
    if (search(d + 1, change)) return 1;
    change = 1;
  }
  return 0;
}
int main() {
  int i, k, j, x, y;
  bool judge = 1;
  string str;
  cin >> str;
  l = str.length();
  for (i = 0; i < l; i++) {
    bel[i] = str[i] == 'V' ? 0 : 1;
    if (i != 0 && str[i - 1] != str[i]) judge = 0;
  }
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%s%d%s", &x, a, &y, b);
    int p1 = a[0] == 'V' ? 0 : 1;
    int p2 = b[0] == 'V' ? 0 : 1;
    if (judge) {
      if (str[0] == a[0] && str[0] != b[0]) {
        puts("-1");
        return 0;
      }
    }
    E[p1 * n + x][p2 * n + y] = E[(!p2) * n + y][(!p1) * n + x] = 1;
  }
  for (i = 1; i <= n * 2; i++) {
    for (k = 1; k <= n * 2; k++) {
      for (j = 1; j <= n * 2; j++) {
        if (E[k][i] && E[i][j]) E[k][j] = 1;
      }
    }
  }
  scanf("%s", ans + 1);
  strcpy(S + 1, ans + 1);
  for (i = 1; i <= n; i++) {
    if (E[i][i + n] && E[i + n][i]) {
      puts("-1");
      return 0;
    }
  }
  if (!search(1, 0)) puts("-1");
  return 0;
}
