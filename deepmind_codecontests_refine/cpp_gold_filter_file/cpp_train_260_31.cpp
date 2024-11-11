#include <bits/stdc++.h>
using namespace std;
char s[25][200001];
int n, m;
long long f[2000001], g[2000001];
void FWT(long long* f) {
  for (int i = 2; i <= (1 << n); i <<= 1)
    for (int j = 0; j < (1 << n); j += i)
      for (int k = j; k < j + i / 2; k++) {
        long long fk = f[k];
        f[k] = f[k] + f[k + i / 2];
        f[k + i / 2] = fk - f[k + i / 2];
      }
}
void IFWT(long long* f) {
  FWT(f);
  for (int i = 0; i < (1 << n); i++) f[i] >>= n;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i]);
  for (int i = 0; i < m; i++) {
    int x = 0;
    for (int j = 1; j <= n; j++)
      if (s[j][i] == '1')
        x = (x << 1) + 1;
      else
        x <<= 1;
    f[x]++;
  }
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) cnt++;
    g[i] = min(cnt, n - cnt);
  }
  FWT(f);
  FWT(g);
  for (int i = 0; i < (1 << n); i++) f[i] *= g[i];
  IFWT(f);
  int ans = 1e9;
  for (int i = 0; i < (1 << n); i++) ans = min(ans, (int)f[i]);
  printf("%d\n", ans);
  return 0;
}
