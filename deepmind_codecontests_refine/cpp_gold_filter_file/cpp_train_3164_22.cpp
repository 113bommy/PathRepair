#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, m, k, ans[MAXN][MAXN];
bool L[MAXN][MAXN], U[MAXN][MAXN];
void Init() {
  scanf("%d%d%d", &n, &m, &k);
  int i, j;
  static char s[MAXN];
  for (i = 1; i < n; i++) {
    scanf("%s", s + 1);
    for (j = 1; j < m; j++) L[i][j + 1] = (s[j] == 'E');
    scanf("%s", s + 1);
    for (j = 1; j <= m; j++) U[i + 1][j] = (s[j] == 'E');
  }
  scanf("%s", s + 1);
  for (j = 1; j < m; j++) L[n][j + 1] = (s[j] == 'E');
}
bool Work1() {
  int i, j, cur, cnt;
  for (i = 1; i <= n; i++) {
    for (cur = j = 1; j <= m; j++) {
      if (!L[i][j]) cur = 3 - cur;
      ans[i][j] = cur;
    }
    for (cnt = 0, j = 1; j <= m; j++)
      cnt += ((ans[i][j] == ans[i - 1][j]) == U[i][j]);
    if (i > 1 && cnt <= m / 2) {
      for (j = 1; j <= m; j++) ans[i][j] = 3 - ans[i][j];
    }
  }
  return true;
}
bool Work2() {
  int i, j, cur, cnt;
  for (j = 1; j <= m; j++) {
    for (cur = i = 1; i <= n; i++) {
      if (!U[i][j]) cur = 3 - cur;
      ans[i][j] = cur;
    }
    for (cnt = 0, i = 1; i <= n; i++)
      cnt += ((ans[i][j] == ans[i][j - 1]) == L[i][j]);
    if (j > 1 && cnt <= n / 2) {
      for (i = 1; i <= n; i++) ans[i][j] = 3 - ans[i][j];
    }
  }
  return true;
}
void Output(bool ok) {
  if (!ok) {
    puts("NO");
    return;
  }
  puts("YES");
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) printf("%d ", ans[i][j]);
    putchar('\n');
  }
}
int main() {
  Init();
  if (k == 1) {
    int i, j, cnt = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        cnt += (i > 1 && U[i][j]);
        cnt += (j > 1 && L[i][j]);
      }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) ans[i][j] = 1;
    Output(cnt >= 3.0 * (n * m * 2 - n - m) / 4);
    return 0;
  }
  Output(m > n ? Work1() : Work2());
  return 0;
}
