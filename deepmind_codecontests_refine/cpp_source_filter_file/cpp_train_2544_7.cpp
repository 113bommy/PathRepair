#include <bits/stdc++.h>
using namespace std;
char s[1005];
int ans[1005][1005], a[1005][1005], b[1005][1005];
int n, m, error, i, j, P[5];
inline int check() {
  for (int i = 1; i <= n; i++) {
    int k = (i & 1) ? 1 : 3, flag = 1;
    for (int j = 1; j <= m && flag; j++)
      if (a[i][j] == 0 || a[i][j] == P[k + (j & 1)])
        ans[i][j] = P[k + (j & 1)];
      else
        flag = 0;
    if (flag) continue;
    flag = 1;
    for (int j = 1; j <= m && flag; j++)
      if (a[i][j] == 0 || a[i][j] == P[k + !(j & 1)])
        ans[i][j] = P[k + !(j & 1)];
      else
        flag = 0;
    if (!flag) return 0;
  }
  return 1;
}
inline void Swap(int opt) {
  if (opt == 1) {
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) b[i][j] = a[n - j + 1][i];
    memcpy(a, b, sizeof(b));
  } else {
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) b[i][j] = ans[j][i];
    memcpy(ans, b, sizeof(b));
  }
  swap(n, m);
}
inline void Print(int opt) {
  error = 1;
  if (opt & 1) Swap(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", ans[i][j]);
    puts("");
  }
}
inline void work(int opt) {
  int T = 24;
  P[1] = 1;
  P[2] = 2;
  P[3] = 3;
  P[4] = 4;
  while (T--) {
    if (check()) {
      Print(opt);
      break;
    }
    next_permutation(P + 1, P + 5);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (j = 1; j <= m; j++) a[i][j] = s[j] - '0';
  }
  work(0);
  if (error) return 0;
  Swap(1);
  work(1);
  if (error) return 0;
  puts("0");
  return 0;
}
