#include <bits/stdc++.h>
using namespace std;
int n, m, nxt[10005], f[10000005];
char a[10005], b[10005];
inline int id(int x, int y) { return (x - 1) * m + y; }
int dp(int i, int j) {
  if (i > n) return j == m + 1;
  if (j == m + 1) return dp(i, nxt[m] + 1) + 1;
  int o = id(i, j);
  if (f[o] != -1) return f[o];
  int tmp = 0;
  if (a[i] != '?' && a[i] != b[j]) {
    if (j > 1) tmp = dp(i, nxt[j - 1] + 1);
  } else if (a[i] == '?') {
    if (j > 1)
      tmp = max(dp(i, nxt[j - 1] + 1), dp(i + 1, j + 1));
    else
      tmp = dp(i + 1, j + 1);
  } else if (a[i] == b[j]) {
    tmp = dp(i + 1, j + 1);
  }
  return f[o] = max(tmp, dp(i + 1, 1));
}
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (int i = 2, j = 0; i <= m; ++i) {
    while (j > 0 && b[i] != b[j + 1]) j = nxt[j];
    if (b[i] == b[j + 1]) j++;
    nxt[i] = j;
  }
  memset(f, -1, sizeof(f));
  cout << dp(1, 1);
}
