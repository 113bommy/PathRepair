#include <bits/stdc++.h>
int n, p[4005], f[4005][4005], w[4005], tl;
void solve() {
  scanf("%d", &n);
  n <<= 1;
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  tl = 0;
  int pre = 1;
  w[++tl] = 1;
  for (int i = 2; i <= n; ++i) {
    if (p[i] < p[pre])
      w[tl]++;
    else {
      pre = i;
      w[++tl] = 1;
    }
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) f[i][j] = 0;
  f[0][0] = 1;
  for (int i = 1; i <= tl; ++i)
    for (int j = 0; j <= n; ++j)
      f[i][j] = f[i - 1][j] | (j - w[i] >= 0 ? f[i - 1][j - w[i]] : 0);
  if (f[tl][n / 2])
    puts("YES");
  else
    puts("NO");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
