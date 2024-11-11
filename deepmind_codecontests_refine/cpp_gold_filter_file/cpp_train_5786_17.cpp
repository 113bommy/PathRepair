#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MAXM = 200;
const int MAXS = 66000;
const int INF = 1E9;
int r[MAXN], b[MAXN];
bool c[MAXN];
int cr[MAXS], cb[MAXS];
int f[MAXS][MAXM];
int main() {
  int n, sr = 0, sb = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char t[2];
    scanf("%s%d%d", t, &r[i], &b[i]);
    c[i] = t[0] == 'R';
    sr += r[i], sb += b[i];
  }
  for (int s = 0; s < 1 << n; s++)
    for (int i = 1; i <= n; i++)
      if (s & 1 << i - 1) c[i] ? cr[s]++ : cb[s]++;
  int m = n * (n - 1) / 2;
  memset(f, 0XC0, sizeof f);
  f[0][0] = 0;
  for (int s = 1; s < 1 << n; s++)
    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        int t = s ^ 1 << j - 1;
        if (s & 1 << j - 1 && min(r[j], cr[t]) <= i)
          f[s][i] = max(f[s][i], f[t][i - min(r[j], cr[t])] + min(b[j], cb[t]));
      }
  int ans = INF;
  for (int i = 0; i <= m; i++)
    ans = min(ans, max(sr - i, sb - f[(1 << n) - 1][i]));
  printf("%d\n", ans + n);
  return 0;
}
